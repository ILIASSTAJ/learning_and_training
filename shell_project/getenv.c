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
			return(token = strtok(NULL, "="));
		}
		i++;
	}
	return NULL;
}
int main (void)
{
	/*ar *buffer;
	size_t buffer_size;
	int n_chars;
	while(1)
	{
		write(1, "$ ", 2);
		n_chars = getline(&buffer, &buffer_size, stdin);
		printf("the value is equal to : %s\n",_getenv(buffer));
	}*/
	printf("%s\n", _getenv("PWD"));
	return 0;
}


