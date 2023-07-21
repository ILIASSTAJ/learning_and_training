#include <stdio.h>
#include <unistd.h>


int main (int argc, char *argv[])
{
	printf("in the child file\n");
	pid_t my_pid;
	my_pid = getpid();
	printf("the child pid is : %u\n", my_pid);
	printf(" 1 : %s\n", argv[1]);
	printf("2 : %s\n", argv[2]);
	return 0;
}
