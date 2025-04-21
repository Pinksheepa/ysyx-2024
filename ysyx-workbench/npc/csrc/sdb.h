#ifndef __SDB_H__
#define __SDB_H__

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <cstdint>

// 前置声明
class Simulator;

// 命令类型定义
typedef struct
{
    const char *name;                   // 命令名称
    const char *description;            // 命令描述
    std::function<int(char *)> handler; // 命令处理函数
} cmd_t;

// SDB类定义
class SDB
{
private:
    Simulator *sim;               // 指向模拟器的指针
    bool is_batch_mode;           // 批处理模式标志
    std::vector<cmd_t> cmd_table; // 命令表

    // 内部辅助方法
    char *rl_gets();
    void register_cmd(const char *name, const char *desc, std::function<int(char *)> handler);

    // 命令处理函数
    int cmd_help(char *args);
    int cmd_quit(char *args);
    int cmd_si(char *args);
    int cmd_info(char *args);
    int cmd_x(char *args);
    int cmd_c(char *args);

public:
    // 构造函数
    SDB(Simulator *simulator, bool batch_mode = false);

    // 公共方法
    void init_sdb();
    void sdb_mainloop();
    void set_batch_mode(bool mode);
};

#endif // __SDB_H__