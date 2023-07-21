#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv, char **env)
{
	extern char **environ;
	printf("env : %p\n", env);
	printf("environ %p\n", environ);
	int i = 0;
	while(env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	return 0;
}

