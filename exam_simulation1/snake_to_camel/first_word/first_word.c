#include <unistd.h>

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\n' || c == '\r')
		return (1);
	else
		return (0);
}


int	main(int argc, char *argv[])
{
	int	i;
	int	flag;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	flag = 0;
	while (argv[1][i])
	{
		if (!ft_isspace(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
			flag = 1;
		}
		else if (flag)
		{
			break;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
