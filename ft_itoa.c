#include <stdlib.h>

int	find_digit(int n)
{
	int	i;
	int	minus;

	if (n == 0)
		return (1);
	if (n < 0)
		minus = 1;
	else
		minus = 0;
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + minus);
}

void	putnbr(char *str, int n)
{
	static int	i;

	if (n < 10 && n >= 0)
	{
		*(str + i) = n + '0';
		i++ ;
		return ;
	}
	else if (n >= 10)
	{
		putnbr(str, n / 10);
		*(str + i) = (n % 10) + '0';
		i++;
	}
	else if (n > -10 && n < 0)
	{
		*(str + i) = '-';
		i++;
		*(str + i) = n * (-1) + '0';
		i++;
		return ;
	}
	else if (n <= -10)
	{
		putnbr(str, n / 10);
		*(str + i) = (n % 10) * (-1) + '0';
		i++;
		return ;
	}
}

char	*ft_itoa(int n)
{
//	long int	nn;
	char		*str;

//	nn = (long int) n;
	str = (char *) malloc (find_digit(n) + 1);
	putnbr(str, n);
	*(str + find_digit(n)) = 0;
	return (str);
}

#include <stdio.h>

int	main(void)
{
	printf("ft_itoa(-2147483649) = %s\n", ft_itoa(-2147483649));
}
