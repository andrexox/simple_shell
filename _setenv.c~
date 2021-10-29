#include "shell.h"

/**
 * _setenv - adds the environment variables
 * @envp: pointer to the environment variables
 *
 * Return: pointer to array of paths
 */
int _setenv(const char *name, const char *value, char **envp);
{
	char *path = _getenv("PATH", envp);
	char **pathparsed = fullpath(path, ENVDELIM);

	return (pathparsed);
}
