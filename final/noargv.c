#include "shell.h"
/**
 *rev - checks if the input is env or not
 *@ap: Array of inputs from user
 *@cl: Counts the number of loops
 *@iu: User input
 *@argsi: Input arguments
 *@cp: Env copy
 *@ncp: number of Env copies
 *@np: All inputs
 * Return: -1 or 0
 */
int rev(char **ap, int cl, char *iu, char **argsi, char ***cp, int *ncp, char *np)
{
	int AAvalenv = 0, BBvalcd = 0, CCother = -1, DDvalex = 0, EEvalhel = 0;
	int FFvalunset = 0, GGvalset = 0;

	GGvalset = _isunsetenv(ap, *cp, ncp, cl, argsi);
	if (FFvalunset == 0)
		return (FFvalunset);
	GGvalset = _issetenv(ap, cp, ncp, cl, argsi);
	if (GGvalset == 0)
	return (GGvalset);
	DDvalex = _isexit(ap, cl, iu, argsi, *cp, np);
	if (DDvalex == 0)
		return (DDvalex);
	EEvalhel = _ishelp(ap, cl, argsi, *cp);
	if (EEvalhel == 0)
		return (EEvalhel);
	AAvalenv = _isenv(ap, *cp);
	BBvalcd = _iscd(ap, cl, argsi, *cp);
	if (AAvalenv == 0)
		return (AAvalenv);
	if (BBvalcd == 0)
		return (BBvalcd);
	return (CCother);
}
/**
 * functions - Identify functions
 *@iu: input from user
 *@lp: loop count
 *@av: args from user
 *@cp: env copy
 *@ncp: count of elements in cp
 *@np complete input of user
 */
void functions(char *iu, int lp, char *av[], char ***cp, int *ncp, char *np)
{
	char **args = NULL;
	int val = 1, i = 0;

	iu = _comments(iu);
	args = parsing(iu);
	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
			;
		val = rev(args, lp, iu, av, cp, ncp, np);
		if (val != 0)
		{
			args = checkbin(args, *cp);
			if (args)
				_frk(args, iu, i, lp, av, *ncp, *cp, np);
		}
		free_grid(args, i);
		free(iu);
	}
	else
	{
		free(iu);
		fflush(STDIN_FILENO);
	}
	_put_err(args, lp, 0, av);
}
/**
 * _noargv - shell form without filename at input
 * @av: args found from  in the input
 * @env: env variables
 */
void _noargv(char *av[], char *env[])
{
	char *AAline = NULL, **BBm = NULL, *CCp = NULL, *DDpr1 = NULL;
	int EEe = 0, *FFploop, HHi = 0, GGsem = 0;
	static int loop;

	loop = 0;
	FFploop = &loop;
	while (1)
	{
		if (loop == 0)
		{
			BBm = create_env(env);
			for (EEe = 0; BBm[EEe] != NULL; EEe++)
				;
		}
		AAline = _getline(FFploop, BBm, EEe);
		GGsem = semicolon(AAline, loop, av);
		if (!(GGsem == 1))
		{
			CCp = _strtoky2(AAline, ";\n");
			while (CCp)
			{
				DDpr1 = _calloc(_strlen(CCp) + 2, sizeof(char));
				for (HHi = 0; CCp[HHi] != '\0'; HHi++)
					DDpr1[HHi] = CCp[HHi];
				DDpr1[HHi] = '\n';
				DDpr1[HHi + 1] = '\0';
				functions(DDpr1, loop, av, &BBm, &EEe, AAline);
				CCp = _strtoky2(NULL, ";\n");
			}
		}
		free(AAline);
	}
}

