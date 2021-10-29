#include "shell.h"

/**
 * _unsetenv - removes an environment variable
 * @name: variable name
 *
 * Return: 0
 */
int _unsetenv(const char *name)
{
	int i = 0;
	char **env_temp;
	size_t name_len;

	name_len = _strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, name_len) == 0)
		{
			env_temp = environ;
			free(env_temp[0]);
			do {
				env_temp[0] = env_temp[1];
				env_temp++;
			} while (*env_temp);
		}
		i++;
	}
	return (0);
}
