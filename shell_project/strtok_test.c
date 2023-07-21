#include <stdio.h>
#include <string.h>


int main()
{
	char *token;
	char test[] ="iliass=basr taj";    // very importat thing if u wanna work with the string u should declar it this way test[] because this  way char *test is just a read only; 
        token = strtok(test, "=");
        printf("%s\n",token);
	return 0;
}
