#include "shell.h"
char* BuildCommandPath(const char* directory, const char* command)
{
    size_t dir_len = strlen(directory);
    size_t command_len = strlen(command);
    size_t path_len = dir_len + command_len + 2; // +2 for '/' and null terminator

    char* command_path = malloc(path_len);
    if (command_path == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(command_path, directory);
    strcat(command_path, "/");
    strcat(command_path, command);

    return command_path;
}
