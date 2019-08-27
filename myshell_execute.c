#include "shellheader.h"

/**
 * myshell_execute - function to run external or built in
 * @args: pointer to an array of pointers holding arguments
 * Return: return int value of the builtin function or external
*/

int myshell_execute(char **args)
{
	int i = 0, builtin_counter = 0;
	char *builtin_name[] = {"cd", "exit"};

	int (*builtin_func[]) (char **) = {&myshell_cd, &myshell_exit};

	if (args == NULL)/*no se cuando seria esto, porque el enter lo tenemos mapeado.. sera necesario esto?*/
	{
		printf("Please enter a command\n");
		return (1);
	}

	builtin_counter = sizeof(builtin_name) / sizeof(char *);

	while (i < builtin_counter)
	{
		if (strcmp(args[0], builtin_name[i]) == 0)
		return (builtin_func[i](args));

		i++;
	}

return (myshell_external(args));
}

/**
 * myshell_external - function to run an external proccess
 * @args: pointer to an array of pointers holding the arguments
 * Return: 1 on success, otherwise just give exit values
 * depending on error
*/

int myshell_external(char **args)
{
	char *path = NULL, *env_PATH, **directories = NULL, *directories_cpy;
	int wait_status, i = 0;

	env_PATH = _getenv("PATH");
	directories = split_path(env_PATH);
	free(env_PATH);
	while (*directories)
	{
		if (strstr(args[0], directories[i]) != NULL)
		{
			path = args[0];
			break;
		} 
		else
		{
			directories_cpy = malloc(1024 * sizeof(char));/*le acabo de quitar strlen(directories[i]) + 1*/
			if (directories_cpy == NULL)
			{
				perror("hsh: failed to allocate directories_cpy\n");
				break;
			}
			strcpy(directories_cpy, directories[i]);
			free(directories[i]);
			strcat(directories_cpy, args[0]);
			path = directories_cpy;
			if (access(path, X_OK) != 0)
			{
				/*if (!directories[i + 1]) si no es un ejecutable y ya llegó al final, creo que no es necesario pues _execv saca ese error
				{
					free(directories);
					free(directories_cpy);
					perror("hsh");
					return (1);
				}*/ free(directories_cpy);
				i++;
				continue;
			} else
			break;
		}
	} _execv(path, args);
	wait(&wait_status);
	free(directories);
	free(directories_cpy);
return (1);
}

/**
 * _execv - function to run execv with the path
 * @path: pointer holding path
 * @args: pointer to an array of strings holding the arguments
 * Return: 1 on succes , 0 on error
*/

int _execv(char *path, char **args)
{
	pid_t pid;

	pid = fork(); /*todo este fork lo puedo meter en una función?*/
	if (pid == 0)
	{
		if (execv(path, args) == -1)
		{
			perror("hsh");
			return (0); /* o -1 ?*/
		}
	}
	else if (pid < 0)
	{
		perror("hsh");
		return (0); /* o -1 ?*/
	}

return (1);
}

/**
 * myshell_cd - function to change directory
 * @args: pointer to an array of pointers holding the arguments
 * Return: 1 on success, exit value on error otherwise
*/

int myshell_cd(char **args)
{
	if (args == NULL)
	printf("Please enter a command\n"); /*acá debe ser con write*/

	else if (chdir(args[1]) != 0)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}

return (1);
}

/**
 * myshell_exit - function to exit from shell
 * @args: pointer to an array of pointers holding the arguments
 * Return: 0, always success
*/

int myshell_exit(__attribute__((unused)) char **args)
{
	return (0);
}
