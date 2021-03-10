/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:37:07 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/10 16:37:18 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_dlist_line(t_dlist *list)
{
	t_dlist	*tmp;
	int		*num;

	tmp = list;
	while (tmp && tmp->next != list)
	{
		num = tmp->content;
		ft_printf("%d", *num);
		tmp = tmp->next;
	}
	num = tmp->next->content;
	ft_printf("\nnext:%d", *num);
	ft_printf("\n");
}

void	print_first_item_dlist(t_dlist *dlist)
{
	if (dlist)
		ft_printf("%d ", *((int*)dlist->content));
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
		ft_printf("\n");
	}
	ft_printf("- -\na b\n\n");
}
