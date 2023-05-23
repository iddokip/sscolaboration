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
            char *pipe_args = strtok(NULL, "|");
            char *trimd_args = pipe_args;
            while (*trimd_args == ' ')
                trimd_args++;
            size_t len = strlen(trimd_args);
            while (len > 0 && trimd_args[len - 1] == ' ')
                trimd_args[--len] = '\0';
	    char* modified_path = modfypath(c_path, cmnd, trimd_args);
	    free(c_path);
	    args[0] = modified_path;
	    return modified_path;
	}
        args[0] = c_path;
        return c_path;
    }
    free(c_path);
    return NULL;
}

