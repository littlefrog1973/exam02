#include <stdlib.h>
#include <unistd.h>

int	print_word(char *str)
{
	int	i;

	i = 0;
	while (!(str[i] == ' ' || str[i] == '\t' || str[i] == 0))
	{
		write(1, &str[i], 1);
		i++;
	}
	if (str[i] == ' ' || str[i] == 0)
		write(1, " ", 1);
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;
	int flag;
	int word_count;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	flag = 0;
	word_count = 0;
	while (argv[1][i])
	{
		if (!(argv[1][i] == ' ' || argv[1][i] == '\t') && !flag)
		{
			flag = 1;
			word_count++;
		}
		else if (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
			flag = 0;
		}
		if (word_count > 1 && !(argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			i +=print_word(&argv[1][i]);
			continue ;
		}
		i++;
	}
	i = 0;
	flag = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == 0) && flag)
			break;
		if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			write(1, &argv[1][i], 1);
			flag = 1;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
