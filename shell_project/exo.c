#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t my_pid;
	pid_t child = 1;
	int i = 0;
	int status;
	char * argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	while(i < 5 && child != 0)
	{
		child = fork();
		if(child == -1)
		{
			printf("error");
			return 1;
		}
		wait(&status);
		i++;
	}
	if(child != 0)
	{
		printf("%u \n", getppid());
	}else{
		printf("%u \n", getppid());
		execv(argv[0], argv);
		printf("%u \n", getpid());
	}
	printf("in the main procss\n");
	return 0;
}


