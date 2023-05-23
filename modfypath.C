#include "main.h"
char* ModifyCommand(const char* command_path, const char* command, const char* arguments)
{
    char* modified_command_path = malloc(strlen(command_path) + strlen(command) + strlen(arguments) + 4);
    if (modified_command_path == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(modified_command_path, command_path);
    strcat(modified_command_path, " ");
    strcat(modified_command_path, command);
    strcat(modified_command_path, " | ");
    strcat(modified_command_path, arguments);

    return modified_command_path;
}
