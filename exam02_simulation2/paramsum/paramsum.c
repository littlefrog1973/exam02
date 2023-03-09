#include <unistd.h>

void	putnbr(char *str, int n)
{
	static	int	i;

	if (n < 10)
	{
		str[i] = n + '0';
		i++;
		return ;
	}
	else
	{
		putnbr(str, n / 10);
		str[i] = (n % 10) + '0';
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	(void) argv;
	argc -= 1;
	char str[11] = {0};
	putnbr(str, argc);
	i = 0;
	while (str[i])
		i++;	
	write(1, str, i);
	write(1, "\n", 1); 
	return (0);
}
