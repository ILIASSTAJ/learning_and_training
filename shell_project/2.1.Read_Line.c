#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	char *buffer = NULL;
	size_t len;
	int n_char;
	write(1, "$ ", 2);
	n_char = getline(&buffer, &len, stdin);
	if(n_char == -1)
	{
		perror("getline\n");
	}
	printf("%s\n", buffer);

	return 0;
}






