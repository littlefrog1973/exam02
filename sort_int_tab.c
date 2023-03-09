/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:25:28 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/03/07 12:56:44 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				dummy;

	i = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				dummy = tab[i];
				tab[i] = tab[j];
				tab[j] = dummy;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int	arr[] = {5, 4, 3, 2, 2, 5, 1, 0, 2, -1 };

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	sort_int_tab(arr, 10);
	printf("After sort\n");
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return (0);
}
