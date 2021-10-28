#include "shell.h"

/**
 * _printenv - prints variables in the
 * current working environment
 *
 * Return: void
 */
void _printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}

/**
 * _isBuiltIn - to check if token is a built-in
 * @str: Pointer to string to check
 *
 * Return: 0 if true, 1 if false
 */
int _isBuiltIn(char *str)
{
	if ((_strcmp(str, "env")) == 0)
	{
		return (0);
	}
	if ((_strcmp(str, "exit")) == 0)
		return (0);
	if ((_strcmp(str, "setenv")) == 0)
		return (0);
	if ((_strcmp(str, "unsetenv")) == 0)
		return (0);
	return (1);

}

/**
 * _executeBuiltIn - executes a built-in function
 * @tokens: Double pointer to tokens
 *
 * Return: 0 on success
 */
int _executeBuiltIn(char **tokens)
{
	if ((_strcmp(*tokens, "env")) == 0)
	{
		_printenv();
		return (0);
	}
	if ((_strcmp(*tokens, "setenv")) == 0)
	{
		if (tokens[1] && tokens[2])
		{
			_setenv(tokens[1], tokens[2]);
			return (0);
		}
		printf("Usage: setenv var_name var_value\n");
		return (0);
	}
	if (_strcmp(*tokens, "unsetenv") == 0)
	{
		if (tokens[1])
		{
			_unsetenv(tokens[1]);
			return (0);
		}
		printf("Usage: unsetenv VAR_NAME\n");
		return (0);
	}

	return (1);
}

/**
 * _exitSimpleShell - exits the shell
 * and frees up memory
 * @tokens: Double pointer to words split from the line
 * @line: Pointer to string gotten using getLine()
 *
 * Return: void
 */
void _exitSimpleShell(char **tokens, char *line)
{
	int status;

	if (tokens[1] != NULL)
	{
		status = atoi(tokens[1]);
		if (status >= 0)
		{
			free(line);
			free(tokens);
			exit(status);
		}
		write(STDERR_FILENO, "Exit: illegal exit status: ", 28);
		write(STDERR_FILENO, tokens[1], 1);
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		free(line);
		free(tokens);
		exit(0);
	}
}
