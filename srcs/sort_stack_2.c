/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:06:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/12/29 22:10:20 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Sort a stack of 3 node with the smallest number of instructions possible
* @param stack	stack of size 2 to sort
* @param name	name of the stack we are working on
*/
void	sort_stack_2(t_stacks *ab, t_dlist **st, char name)
{
	if (ft_dlstsize((*st)) != 2 || !checker((*st)))
		return ;
	swap(st);
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sa")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sb")));
}

/*
* Sort a stack of 3 node with the smallest number of instructions possible
* @param stack	stack of size 2 to sort
* @param n_a	name of stack a
* @param n_b	name of stack b
*/
void	sort_stack_2_reverse(t_stacks *ab, t_dlist **st, int p_a)
{
	if (!p_a && get_value(*st) > get_value((*st)->next))
	{
		swap(st);
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sa")));
	}
	else if (p_a && get_value(*st) < get_value((*st)->next))
	{
		swap(st);
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sb")));
	}
}
