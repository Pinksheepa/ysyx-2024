#include "sdb.h"
#include "log.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

// 如有readline库，可以添加此头文件：
#include <readline/readline.h>
#include <readline/history.h>

// 前置声明，在sim_main.cpp中定义
class Simulator;
extern "C" int get_gpr(int index); // DPI-C函数，从RegisterFile.v导出

// 构造函数
SDB::SDB(Simulator *simulator, bool batch_mode) : sim(simulator), is_batch_mode(batch_mode)
{
    // 初始化命令表为空
}

// 初始化调试器
void SDB::init_sdb()
{
    // 注册所有命令
    register_cmd("help", "显示命令帮助信息", [this](char *args)
                 { return cmd_help(args); });
    register_cmd("q", "退出NPC", [this](char *args)
                 { return cmd_quit(args); });
    register_cmd("si", "单步执行N条指令", [this](char *args)
                 { return cmd_si(args); });
    register_cmd("info", "打印程序状态，info r表示打印寄存器", [this](char *args)
                 { return cmd_info(args); });
    register_cmd("x", "扫描内存，格式：x N ADDR - 显示N个32位字内存，从ADDR开始", [this](char *args)
                 { return cmd_x(args); });
    register_cmd("c", "继续执行程序，直到结束或中断", [this](char *args)
                 { return cmd_c(args); });
}

// 注册命令
void SDB::register_cmd(const char *name, const char *desc, std::function<int(char *)> handler)
{
    cmd_table.push_back({name, desc, handler});
}

// 获取用户输入
char *SDB::rl_gets()
{
    // 使用 readline 库实现命令行输入
    static char *line_read = nullptr;

    // 释放之前的内存
    if (line_read)
    {
        free(line_read);
        line_read = nullptr;
    }

    // 获取新的输入
    line_read = readline("(npc) ");

    // 处理EOF（Ctrl+D）
    if (line_read == nullptr)
    {
        return nullptr;
    }

    // 去除字符串两端的空白字符
    char *start = line_read;
    while (*start && isspace(*start))
        start++;

    char *end = start + strlen(start) - 1;
    while (end > start && isspace(*end))
        *end-- = '\0';

    if (*start)
    {
        // 只有非空命令才加入历史记录
        add_history(start);

        // 如果输入在开头有空格，移动字符串
        if (start != line_read)
            memmove(line_read, start, strlen(start) + 1);
    }

    return line_read;
}

// 主循环
void SDB::sdb_mainloop()
{
    if (is_batch_mode)
    {
        // 在批处理模式下，直接执行 c 命令
        cmd_c(nullptr);
        return;
    }

    printf("欢迎使用 NPC 调试器。输入 'help' 获取命令帮助。\n");
    for (char *str; (str = rl_gets()) != NULL;)
    {
        // 跳过空命令
        if (str[0] == '\0')
        {
            continue;
        }

        // 解析命令
        char *cmd = strtok(str, " \t\r\n"); // 使用所有空白字符作为分隔符
        if (cmd == nullptr)
            continue; // 再次检查，以防全是空白字符

        // 获取参数字符串
        char *args = strtok(nullptr, ""); // 获取剩余的所有字符串作为参数

        // 去除参数字符串开头的空白字符
        if (args)
        {
            while (*args && isspace(*args))
                args++;
            if (*args == '\0')
                args = nullptr; // 如果参数全是空白字符，设为nullptr
        }

        // 查找并执行命令
        bool found = false;
        for (const auto &entry : cmd_table)
        {
            if (strcmp(cmd, entry.name) == 0)
            {
                if (entry.handler(args) < 0)
                {
                    return;
                }
                found = true;
                break;
            }
        }

        if (!found)
        {
            printf("未知命令 '%s'\n", cmd);
        }
    }

    // 处理 EOF（Ctrl+D）
    printf("\n再见！\n");
}

void SDB::set_batch_mode(bool mode)
{
    is_batch_mode = mode;
}

