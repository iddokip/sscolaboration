#include "shell.h"
/**
 * Handle_Path - Search for the command in /bin/ and append
 * @args: Array of arguments.
 * Return: Always 1 if sucessfull 0 if fails
 */
int Handle_Path(char **args)
{
	char *path;
	DIR *dirr = opendir("/bin");
	struct dirent *enterd;

	if (dirr != NULL)
	{
	while ((enterd = readdir(dirr)) != NULL)
	{
		if (comp_string(enterd->d_name, args[0]) == 0)
		{
			path = malloc(strlen("/bin/") + strlen(args[0]) + 1);
			if (path != NULL)
			{
				str_cpy(path, "/bin/");
				str_cat(path, args[0]);
				free(args[0]);
				args[0] = path;
				closedir(dirr);
				return (1);
			}
			else
			{
				perror("malloc");
				break;
			}
		}
	}
		closedir(dirr);
	}
	perror("unable to open /bin directory");
	args[0] = NULL;
	return (0);
	/* Free the path if it was allocated*/
	if (path != NULL)
		free(path);
}

