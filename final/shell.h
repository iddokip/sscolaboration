#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int _atoi(char *ss);
char *_verifypath(char *pth, char *pd);
char *_getpath(char **mm);
char **checkbin(char **bb, char **mm);
ssize_t read_help(char **mm);
ssize_t read_cdhelp(char **mm);
ssize_t read_exithelp(char **mm);
ssize_t read_helphelp(char **mm);
void free_grid(char **ggrid, int hheight);
int _iscd(char **pp, int lloop, char *vv[], char **env);
void _cleancd(char *cc);
void _fullcd(char *ff, char *aaux);
void _cd(char **aa, int lloop, char *vv[], char **env);
void _yesargv(char *av[], char *env[]);
void print_number(int nn);
void _signal(int sg);
int _isunsetenv(char **iu, char **env, int *en, int lp, char *ag[]);
void _unsetenv(char **iu, char **env, int *ne, int lp, char *ag[]);
void *_calloc(unsigned int memb, unsigned int sz);
int semicolon(char *ln, int lp, char **arg);
char *_comments(char *ln);
int _isenv(char **ptr, char **env);
char **create_env(char *env[]);
void _env(char **env);
char *_gethome(char **mm);
void _type(char **pp, int LL, char *ll, int ii, char **vv, char **mm, int ee, char *ff);
int _isexit(char **pp, int LL, char *ll, char **vv, char **mm, char *ff);
int rev(char **ap, int cl, char *iu, char **argsi, char ***cp, int *ncp, char *np);
void functions(char *iu, int lp, char *av[], char ***cp, int *ncp, char *np);
void _noargv(char *av[], char *env[]);
void *_realloc(char *pptr, unsigned int oold_size, unsigned int nnew_size);
void *_realloc2(char *aa, char *pp, unsigned int oold, unsigned int nnew_size);
char *str_concat(char *ar1, char *ar2);
int _strlen(char *str);
void _put_err(char **ptr, int lp, int sg, char *vv[]);
void _builtinerr(char **ptr);
void _builtinerr2(char **ptr);
void _updatepwd(char *buff, char **env);
void _updateoldpwd(char *buff, char **env);
int currentstatus(int *stat);
void _frk(char **pp, char *ll, int aa, int LL, char **vv, int ee, char **mm, char *ff);
void salida3(char **mm, int ee);
void salida2(char **mm, int ee, char *lline);
void salida1(char **mm, int ee);
char  *_getline(int *aa, char **mm, int ee);
char  *_getlineav(int *aa, char **mm, int ee, char **av);
int _ishelp(char **pp, int lloop, char *vv[], char **mm);
void _help_builtin(char **pp, int lp, char *vv[], char **mm);
void _help(char **pp, int lp, char *vv[], char **mm);
int Counter(char *LL, char *lim);
char **parsing(char *ln);
int _issetenv(char **iu, char ***env, int *en, int lp, char *ag[]);
void _setenv(char **iu, char ***env, int *en, int lp, char *ag[]);
void _setenvcreat(char ***env, int *en, char *AAentirenv);
int _sch(char *ss, char cc);
char *_strtoky(char *ss, char *dd);
char *_strtoky2(char *ss, char *dd);
void _errorcd(char **ptr);
void _errorexit(char **ptr);
void _errorhelp(char **ptr);
void _errorgarbage(char **ptr);
void _errorenv(char **ptr);




#endif
