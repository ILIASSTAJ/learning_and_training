#include <stdio.h>
#include <unistd.h>


int main (void)
{
	printf("in the parent file\n");
	pid_t my_pid;
	my_pid = getpid();
	printf("the parent pid is : %u\n", my_pid);
	char *buffer = "/bin/ls";
	char *argv[] = {buffer, NULL};
	execv(argv[0], argv);
	return 0;
}
