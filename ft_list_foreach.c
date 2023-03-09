/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:42:48 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/03/08 13:56:54 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	f(void *ptr)
{
	int		i;
	char	*str;

	str = (char *) ptr;
	i = 0;
	while (str[i])
	{
		str[i] += 'A' - 'a';
		i++;
	}
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*runner;

	runner = begin_list;
	while (runner != NULL)
	{
		(*f)(runner->data);
		runner = runner->next;
	}
}

#include <string.h>

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	*list_ptr;

	a.data = strdup("abc");
	b.data = strdup("def");
	c.data = strdup("hij");
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	list_ptr = &a;
	ft_list_foreach(list_ptr, &f);
	while (list_ptr != NULL)
	{
		printf("%s\n", (char *) list_ptr->data);
		list_ptr = list_ptr->next;
	}
	free(a.data);
	free(b.data);
	free(c.data);
	return (0);
}

