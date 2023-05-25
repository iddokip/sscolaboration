#include "shell.h"
/**
 * _yesargv - shell form without filename at input
 * @av: args found from in the input
 * @env: env variables in shell
 */
void _yesargv(char *av[], char *env[])
{
	char *AAline = NULL, **BBm = NULL, *CCp = NULL, *DDpr1 = NULL;
	int EEe = 0, *FFploop, HHi, GGsem;
	static int loop;

	loop = 0;
	FFploop = &loop;
	while (1)
	{
		if (loop == 0)
		{
			BBm = create_env(env);
			for (EEe = 0; BBm[e] != NULL; EEe++)
				;
		}
		AAline = _getlineav(FFploop, BBm, EEe, av);
		GGsem = semicolon(AAline, loop, av);
		if (!(GGsem == 1))
		{
			CCp = _strtoky2(AAline, ";\n");
			while (CCp)
			{
				DDpr1 = _calloc(_strlen(CCp) + 2, sizeof(char));
				for (HHi = 0; CCp[HHi] != '\0'; i++)
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

