#include "main.h"

/**
 *find_cmd -  A funcion to get the path
 *of the command passed.
 *
 *@tokenz: an array of tokenized commands.
 *Return: a pointer to the path of the command.
 */




char *find_cmd(const char *tokenz);

char *find_cmd(const char *tokenz)
{
	char *env = _getenv("PATH");
	char *env_cpy = NULL;
	char *token = NULL;
	char *output = NULL;

	env_cpy = strdup(env);

	if (env_cpy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(env_cpy, ":");
	output = NULL;

	while (token != NULL)
	{
		output = malloc(MAX_SIZE);

		if (output == NULL)
		{
			perror("malloc");
			free(env_cpy);
			return (NULL);
		}

		strcpy(output, token);

		if (output[_strlen(output) - 1] != '/')
			strcat(output, "/");

		strcat(output, tokenz);

		if (access(output, X_OK) == 0)
		{
			return (output);
		}

		free(output);
		token = strtok(NULL, ":");
	}
	free(env_cpy);
	return (NULL);
}
