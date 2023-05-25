#include "shell.h"

/**
 * _errorcd - writes the  error message
 * @pp: pointers to array
 * Return: zero.
 */
void _errorcd(char **pp)
{
	int aa = 2;

	write(STDERR_FILENO, pp[0], 2);
	write(STDERR_FILENO, ": can't cd to ", 14);
	write(STDERR_FILENO, pp[1], _strlen(pp[1]));
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&aa);
}
/**
 * _errorexit -writes the error message
 * @pp: input pointer to array
 * Return: nothing.
 */
void _errorexit(char **pp)
{
	int aa = 2;

	write(STDERR_FILENO, pp[0], 4);
	write(STDERR_FILENO, ": Illegal number: ", 18);
	write(STDERR_FILENO, pp[1], _strlen(pp[1]));
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&aa);
}
/**
 * _errorhelp - writes the error
 * @pp: input pointe to array
 * Return: nothing.
 */
void _errorhelp(char **pp)
{
	int aa = 2;

	write(STDERR_FILENO, pp[0], 4);
	write(STDERR_FILENO, ": no help topics match '", 24);
	write(STDERR_FILENO, pp[1], _strlen(pp[1]));
	write(STDERR_FILENO, "'. Try 'help help' or 'man -k '", 31);
	write(STDERR_FILENO, pp[1], _strlen(pp[1]));
	write(STDERR_FILENO, "' or info '", 11);
	write(STDERR_FILENO, pp[1], _strlen(pp[1]));
	write(STDERR_FILENO, "'\n", 2);
	currentstatus(&aa);
}
/**
 * _errorgarbage - writes the error
 * @pp: input pointer to array
 * Return: nothing.
 */
void _errorgarbage(char **pp)
{
	int aa = 2;

	write(STDERR_FILENO, pp[0], _strlen(pp[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	currentstatus(&aa);
}
/**
 * _errorenv - writes the error
 * @p: input pointer to array
 * Return: nothing.
 */
void _errorenv(char **pp)
{
	int aa = 2;

	write(STDERR_FILENO, pp[0], _strlen(pp[0]));
	write(STDERR_FILENO, ": unable to add/rm variable ", 28);
	write(STDERR_FILENO, "\n", 1);
	currentstatus(&aa);
}
