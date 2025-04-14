#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 辅助函数：将整数转换为字符串
static char *itoa(int num, char *str, int base)
{
  char *ptr = str;
  char *ptr1 = str;
  char tmp_char;
  int tmp_value;
  int neg = 0;

  // 处理负数
  if (num < 0 && base == 10)
  {
    neg = 1;
    num = -num;
  }

  // 先转换成逆序字符
  do
  {
    tmp_value = num % base;
    *ptr++ = (tmp_value < 10) ? (tmp_value + '0') : (tmp_value - 10 + 'a');
    num /= base;
  } while (num);

  // 添加负号（如果需要）
  if (neg)
  {
    *ptr++ = '-';
  }

  *ptr-- = '\0';

  // 反转字符串
  while (ptr1 < ptr)
  {
    tmp_char = *ptr;
    *ptr = *ptr1;
    *ptr1 = tmp_char;
    ptr--;
    ptr1++;
  }

  return str;
}

// 辅助函数：将无符号整数转换为字符串
static char *utoa(unsigned int num, char *str, int base)
{
  char *ptr = str;
  char *ptr1 = str;
  char tmp_char;
  unsigned int tmp_value;

  // 先转换成逆序字符
  do
  {
    tmp_value = num % base;
    *ptr++ = (tmp_value < 10) ? (tmp_value + '0') : (tmp_value - 10 + 'a');
    num /= base;
  } while (num);

  *ptr-- = '\0';

  // 反转字符串
  while (ptr1 < ptr)
  {
    tmp_char = *ptr;
    *ptr = *ptr1;
    *ptr1 = tmp_char;
    ptr--;
    ptr1++;
  }

  return str;
}

// 辅助函数：将长整型无符号数转换为字符串（用于指针）
static char *ultoa(unsigned long num, char *str, int base)
{
  char *ptr = str;
  char *ptr1 = str;
  char tmp_char;
  unsigned long tmp_value;

  // 先转换成逆序字符
  do
  {
    tmp_value = num % base;
    *ptr++ = (tmp_value < 10) ? (tmp_value + '0') : (tmp_value - 10 + 'a');
    num /= base;
  } while (num);

  *ptr-- = '\0';

  // 反转字符串
  while (ptr1 < ptr)
  {
    tmp_char = *ptr;
    *ptr = *ptr1;
    *ptr1 = tmp_char;
    ptr--;
    ptr1++;
  }

  return str;
}

int printf(const char *fmt, ...)
{
  char buffer[4096]; // 假设输出不会超过4096字符
  va_list args;
  va_start(args, fmt);
  int len = vsprintf(buffer, fmt, args);
  va_end(args);

  for (int i = 0; i < len; i++)
  {
    putch(buffer[i]);
  }

  return len;
}

int vsprintf(char *out, const char *fmt, va_list ap)
{
  return vsnprintf(out, -1, fmt, ap); // 使用-1表示无限大小限制
}

int sprintf(char *out, const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  int ret = vsprintf(out, fmt, args);
  va_end(args);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  int ret = vsnprintf(out, n, fmt, args);
  va_end(args);
  return ret;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap)
{
  char *original_out = out;
  char c;
  char number_buf[64]; // 加大缓冲区，足够存储任何数字的字符表示
  size_t written = 0;

  while ((c = *fmt++) != '\0')
  {
    if (c != '%')
    {
      // 普通字符
      if (n == 0 || written + 1 < n)
      {
        *out++ = c;
      }
      written++;
    }
    else
    {
      // 格式说明符
      c = *fmt++;
      switch (c)
      {
      case 'd':
      case 'i':
      { // 整数
        int num = va_arg(ap, int);
        itoa(num, number_buf, 10);
        int len = strlen(number_buf);

        if (n == 0 || written + len < n)
        {
          strcpy(out, number_buf);
          out += len;
        }
        written += len;
        break;
      }
      case 'u':
      { // 无符号整数
        unsigned int num = va_arg(ap, unsigned int);
        utoa(num, number_buf, 10);
        int len = strlen(number_buf);

        if (n == 0 || written + len < n)
        {
          strcpy(out, number_buf);
          out += len;
        }
        written += len;
        break;
      }
      case 'x':
      { // 十六进制(小写)
        unsigned int num = va_arg(ap, unsigned int);
        utoa(num, number_buf, 16);
        int len = strlen(number_buf);

        if (n == 0 || written + len < n)
        {
          strcpy(out, number_buf);
          out += len;
        }
        written += len;
        break;
      }
      case 'X':
      { // 十六进制(大写)
        unsigned int num = va_arg(ap, unsigned int);
        utoa(num, number_buf, 16);
        // 转换为大写
        for (char *p = number_buf; *p; p++)
        {
          if (*p >= 'a' && *p <= 'f')
          {
            *p = *p - 'a' + 'A';
          }
        }
        int len = strlen(number_buf);

        if (n == 0 || written + len < n)
        {
          strcpy(out, number_buf);
          out += len;
        }
        written += len;
        break;
      }
      case 'p':
      { // 指针
        void *ptr = va_arg(ap, void *);
        *out++ = '0';
        *out++ = 'x';
        written += 2;

        ultoa((unsigned long)ptr, number_buf, 16);
        int len = strlen(number_buf);

        if (n == 0 || written + len < n)
        {
          strcpy(out, number_buf);
          out += len;
        }
        written += len;
        break;
      }
      case 'c':
      {                                  // 字符
        char ch = (char)va_arg(ap, int); // 注意：char会被提升为int

        if (n == 0 || written + 1 < n)
        {
          *out++ = ch;
        }
        written++;
        break;
      }
      case 'o':
      { // 八进制
        unsigned int num = va_arg(ap, unsigned int);
        utoa(num, number_buf, 8);
        int len = strlen(number_buf);

        if (n == 0 || written + len < n)
        {
          strcpy(out, number_buf);
          out += len;
        }
        written += len;
        break;
      }
      case 's':
      { // 字符串
        char *str = va_arg(ap, char *);
        if (str == NULL)
          str = "(null)";
        int len = strlen(str);

        if (n == 0 || written + len < n)
        {
          strcpy(out, str);
          out += len;
        }
        written += len;
        break;
      }
      case '%':
      { // 百分号
        if (n == 0 || written + 1 < n)
        {
          *out++ = '%';
        }
        written++;
        break;
      }
      default:
      { // 未知格式，原样输出%
        if (n == 0 || written + 1 < n)
        {
          *out++ = '%';
        }
        written++;

        if (n == 0 || written + 1 < n)
        {
          *out++ = c;
        }
        written++;
        break;
      }
      }
    }
  }

  // 添加终止符（如果有空间）
  if (n == 0 || written < n)
  {
    *out = '\0';
  }
  else if (n > 0)
  {
    *(original_out + n - 1) = '\0';
  }

  return written;
}

#endif
