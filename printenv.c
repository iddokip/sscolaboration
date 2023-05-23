#include "shell.h"
/**
 * print_env -used t  Print the curnt envt.
 */
void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, getLength(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
