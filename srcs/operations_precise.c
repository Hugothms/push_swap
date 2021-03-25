/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_precise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:03:12 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 17:19:36 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stacks *ab, t_dlist **stack)
{
	*stack = (*stack)->next;
	push(&ab->stack_b, &ab->stack_a);
	ft_dlstadd_back(&ab->operations, ft_dlstnew(ft_strdup("pb\n")));
}

void	pa(t_stacks *ab, t_dlist **stack)
{
	*stack = (*stack)->next;
	push(&ab->stack_a, &ab->stack_b);
	ft_dlstadd_back(&ab->operations, ft_dlstnew(ft_strdup("pa%c\n")));
}

void	ra(t_stacks *ab)
{
	rotate(&ab->stack_a);
	ft_dlstadd_back(&ab->operations, ft_dlstnew(ft_strdup("ra%c\n")));
}

void	rb(t_stacks *ab)
{
	rotate(&ab->stack_b);
	ft_dlstadd_back(&ab->operations, ft_dlstnew(ft_strdup("rb%c\n")));
}

void	rra(t_stacks *ab)
{
	reverse(&ab->stack_a);
	ft_dlstadd_back(&ab->operations, ft_dlstnew(ft_strdup("rra\n")));
}