// 命令处理函数 - help
int SDB::cmd_help(char *args)
{
    if (args == nullptr)
    {
        // 显示所有命令
        for (const auto &entry : cmd_table)
        {
            printf("%s - %s\n", entry.name, entry.description);
        }
    }
    else
    {
        // 显示特定命令的帮助
        const char *arg = strtok(args, " ");
        for (const auto &entry : cmd_table)
        {
            if (strcmp(arg, entry.name) == 0)
            {
                printf("%s - %s\n", entry.name, entry.description);
                return 0;
            }
        }
        printf("未知命令 '%s'\n", arg);
    }
    return 0;
}

// 命令处理函数 - quit
int SDB::cmd_quit(char *args)
{
    return -1; // 返回-1表示退出
}

// 命令处理函数 - si
int SDB::cmd_si(char *args)
{
    int n = 1; // 默认执行1条指令

    if (args != nullptr)
    {
        char *arg = strtok(args, " ");
        if (arg != nullptr)
        {
            n = atoi(arg);
            if (n <= 0)
            {
                printf("无效的步数 '%s', 使用默认值1\n", arg);
                n = 1;
            }
        }
    }

    // 调用模拟器执行n条指令
    extern void execute_n_cycles(Simulator * sim, int n);
    execute_n_cycles(sim, n);

    return 0;
}

// 命令处理函数 - info
int SDB::cmd_info(char *args)
{
    if (args == nullptr)
    {
        printf("info r: 打印寄存器\n");
        return 0;
    }

    char *arg = strtok(args, " ");
    if (strcmp(arg, "r") == 0)
    {
        // 打印寄存器
        printf("通用寄存器:\n");

        // ABI寄存器名称
        const char *reg_names[] = {
            "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
            "s0/fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
            "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
            "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

        // 使用DPI-C导出的get_gpr函数获取寄存器值
        for (int i = 0; i < 32; i++)
        {
            int value = get_gpr(i);
            printf("x%-2d %-7s = 0x%08x    %d\n", i, reg_names[i], value, value);
        }

        // 打印PC寄存器（需要在Simulator中实现获取PC的方法）
        extern uint32_t get_pc(Simulator * sim);
        printf("pc = 0x%08x\n", get_pc(sim));
    }
    else
    {
        printf("未知的info参数: %s\n", arg);
    }

    return 0;
}

// 命令处理函数 - x
int SDB::cmd_x(char *args)
{
    if (args == nullptr)
    {
        printf("用法: x N ADDR - 从地址ADDR开始扫描N个32位字内存\n");
        return 0;
    }

    // 解析参数：N和ADDR
    char *arg1 = strtok(args, " ");
    if (arg1 == nullptr)
    {
        printf("错误: 缺少内存单元数量参数\n");
        return 0;
    }

    int n = atoi(arg1);
    if (n <= 0)
    {
        printf("错误: 无效的数量 '%s'\n", arg1);
        return 0;
    }

    char *arg2 = strtok(nullptr, " ");
    if (arg2 == nullptr)
    {
        printf("错误: 缺少地址参数\n");
        return 0;
    }

    // 尝试将地址参数解析为数字
    uint32_t addr;
    if (strncmp(arg2, "0x", 2) == 0)
    {
        sscanf(arg2 + 2, "%x", &addr);
    }
    else
    {
        addr = atoi(arg2);
    }

    // 调用内存读取函数扫描内存
    extern uint32_t read_memory(Simulator * sim, uint32_t addr);

    printf("内存内容 (起始地址 = 0x%08x):\n", addr);
    for (int i = 0; i < n; i++)
    {
        if (i % 4 == 0)
        {
            printf("0x%08x: ", addr + i * 4);
        }

        uint32_t value = read_memory(sim, addr + i * 4);
        printf("0x%08x ", value);

        if ((i + 1) % 4 == 0 || i == n - 1)
        {
            printf("\n");
        }
    }

    return 0;
}

// 命令处理函数 - c (continue)
int SDB::cmd_c(char *args)
{
    // 使用 run_until_end 函数执行，直到程序结束或被中断
    extern void run_until_end(Simulator * sim, int maxCycles);
    run_until_end(sim, 10000000); // 设置一个较大的周期数

    return 0;
}