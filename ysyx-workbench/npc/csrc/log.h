#ifndef __LOG_H__
#define __LOG_H__

// ANSI color codes
#define ANSI_RED     "\033[1;31m"
#define ANSI_YELLOW  "\033[1;33m"
#define ANSI_RESET   "\033[0m"

#define Log_Error(format, ...) printf(ANSI_RED "[ERROR] " format ANSI_RESET "\n", ##__VA_ARGS__)
#define Log_Warning(format, ...) printf(ANSI_YELLOW "[WARNING] " format ANSI_RESET "\n", ##__VA_ARGS__)

#endif
