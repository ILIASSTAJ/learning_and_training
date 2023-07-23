#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

int _unsetenv(const char *name)
{
	extern char **environ;
	int i = 0;
	int len = strlen(name);
	while(environ[i])
	{
		if(strncmp(name, environ[i], len) == 0)
		{
			environ[i] = NULL;
			return 0;
		}
		i++;
	}
	return 0;
}
int main(void)
{
	extern char **environ;
	int i = 0;
	_unsetenv("PWD");
	while(environ[i] != NULL || environ[i + 1] != NULL)
	{
		if(environ[i] == NULL)
		{
			i++;
			continue;
		}
		else
			printf("%s\n", environ[i]);
		i++;
	}
	return 0;
}

