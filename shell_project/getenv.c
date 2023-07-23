#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


char *_getenv(const char *name)
{
	extern char **environ;
	char *token;
	int i = 0;

	while(environ[i])
	{
		token = strtok(environ[i], "=");
		printf("%s\n", token);
		if(strcmp(name, token) == 0)
		{
			return(token = strtok(NULL, "\n"));
		}
		i++;
	}
	return NULL;
}
int main (void)
{
	char *buffer;
	char *token;
	size_t buffer_size;
	int n_chars;
	while(1)
	{
		write(1, "$ ", 2);
		n_chars = getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, " \t\n");
		printf("the value of : %s is equal to : %s\n", token, _getenv(token));
		
	}
	//printf("%s\n", _getenv("PWD"));
	return 0;
}


