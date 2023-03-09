#include <unistd.h>

void	lower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 'a' - 'A';
		}
		i++;
	}
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\n' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);	
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	cap;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	j = 1;
	while (j < argc)
	{
		lower(argv[j]);
		i = 0;
		cap = 0;
		while (argv[j][i])
		{
			if(ft_isalpha(argv[j][i]) && (ft_isspace(argv[j][i + 1]) || argv[j][i + 1] == 0))
			{
				cap = argv[j][i] - ('a' - 'A');
				write(1, &cap, 1);
			}
			else
			{
				write(1, &argv[j][i], 1);
			}
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
/*	i = 0;
	while (argv[1][i])
	{
		write(1, &argv[1][i], 1);
		i++;
	}
*/
	return (0);
}
