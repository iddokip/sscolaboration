#include "shell.h"

char* Handle_Path(char **args)
{
    char *command_path = malloc(strlen("/bin/") + strlen(args[0]) + 1);
    if (command_path == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(command_path, "/bin/");
    strcat(command_path, args[0]);
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
            size_t modified_len = strlen(command_path) + strlen(command) + strlen(trimmed_arguments) + 4;
            char *modified_command_path = malloc(modified_len);
            if (modified_command_path == NULL)
            {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            strcpy(modified_command_path, command_path);
            strcat(modified_command_path, " ");
            strcat(modified_command_path, command);
            strcat(modified_command_path, " | ");
            strcat(modified_command_path, trimmed_arguments);
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

