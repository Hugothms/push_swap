/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/12 13:15:21 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Check if the given list is sorted
 * @return	0 if the list is sorted, otherwise return 1
 **/

int		checker(t_dlist *a, t_dlist *b)
{
	t_dlist	*tmp;

	if (!a)
		return (0);
	tmp = a;
	if (*(int*)(a->content) > *(int*)(a->next->content) || b)
		return (1);
	tmp = tmp->next;
	while (tmp && tmp->next != a)
	{
		if (*(int*)(tmp->content) > *(int*)(tmp->next->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/**
 * Swap the ﬁrst 2 elements at the top of stack
 * Do nothing if there is only one or no elements)
 **/

void	swap(t_dlist **list)
{
	int		*num;

	if (*list && (*list)->next)
	{
		num = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->next->content = num;
	}
}

/**
 * Take the ﬁrst element at the top of b and put it at the top of a
 * Do nothing if b is empty
 **/

void	push(t_dlist **a, t_dlist **b)
{
	int		*num;
	t_dlist	*tmp;

	if (!*b)
		return ;
	num = (*b)->content;
	tmp = *b;
	ft_dlstremove_one(b, *b);
	if (!(tmp = ft_dlstnew(num)))
		return ;
	ft_dlstadd_front(a, tmp);
}

/**
 * Shift up all elements of stack a by 1
 * The ﬁrst element becomes the last one
 **/

void	rotate(t_dlist **list)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstremove_one(list, *list)))
		ft_dlstadd_back(list, tmp);
}

/**
 * Shift down all elements of stack a by 1
 * The last element becomes the ﬁrst one.
 **/

void	reverse(t_dlist **list)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstremove_one(list, ft_dlstlast(*list))))
		ft_dlstadd_front(list, tmp);
}
