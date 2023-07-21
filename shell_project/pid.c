#include <stdio.h>
#include <unistd.h>


void test (void)
{
	pid_t ur_pid;
	ur_pid = getpid();
	printf("%u\n", ur_pid);
	ur_pid = getppid();
	printf("%u\n", ur_pid);
}
int main (void)
{
	pid_t my_pid;
	my_pid = getpid();
	printf("%u\n", my_pid);
	printf(" hey\n");
	my_pid = getpid();
	printf("%u\n",my_pid);
	test();
	return 0;
}

