#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	n;

	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	n = atoi(argv[1]);
	if (n == 1)
	{
		printf("%d\n", 1);
		return (0);
	}
	for (i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			if (n != i)
				printf("%d*", i);
			else
				printf("%d", i);
			n /= i;
		}
	}
	printf("\n");
	return (0);
}
