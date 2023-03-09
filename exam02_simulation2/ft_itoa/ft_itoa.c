#include <stdlib.h>

int	find_digit(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);

}

void	putnbr(char *str, int n)
{
	static int	i = 0;

	if (n < 0 && !i)
	{
		str[i] = '-';
		i++;
	}
	if (n < 10 && n >= 0)
	{
	       str[i] = n + '0';
	       i++;
	       return ;
	}
	else if (n > 10)
	{
		putnbr(str, n / 10);
		str[i] = (n % 10) + '0';
		i++;
	}
	else if (n > -10 && n < 0) 
	{
		str[i] = n * (-1) + '0';
		i++;
		return ;
	}
	else if (n < -10)
	{
		putnbr(str, n / 10);
		str[i] = (n % 10) * (-1) + '0';
		i++;
	}

}

char	*ft_itoa(int nbr)
{
	int	i;
	char	*str;

	i = find_digit(nbr) + 1;
	str = (char *) malloc(i);
	if (!str)
		return (NULL);
	while (--i >= 0)
		str[i] = 0;
	putnbr(str, nbr);
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char *str;
	
	str = ft_itoa(-2147483648);
	printf("ft_itoa(-2147483648) = %s\n", str);
	free(str);
	return (0);
}

