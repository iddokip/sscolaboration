#include "shell.h"

char* Handle_Path(char **args)
{
    const char* dir = "/bin/";
    const char* firstArg = args[0];

    char* c_path = Append_Path(dir, firstArg);
    if (access(c_path, X_OK) == 0)
    {
        char *pipe_arg = strchr(args[0], '|');
        if (pipe_arg != NULL)
        {
            char *cmnd = strtok(args[0], "|");
            char *arg_str = strtok(NULL, "|");
            char *trimd_args = arg_str;
            while (*trimd_args == ' ')
                trimd_args++;
            size_t len = strlen(trimd_args);
            while (len > 0 && trimd_args[len - 1] == ' ')
                trimd_args[--len] = '\0';

            char* modfyd_path = malloc(strlen(c_path) + strlen(cmnd) + strlen(trimd_args) + 4);
            if (modfyd_path == NULL)
            {
                perror("malloc");
                exit(EXIT_FAILURE);
            }

            strcpy(modfyd_path, c_path);
            strcat(modfyd_path, " ");
            strcat(modfyd_path, cmnd);
            strcat(modfyd_path, " | ");
            strcat(modfyd_path, trimd_args);

            free(c_path);
            args[0] = modfyd_path;
            return modfyd_path;
        }

        args[0] = c_path;
        return c_path;
    }

    free(c_path);
    return NULL;
}

