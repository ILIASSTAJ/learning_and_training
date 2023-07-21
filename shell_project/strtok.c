#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main (void)
{
	char *buffer;
	size_t len;
	int n_char;
	char *token;
	char *buffer_tow;
	while(1)
	{
		write(1, "$ ", 2);
		n_char = getline(&buffer, &len, stdin);
		if(n_char == -1)
		{
			perror("getline\n");
		}
		buffer_tow = strdup(buffer);
		token = strtok(buffer, " \t\n");
		while(token)
		{
			printf("%s\n", token);
			token = strtok(NULL, " \t\n");
		}
		printf("%s\n",buffer_tow);
	}

	return 0;
} 
