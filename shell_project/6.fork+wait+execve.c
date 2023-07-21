#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - exercise: fork + wait + execve
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t my_pid;
	int status;
	int i = 0;
	char *argv[] = {"/bin/ls", "-a", "./", NULL};

	for(; i < 5; i++)
	{
		my_pid = fork();
		if(my_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if(my_pid == 0)
		{
			if(execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}else{
			wait(&status);
			printf("i'm the fother\n");
		}
	}
	return (0);
}
