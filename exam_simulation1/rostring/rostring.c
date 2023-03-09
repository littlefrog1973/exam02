#include <unistd.h>

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r' || c == '\v')
		return (1);
	else
		return (0);
}

int	put_word(char *str)
{
	int	i;

	i = 0;
	while (!ft_isspace(str[i]) && str[i])
		i++;
	write(1, str, i);
	return (i);
}
int	main(int argc, char *argv[])
{
	int	i;
	int	flag;
	int	word;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	word = 0;
	flag = 0;
	while (argv[1][i])
	{
		if (!ft_isspace(argv[1][i]) && !flag)
		{
			word++;
			flag = 1;
			if (!ft_isspace(argv[1][i]) && word > 1)
			{
				i +=put_word(&argv[1][i]);
				write(1, " ", 1);
				flag = 0;
				continue;
			}
		}
		else if (ft_isspace(argv[1][i]) && flag)
			flag = 0;	
		i++;	
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isspace(argv[1][i]))
		{
			put_word(&argv[1][i]);
			write(1, "\n", 1);
			break;
		}
		i++;
	}
	return (0);
}
