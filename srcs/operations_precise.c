/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_precise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:03:12 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 14:50:58 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stacks *ab, t_dlist **stack)
{
	*stack = (*stack)->next;
	push(&ab->stack_b, &ab->stack_a);
	printf("p%c\n", 'b');
}

void	pa(t_stacks *ab, t_dlist **stack)
{
	*stack = (*stack)->next;
	push(&ab->stack_a, &ab->stack_b);
	printf("p%c\n", 'a');
}

void	ra(t_stacks *ab)
{
	rotate(&ab->stack_a);
	printf("r%c\n", 'a');
}

void	rb(t_stacks *ab)
{
	rotate(&ab->stack_b);
	printf("r%c\n", 'b');
}

void	rra(t_stacks *ab)
{
	reverse(&ab->stack_a);
	printf("rr%c\n", 'a');
}
