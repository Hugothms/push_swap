/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:37:07 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/23 15:17:22 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_dlist_line(t_dlist *stack, char name)
{
	t_dlist	*tmp;
	int		*num;

	tmp = stack;
	printf("%c: ", name);
	while (tmp && tmp->next != stack)
	{
		num = tmp->content;
		printf("%d ", *num);
		tmp = tmp->next;
	}
	if (tmp)
	{
		num = tmp->content;
		printf("%d", *num);
	}
	printf("\n");
}

void	print_first_item_dlist(t_dlist *dlist)
{
	if (dlist)
		printf("%d ", *((int *)dlist->content));
}

void	print_clean_dlist(t_dlist *a, t_dlist *b)
{
	t_dlist	*tmp_a;
	t_dlist	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	print_first_item_dlist(a);
	print_first_item_dlist(b);
	printf("\n");
	if (tmp_a)
	tmp_a = tmp_a->next;
	if (tmp_b)
	tmp_b = tmp_b->next;
	while ((tmp_a && tmp_a != a) || (tmp_b && tmp_b != b))
	{
		if (tmp_a != a)
		{
			print_first_item_dlist(tmp_a);
			tmp_a = tmp_a->next;
		}
		if (tmp_b != b)
		{
			print_first_item_dlist(tmp_b);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
	printf("- -\na b\n\n");
}
