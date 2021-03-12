/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:06:58 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/12 13:15:21 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_it(t_dlist **a, t_dlist **b, char *line, int *ret)
{
	*ret = 0;
	if (!ft_strcmp(line, "sa"))
		swap(a);
	else if (!ft_strcmp(line, "sb"))
		swap(b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(a);
		swap(b);
	}
	else
		*ret = 1;
}

void	push_it(t_dlist **a, t_dlist **b, char *line, int *ret)
{
	*ret = 0;
	if (!ft_strcmp(line, "pa"))
		push(a, b);
	else if (!ft_strcmp(line, "pb"))
		push(b, a);
	else
		*ret = 1;
}

void	rotate_it(t_dlist **a, t_dlist **b, char *line, int *ret)
{
	*ret = 0;
	if (!ft_strcmp(line, "ra"))
		rotate(a);
	else if (!ft_strcmp(line, "rb"))
		rotate(b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else
		*ret = 1;
}

void	reverse_it(t_dlist **a, t_dlist **b, char *line, int *ret)
{
	*ret = 0;
	if (!ft_strcmp(line, "rra"))
		reverse(a);
	else if (!ft_strcmp(line, "rrb"))
		reverse(b);
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse(a);
		reverse(b);
	}
	else
		*ret = 1;
}