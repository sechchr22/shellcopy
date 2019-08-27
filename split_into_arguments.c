#include "shellheader.h"
/**
 * split_into_arguments - function to splite the line indexed
 * by the user into tokens that will be the commands to read
 * @line: Pointer that will hold the line indexed by user
 * Return: Pointer to an array of pointers that will hold
 * each command
*/
char **split_into_arguments(char *line)
{
	int i;
	int commands_size = 32;
	char **commands;
	char *tok = NULL;

	commands = malloc(commands_size * sizeof(char *));

	if (commands == NULL)
	dprintf(STDERR_FILENO, "allocation error\n");

	tok = strtok(line, " \t\n\r\a");

	if (tok == NULL)
	{
		free(commands);
		printf("Please enter a command\n");
	}

	else
	{
		i = 0;
		while (tok != NULL)
		{
			commands[i] = tok;
			tok = strtok(NULL, " \n");
			i++;

			if (i >= commands_size)
			{
				commands_size += 32;
				commands = realloc(commands, commands_size * sizeof(char *));
				if (commands == NULL)
				perror("hsh: failed to realloc commands\n");
			}
		}
		commands[i] = NULL;
	}

return (commands);
}
