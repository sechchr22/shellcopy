#include "shellheader.h"
/**
 * split_path - function to split env variable PATH into tokens
 * @path: pointer holding PATH
 * Return: Pointer to an array of strings holding the tokens
*/
char **split_path(char *path)
{
	unsigned int i;
	char *tok = NULL, **dir;
	size_t dir_size = 1024;

	dir = malloc(sizeof(char *) * dir_size);
	if (dir == NULL)
	{
		perror("split_path: failed to allocate dir\n");
		exit(EXIT_FAILURE);
	} tok = strtok(path, "= :");
	tok = strtok(NULL, "= :");
	if (tok == NULL)
	{
		free(dir);
		perror("Please enter a path\n");
		exit(EXIT_FAILURE);
	} else
	{
		i = 0;
		while (tok != NULL)
		{
			dir[i] = malloc(sizeof(char) * (strlen(tok) + 2)); /*+1 por el slash*/ /*debe ser +2 por el null tambien*/
			if (dir[i] == NULL)
			{
				free(dir);
				perror("hsh: failed to allocate dir[i]\n");
				exit(EXIT_FAILURE);
			} strcpy(dir[i], tok); /*strcpy agrega un '/0' al final osea que no tendrá ese espacio extra en el strcat*/
			strcat(dir[i], "/");
			tok = strtok(NULL, "= :");
			i++;
			if (i >= dir_size)
			{
				dir_size += 1024;
				dir = realloc(dir, dir_size * sizeof(char *)); /*verificar si falla*/
				if (dir == NULL)
				perror("hsh: failed to reallocate dir\n");
			}
		} dir[i] = NULL;
	} return (dir);
}
