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
  char number_buf[32]; // 足够存储任何整数的字符表示
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
      case 's':
      { // 字符串
        char *str = va_arg(ap, char *);
        int len = strlen(str);

        if (n == 0 || written + len < n)
        {
          strcpy(out, str);
          out += len;
        }
        written += len;
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
