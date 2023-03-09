#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	flag1;
	int	flag2;
	int	cap;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	flag1 = 0;
	flag2 = 0;
	cap = 0;
	while (argv[1][i])
	{
		if (flag2 && argv[1][i] != '_')
		{
			cap = argv[1][i] + ('A' - 'a');
			write(1, &cap, 1);
			flag2 = 0;
			i++;
			continue;
		}
		if (argv[1][i] != '_')
		{
			write(1, &argv[1][i], 1);
			flag1 = 1;
		}
		if (flag1 && argv[1][i] == '_')
		{
			flag2 = 1;
		}	
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
