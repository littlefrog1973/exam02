#include <stdlib.h>
#include <unistd.h>

int	word_count(char *str)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != '\t' || str[i] != ' ') && !flag)
		{
			count++;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		i++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void print_with_space(char *str, int n)
{
	char *str_with_space;
	int	i;

	str_with_space = (char *) malloc(n + 1);
	i = 0;
	while (i < n)
	{
		str_with_space[i] = str[i];
		i++;
	}
	str_with_space[i] = ' ';
	write(1, str_with_space, n + 1);
	free(str_with_space);
}

int	main(int argc, char *argv[])
{
	int	i;
	int j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = ft_strlen(argv[1]) - 1;
	j = 0;
	while (i > 0)
	{
		if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			j++;
		}
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
//			print_with_space(&argv[1][i + 1], j);
			write(1, &argv[1][i + 1], j);
			write(1, " ", 1);
			j = 0;
		}
		i--;
	}
	write(1, &argv[1][0], j + 1);
	write(1, "\n", 1);
	return (0);
}
