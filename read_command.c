#include "shellheader.h"

/**
 * read_command - read the command that the user will type
 * in my shell and stores it in a buffer
 * Return: the buffer
*/
char *read_command(void)
{
	ssize_t linesize = 32;
	char *line = NULL;

	/*getline(&line, &linesize, stdin);*/
	_getline(&line, &linesize, stdin);

	return (line);
}
