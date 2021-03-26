/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_naif_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:43:36 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/26 11:09:08 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort1(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sa")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sb")));
	swap(stack);
}

void	sort2(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sa")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sb")));
	swap(stack);
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rra")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rrb")));
	reverse(stack);
}

void	sort3(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("ra")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rb")));
	rotate(stack);
}

void	sort4(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sa")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sb")));
	swap(stack);
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("ra")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rb")));
	rotate(stack);
}

void	sort5(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rra")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rrb")));
	reverse(stack);
}
