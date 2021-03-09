/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/09 10:57:47 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/**
 * if the given array is sorted return 0, else return 1
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

void	push(t_dlist **a, t_dlist **b)
{
	t_dlist	*tmp;
	if (*b)
	{
		tmp = ft_dlstremove_one(*b);
		ft_dlstadd_front(a, tmp);
	}
}

// void	rotate(t_dlist **list)
// {

// }

// void	reverse(t_dlist **list)
// {

// }