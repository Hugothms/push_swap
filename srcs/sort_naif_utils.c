/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_naif_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:43:36 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 17:24:39 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort1(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sa%c\n")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sb\n")));
	swap(stack);
}

void	sort2(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sa%c\n")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sb\n")));
	swap(stack);
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rra\n")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rrb\n")));
	reverse(stack);
}

void	sort3(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("ra%c\n")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rb\n")));
	rotate(stack);
}

void	sort4(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sa%c\n")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("sb\n")));
	swap(stack);
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("ra%c\n")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rb\n")));
	rotate(stack);
}

void	sort5(t_stacks *ab, t_dlist **stack, char name)
{
	if (name == 'a')
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rra\n")));
	else
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rrb\n")));
	reverse(stack);
}
