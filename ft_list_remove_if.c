/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:42:59 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/03/09 00:23:33 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	equal(void *a, void *b)
{
	return !(a == b);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*runner;
	t_list	*before;

	runner = *begin_list;
	before = *begin_list;
	while (runner != NULL)
	{
		if (!cmp(runner->data, data_ref))
		{
			if (*begin_list == runner)
			{
				*begin_list = runner->next;
				free(runner);
				runner = *begin_list;
				continue;
			}
			before->next = runner->next;
			free(runner);
			runner = before->next;
			continue;
		}
		before = runner;
		runner = runner->next;
	}
}

#include <string.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*d;
	t_list	**list_ptr;
	t_list	*dummy;
	char	aa[] = "abc";
//	char	bb[] = "def";
	char	cc[] = "hij";
	char	dd[] = "klm";

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	c = malloc(sizeof(t_list));
	d = malloc(sizeof(t_list));
	a->data = aa;
	b->data = aa;
	c->data = cc;
	d->data = dd;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	list_ptr = &a;
	ft_list_remove_if(list_ptr, "abc", strcmp);
	dummy = *list_ptr;
	while (*list_ptr != NULL)
	{
		printf("%s\n", (char *) (*list_ptr)->data);
		*list_ptr = (*list_ptr)->next;
	}
	*list_ptr = dummy;
	free(d);
//	free(b);
	free(c);

	return (0);
}
