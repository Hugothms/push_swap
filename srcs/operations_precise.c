/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_precise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:03:12 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/18 11:24:43 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stacks *ab, t_dlist **stack)
{
	*stack = (*stack)->next;
	push(&ab->stack_b, &ab->stack_a);
	ab->size_b++;
	ab->size_a--;
	ft_printf("p%c\n", ab->name_b);
}

void	pa(t_stacks *ab, t_dlist **stack)
{
	*stack = (*stack)->next;
	push(&ab->stack_a, &ab->stack_b);
	ab->size_a++;
	ab->size_b--;
	ft_printf("p%c\n", ab->name_a);
}

void	ra(t_stacks *ab)
{
	rotate(&ab->stack_a);
	ft_printf("r%c\n", ab->name_a);
}

void	rb(t_stacks *ab)
{
	rotate(&ab->stack_b);
	ft_printf("r%c\n", ab->name_b);
}

void	rra(t_stacks *ab)
{
	reverse(&ab->stack_a);
	ft_printf("rr%c\n", ab->name_a);
}

void	rrb(t_stacks *ab)
{
	reverse(&ab->stack_b);
	ft_printf("rr%c\n", ab->name_b);
}
