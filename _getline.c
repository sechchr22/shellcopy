#include "shellheader.h"

/**
 * _getchar - function to get a character from STDIN
 * Return: the character
*/

int _getchar(void)
{
	char charbuf[1];
	int n;

	n = read(0, charbuf, 1);

	if (n < 1)
	perror("read failed");

return (charbuf[0]);
}

/**
 * _getline - my getline function
 * @line: pointer to the resultant string holding what the user typed
 * @line_size: pointer to an integer that means the size of line
 * @stream: pointer to the fd STDIN
 * Return: number of characters indexed by the user
*/

ssize_t _getline(char **line, ssize_t *line_size, FILE *stream)
{
	char *buffer;
	ssize_t characters = 0, character;

	buffer = malloc(sizeof(char) * (*line_size));

	if (!buffer)
	{
		perror("hsh: line allocation error\n");
		exit(EXIT_FAILURE);
	}

	*line = buffer;

	while (1 & (stream == stdin))
	{
		fflush(stdout);
		character = _getchar();

		if (character == EOF || character == '\n')
		{
			buffer[characters] = '\0';
			break;
		}
		else
		{
			buffer[characters] = character;
			characters++;
		}
		if (characters >= *line_size)
		{
			*line_size += 1024;
			buffer = realloc(buffer, (*line_size) * (sizeof(char)));
			if (!buffer)
			{
				perror("hsh: line reallocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
return (characters);
}
