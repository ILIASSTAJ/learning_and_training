#include <stdio.h>



int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;

	while(argv[i][j])
	{
		
		while(argv[i][j])
		{
			printf("%c",argv[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}

	return 0;
}

