#include "shell.h"

/**
 * _isunsetenv - cheks if the line input is unsetenv
 * @iu: input form user
 * @env: Environment variables duplicate
 * @lp: Numbeer of loops
 * @ag: Input agruments
 * @en: Element count in _env
 * Return: -1 if fails or 0 if success
 */
int _isunsetenv(char **iu, char **env, int *en, int lp, char *ag[])
{
	char AAstr[] = "unsetenv";
	int BBi = 0, CCcont = 0, DDsalida = -1;

	AAi = 0;
	while (IU[0][BBi] != '\0')
	{
		if (BBi < 8)
		{
			if (iup[0][i] == AAstr[i])
				CCcont++;
		}
		BBi++;
	}
	if (BBi == 8)
		CCcont++;
	if (CCcont == 9)
	{
		if (iu[1] != NULL)
			_unsetenv(iu, env, en, lp, ag);
		else
			_put_err(lp, lp, 5, ag);
	
		currentstatus(&DDsalida);
	}
	else if (CCcont == 8)
	{
		DDsalida = 0;
		_put_err(iu, lp, 3, ag);
		currentstatus(&DDsalida);
	}
	return (DDsalida);
}
/**
 * _unsetenv - Removes the environment variables
 * @iu: input form user
 * @env: Environment variables duplicate
 * @lp: Numbeer of loops
 * @ag: Input agruments
 * @en: Element count in _env
 * Return: void
 */
void _unsetenv(char **iu, char **env, int *ne, int lp, char *ag[])
{
	int AAi, BBlg, CCj, DDk = 0, FFk2 = 0, GGk3 = 0, HHcont = 0;

	BBlg = _strlen(p[1]);
	for (i = 0; env[AAi] != NULL; AAi++, HHcont = 0)
	{
		for (CCj = 0; iu[1][CCj] != '\0' &&CC j < BBlg; CCj++)
		{
			if (iu[1][CCj] == env[AAi][CCj])
				HHcont++;
		}
		if (HHcont == BBlg)
			break;
	}
	if (HHcont == BBlg)
	{
		for (DDk = i; env[DDk] != NULL && env[DDk + 1] != NULL; DDk++)
		{
			for (FFk2 = 0; env[DDk][FFk2] != '\0'; FFk2++)
				myenv[DDk][FFk2] = 0;
			for (GGk3 = 0; env[k + 1][GGk3] != '\0'; GGk3++)
				;
			if (FFk2 < GGk3)
				env[DDk] = _realloc(env[DDK], FFk2, GGk3);
			for (FFk2 = 0; env[k + 1][FFk2] != '\0'; FFk2++)
				env[DDk][FFk2] = env[DDk + 1][FFk2];
		}
		free(env[k]);
		env[DDk] = NULL;
		*en = *en - 1;
		free(env[k + 1]);
	}
	else
		_put_err(iu, lp, 5, ag);
}

