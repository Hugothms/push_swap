/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_under_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:01:12 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:28:48 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Sort a stack of 3 node with the smallest number of instructions possible
** @param stack	stack of size 3 to sort
** @param name	name of the stack we are working on
*/

void	sort_stack_3(t_dlist **st, char name)
{
	if (ft_dlstsize((*st)) != 3 || !checker((*st)))
		return ;
	if (get_value((*st)) > get_value((*st)->next)
		&& get_value((*st)->next) < get_value((*st)->next->next)
		&& get_value((*st)->next->next) > get_value((*st)))
		sort1(st, name);
	else if (get_value((*st)) > get_value((*st)->next)
		&& get_value((*st)->next) > get_value((*st)->next->next)
		&& get_value((*st)->next->next) < get_value((*st)))
		sort2(st, name);
	else if (get_value((*st)) > get_value((*st)->next)
		&& get_value((*st)->next) < get_value((*st)->next->next)
		&& get_value((*st)->next->next) < get_value((*st)))
		sort3(st, name);
	else if (get_value((*st)) < get_value((*st)->next)
		&& get_value((*st)->next) > get_value((*st)->next->next)
		&& get_value((*st)->next->next) > get_value((*st)))
		sort4(st, name);
	else if (get_value((*st)) < get_value((*st)->next)
		&& get_value((*st)->next) > get_value((*st)->next->next)
		&& get_value((*st)->next->next) < get_value((*st)))
		sort5(st, name);
}

/*
** Sort a stack of 3 node with the smallest number of instructions possible
** @param stack	stack of size 3 to sort
** @param name	name of the stack we are working on
*/

void	sort_stack_3_reverse(t_dlist **st, char name)
{
	if (ft_dlstsize((*st)) != 3)
		return ;
	if (get_value((*st)) > get_value((*st)->next)
		&& get_value((*st)->next) < get_value((*st)->next->next)
		&& get_value((*st)->next->next) > get_value((*st)))
		sort5(st, name);
	else if (get_value((*st)) < get_value((*st)->next)
		&& get_value((*st)->next) < get_value((*st)->next->next)
		&& get_value((*st)->next->next) > get_value((*st)))
		sort2(st, name);
	else if (get_value((*st)) > get_value((*st)->next)
		&& get_value((*st)->next) < get_value((*st)->next->next)
		&& get_value((*st)->next->next) < get_value((*st)))
		sort4(st, name);
	else if (get_value((*st)) < get_value((*st)->next)
		&& get_value((*st)->next) > get_value((*st)->next->next)
		&& get_value((*st)->next->next) > get_value((*st)))
		sort3(st, name);
	else if (get_value((*st)) < get_value((*st)->next)
		&& get_value((*st)->next) > get_value((*st)->next->next)
		&& get_value((*st)->next->next) < get_value((*st)))
		sort1(st, name);
}

int		sort_stack_under_3_pre(t_stacks *ab, t_dlist **begin, int p_a)
{
	if (!p_a)
		push_n_times(ab, begin, 'b', 3);
	sort_stack_3_reverse(&ab->stack_b, 'b');
	if (!p_a)
		push_n_times(ab, begin, 'a', 3);
	if (p_a && find_node(ab->stack_a, get_value(*begin)))
		push_n_times(ab, &ab->stack_b, 'a', 3);
	else if (p_a)
		push_n_times(ab, &ab->stack_b, 'a', 3);
	return (3);
}

int		sort_stack_under_3(t_stacks *ab, t_dlist **begin, t_dlist *end, int p_a)
{
	if (size_stack(*begin, end) == 3)
		return (sort_stack_under_3_pre(ab, begin, p_a));
	else if (size_stack(*begin, end) == 2)
	{
		sort_stack_2_reverse(begin, p_a, 'a', 'b');
		if (!find_node(ab->stack_a, get_value(*begin)))
		{
			if (p_a)
				push_n_times(ab, begin, 'a', 2);
			else
				push_n_times(ab, begin, 'b', 2);
		}
		return (2);
	}
	else if (size_stack(*begin, end) == 1)
	{
		if (p_a)
			pa(ab, begin);
		else
			pb(ab, begin);
		return (1);
	}
	return (0);
}
