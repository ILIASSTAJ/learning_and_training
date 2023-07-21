#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 
*/

void chek_command (char *command)
{
	if(access(command, F_OK) == 0)
		printf("%s found!\n", command);
	else
		printf("%s not found!\n", command);
}
void alx_cheker (char *command)
{
	struct stat st;

	if(stat(command, &st) == 0)
	{
		printf("%s : is found!\n", command);
	}else{
		printf("%s : is not found try to write the full path please!\n", command);
	}
}

int main(void)
{
	char *buffer;
	size_t buffer_size;
	int n_chars;
	char *token;
	while(1)
	{
		write(1, "$ ", 2);
		n_chars = getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, " \t\n");
		if(strcmp(token, "which") == 0)
		{
			while(token = strtok(NULL, " \t\n"))
			{
				alx_cheker(token);
			}
		}
	}
	return (0);
}

