#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *main-prototype
 *Return: 0
 */
int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;
	char *token;
	char *i = malloc(10);
	char flag = '1';
	i = &flag;
	size_t size = 1;

	while (*i != '0')
	{
		printf("$ ");
		getline(&buffer, &len, stdin);
		printf("buffer getline: %s", buffer);
		token = strtok(buffer, " ");
		while (token)
		{
			printf("buffer strtok: %s\n", token);
			token = strtok(NULL, " ");
		}
		printf("print 0 to quit $ ");
		getline(&i, &size, stdin);
	}
	return (0);
}
