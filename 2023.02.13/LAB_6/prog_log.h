#ifndef PROG_LOG_HEADER
#define PROG_LOG_HEADER

#include <stdio.h>

/// @brief just file for writing logs
extern FILE *log_file;

/// @brief opens new log file
/// @param[in] path path to the file
/// @return 0 if all is ok and 1 if have problems
int set_log_file(const char *path);

/// @brief closes new log file
void close_log_file();

#endif //PROG_LOG_HEADER