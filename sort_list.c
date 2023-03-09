/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:06:14 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/03/08 11:28:22 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ascending(int a, int b)
{
	return (a <= b);
}
/*
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (cmp(lst->value, lst->next->value) == 0)
		{
			swap = lst->value;
			lst->value = lst->next->value;
			lst->next->value = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
*/
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*runner;
	int		dummy;
	int		list_num;
	int		i;
	int		j;

	runner = lst;
	list_num = 0;
	while (runner != NULL)
	{
		list_num++;
		runner = runner->next;
	}
	i = 0;
	while (i + 1 < list_num )
	{
		runner = lst;
		j = i + 1;
		while (list_num - j > 0)
		{
			if (!cmp(runner->value, runner->next->value))
			{
				dummy = runner->value;
				runner->value = runner->next->value;
				runner->next->value = dummy;
			}
			runner = runner->next;
			j++;
		}
		i++;
	}
	return (lst);
}

int	main(void)
{
	t_list *list;
	t_list *list1;
	t_list *list2;
	t_list *list3;
//	t_list *list4;
//	t_list *list5;

	list = (t_list *) malloc(sizeof(t_list));
	list->value = 5;
	list1 = (t_list *) malloc(sizeof(t_list));
	list1->value = 4;
	list2 = (t_list *) malloc(sizeof(t_list));
	list2->value = 3;
	list3 = (t_list *) malloc(sizeof(t_list));
	list3->value = 2;
//	list4 = (t_list *) malloc(sizeof(t_list));
//	list4->value = 1;
//	list5 = (t_list *) malloc(sizeof(t_list));
//	list5->value = -1;

	list->next = list1;
	list1->next = list2;
	list2->next = list3;
	list3->next = NULL;
//	list3->next = list4;
//	list4->next = list5;
//	list5->next = NULL;
	sort_list(list, &ascending);
	printf("list0.value = %d\n", list->value);
	printf("list1.value = %d\n", list1->value);
	printf("list2.value = %d\n", list2->value);
	printf("list3.value = %d\n", list3->value);
//	printf("list4.value = %d\n", list4->value);
//	printf("list5.value = %d\n", list5->value);
	return (0);
}
