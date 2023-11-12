#include "main.h"

char *find_cmd(const char *tokenz)
{
	char *env = _getenv("PATH");
	char *env_cpy = NULL;
	char *token = NULL;
	char *output = NULL;

	if ((env_cpy = strdup(env)) == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(env_cpy, ":");
	output = NULL;

	while (token != NULL)
	{
		if ((output = malloc(MAX_SIZE)) == NULL)
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
			free(env_cpy);
			return (output);
		}

		free(output);
		token = strtok(NULL, ":");
	}

	free(env_cpy);
	return (NULL);
}
