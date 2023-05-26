#include "shell.h"
/**
 * main -  Entry point to shell
 * @argc: No of Args found in  input
 * @argv: all argts found in the input
 * @envp: env virables 
 * Return: zero
 */
int main(int ac, char *av[], char **env)

{

	if (ac == 1)
	{
		_noargv(av, env);
	}
	else if (ac == 2)
	{
		_yesargv(av, env);
	}
	else
	{
		write(STDIN_FILENO, "ARGUMENTS NOT PRESENT", 31);
		write(STDIN_FILENO, "\n", 1);
	}
	return (0);
}

