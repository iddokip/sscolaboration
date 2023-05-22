#include "shell.h"
/**
 * processInput - Process the input string.
 * @string: Input string.
 * @args: Array to store the processed arguments.
 */
void processInput(char *string, char **args)
{
	int i = 0, j;
	char *stoken;

	while (string[i])
	{
		if (string[i] == '\n')
			string[i] = 0;
		i++;
	}

	stoken = strtok(string, " ");
	j = 0;
	while (stoken != NULL)
	{
		args[j] = stoken;
		stoken = strtok(NULL, " ");
		j++;
	}

	args[j] = NULL;
	// Check if the command requires a full path
    if (args[0] != NULL && args[0][0] != '/')
    {
        // Call Handle_Path to search for the command in /bin/ and append the full path
        if (Handle_Path(args) == 0)
        {
            printf("%s: Command not found\n", args[0]);
            args[0] = NULL;
        }
    }

}
