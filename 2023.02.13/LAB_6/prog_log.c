#include "prog_log.h"

FILE *log_file = NULL;

int set_log_file(const char *path)
{
    log_file = fopen(path, "w");
    return log_file == NULL;
}

void close_log_file()
{
    if(log_file == NULL)
        return;

    fclose(log_file);
}