#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char *new_key;
	int i = 0, len;
	if(!name || !value)
		return (-1);
	while(environ[i])
	{
		len = strlen(name);
		if(strncmp(name, environ[i], len) == 0)
		{
			if(overwrite)
			{
				new_key = malloc(strlen(name) + strlen(value) + 2);
				strcpy(new_key, name);
				strcat(new_key, "=");
				strcat(new_key, value);
				environ[i] = new_key;
				return 0;
			}
			return 0;
		}
		i++;
	}
	new_key = malloc(strlen(name) + strlen(value)+ 2);
	strcpy(new_key, name);
	strcat(new_key, "=");
	strcat(new_key, value);
	environ[i] = new_key;
	environ[i + 1] = NULL;
	return 0;
}
int main(void)
{
	extern char **environ;
	int i = 0;
	_setenv("PWD","/home/iliass/basrtaj/test", 0 );
	while(environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	i = 0;
	_setenv("OLDPWD", "/from_here/iliass/basrtaj/test", 1);
	while(environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	i = 0;
	_setenv("iliass_test", "/home/iliass/basrtaj/test", 1);
	 while(environ[i])
	 {
		 printf("%s\n", environ[i]);
		 i++;
	 }
	 return 0;
}




