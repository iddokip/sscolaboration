#include "shell.h"
char* Handle_Path(char **args)
{
    const char* directory = "/bin/";
    const char* command = args[0];

    char* command_path = BuildCommandPath(directory, command);
    if (access(command_path, X_OK) == 0)
    {
        char *pipe_arg = strchr(args[0], '|');
        if (pipe_arg != NULL)
        {
            char *command = strtok(args[0], "|");
            char *arguments = strtok(NULL, "|");
            char *trimmed_arguments = arguments;
            while (*trimmed_arguments == ' ')
                trimmed_arguments++;
            size_t len = strlen(trimmed_arguments);
            while (len > 0 && trimmed_arguments[len - 1] == ' ')
                trimmed_arguments[--len] = '\0';

            char* modified_command_path = ModifyCommand(command_path, command, trimmed_arguments);
            free(command_path);
            args[0] = modified_command_path;
            return modified_command_path;
        }
        args[0] = command_path;
        return command_path;
    }
    free(command_path);
    return NULL;
}
