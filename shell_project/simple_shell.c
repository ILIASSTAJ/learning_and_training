#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main (void)
{
	char *buffer;
	char *token;
	char **argv = NULL;
	size_t len;
	int n_chars;
	int status;
	pid_t my_pid;

	while(1)
	{
		write(1, "$ ", 2);
		argv =  malloc(sizeof(char*) * 1024);
		n_chars = getline(&buffer, &len, stdin);
		token = strtok(buffer, " \t\n");
		int i = 0;
		for(; token; i++)
		{
			argv[i] = token;
			token = strtok(NULL, " \t\n");
		}
		my_pid = fork();
		if(my_pid == 0)
		{
			if(execve(argv[0], argv, NULL) == -1)
				perror("execve");
		}else{
			wait(&status);
		}
		free(argv);
	}


	return 0;



}
