#include "shell.h"

/**
 * _getenv - gets an environment variable
 * @name: name of the environment variable
 * @envp: pointer to the environment
 *
 * Return: char with the same path
 */
char *_getenv(const char *name, char **envp)
{
	int i = 0, j = 0, compare = 0;

	for (; envp[i] != NULL; i++)
	{
		for (; envp[i][j] != '='; j++)
		{
			compare = _strcmp((char *)name, envp[i]);
			if (compare == 0)
			{
				return (envp[i]);
			}
			break;
		}
	}
	return (envp[i]);
}
