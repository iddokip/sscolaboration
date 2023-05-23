#include "shell.h"

char *Append_Path(const char *dir, const char *cmnd)
{
	size_t dir_len = strlen(dir);
	size_t cmnd_len = strlen(cmnd);
	size_t path_len = dir_len + cmnd_len + 2;
	char *cmnd_path = malloc(path_len);

	if (cmnd_path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	str_cpy(cmnd_path, dir);
	str_cat(cmnd_path, "/");
	str_cat(cmnd_path, cmnd);

	return (cmnd_path);
}