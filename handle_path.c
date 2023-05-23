#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* Handle_Path(char **args)
{
    char *env_path = getenv("PATH"); // Get the value of the PATH environment variable
    char *path = strtok(env_path, ":"); // Tokenize the path using ':' as the delimiter

    while (path != NULL)
    {
        char *command_path = malloc(strlen(path) + strlen(args[0]) + 2); // Allocate memory for the command path
        if (command_path == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        // Create the full path by concatenating the directory path and the command name
        strcpy(command_path, path);
        strcat(command_path, "/");
        strcat(command_path, args[0]);

        // Check if the command path exists and is executable
        if (access(command_path, X_OK) == 0)
        {
            // Check if the command includes arguments and a pipe symbol
            char *pipe_arg = strchr(args[0], '|');
            if (pipe_arg != NULL)
            {
                // Extract the command and arguments before the pipe symbol
                char *command = strtok(args[0], "|");
                char *arguments = strtok(NULL, "|");

                // Trim leading and trailing whitespace from the arguments
                char *trimmed_arguments = arguments;
                while (*trimmed_arguments == ' ')
                    trimmed_arguments++;
                size_t len = strlen(trimmed_arguments);
                while (len > 0 && trimmed_arguments[len - 1] == ' ')
                    trimmed_arguments[--len] = '\0';

                // Allocate memory for the modified command path with arguments and pipe symbol
                size_t modified_len = strlen(command_path) + strlen(command) + strlen(trimmed_arguments) + 4;
                char *modified_command_path = malloc(modified_len);
                if (modified_command_path == NULL)
                {
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }

                // Create the modified command path with arguments and pipe symbol
                snprintf(modified_command_path, modified_len, "%s %s | %s", command_path, command, trimmed_arguments);

                free(command_path); // Free the original command path
                args[0] = modified_command_path; // Update the argument with the modified command path
                return modified_command_path;
            }

            args[0] = command_path; // Update the argument with the full path
            return command_path; // Return the full path
        }

        free(command_path); // Free the allocated memory
        path = strtok(NULL, ":"); // Get the next path
    }

    return NULL; // Return NULL if the command is not found in any of the paths
}

