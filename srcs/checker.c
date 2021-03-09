/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/09 12:06:58 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/**
 * Check if the given list is sorted
 * @return	0 if the list is sorted, otherwise return 1
 **/

int		checker(t_dlist *list)
{
	t_dlist	*tmp;

	tmp = list;
	if (*(int*)(list->content) > *(int*)(list->next->content))
		return (1);
	tmp = tmp->next;
	while (tmp && tmp->next != list)
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
	int		*tmp;

	if (*list && (*list)->next)
	{
		tmp = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->content = tmp;
	}
}

/**
 * Take the ﬁrst element at the top of b and put it at the top of a
 * Do nothing if b is empty
 **/

void	push(t_dlist **a, t_dlist **b)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstremove_one(*b)))
		ft_dlstadd_front(a, tmp);
}

/**
 * Shift up all elements of stack a by 1
 * The ﬁrst element becomes the last one
 **/

void	rotate(t_dlist **list)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstremove_one(*list)))
		ft_dlstadd_back(list, tmp);
}

/**
 * Shift down all elements of stack a by 1
 * The last element becomes the ﬁrst one.
 **/

void	reverse(t_dlist **list)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstremove_one(ft_dlstlast(*list))))
		ft_dlstadd_front(list, tmp);
}
