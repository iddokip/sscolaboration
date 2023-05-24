#include "shell.h"

char* Handle_Path(char** args)
{
    const char* dir = "/bin/";
    const char* firstArg = args[0];
    char* c_path = Append_Path(dir, firstArg);

    if (access(c_path, X_OK) == 0)
    {
        char* pipe_arg = strchr(args[0], '|');

        if (pipe_arg != NULL)
        {
            char* modified_path = Handle_Pipe(args[0]);
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
