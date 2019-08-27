#include "shellheader.h"

/**
 * _getenv - function to get an enviroment variable
 * @name: pointer to hold the name of the enviroment variable
 * to be found
 * Return: pointer holding the enviroment variable found
*/

char *_getenv(const char *name)
{
	char **envp;
	char *buffer;
	size_t buf_size = 1024, pathlen;

	if (name == NULL)
	{
		perror("hsh: Please enter a valid env\n");
		exit(EXIT_FAILURE);
	}

	envp = environ;
	buffer = malloc(sizeof(char) * buf_size);
	if (!buffer)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}

	while (*envp) /*cambie envp++ por i++*/
	{
		if (strncmp(*envp, name, strlen(name)) == 0) /*toca poner el strncmp que cojo del repositorio de diego*/
		{
			pathlen = strlen(*envp);

			if (pathlen >= buf_size)
			{
				buffer = realloc(buffer, buf_size);
				if (!buffer)
				{
					free(buffer);
					perror("hsh"); /*acá creo que si va mensaje*/
					exit(EXIT_FAILURE);
				}
			}
			strcpy(buffer, *envp); /*have to handle error of strcpy?*/
			break;
		}
		envp++;
	}
return (buffer);
}
