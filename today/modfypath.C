#include "shell.h"
char* modfypath(const char* c_path, const char* cmnd, const char* args)
{
    char*  modfyd_path= malloc(strlen(c_path) + strlen(cmnd) + strlen(args) + 4);
    if (modfyd_path == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(modfyd_path, c_path);
    strcat(modfyd_path, " ");
    strcat(modfyd_path, cmnd);
    strcat(modfyd_path, " | ");
    strcat(modfyd_path, args);

    return modfyd_path;
}
