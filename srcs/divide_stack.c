/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:58:07 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 14:37:28 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_on_a(t_stacks *ab, t_dlist **stack, int value, t_norm *be)
{
	if (get_value(*stack) > value)
	{
		if (!*be->begin)
			*be->begin = *stack;
		if (get_value(*stack) != value)
			*be->end = *stack;
		ra(ab);
		*stack = (*stack)->next;
		return (1);
	}
	else if (get_value(*stack) == value)
	{
		pb(ab, stack);
		rb(ab);
	}
	else
		pb(ab, stack);
	return (0);
}

int	push_on_b(t_stacks *ab, t_dlist **stack, int value, t_norm *be)
{
	if (get_value(*stack) < value)
	{
		rb(ab);
		*stack = (*stack)->next;
	}
	else if (get_value(*stack) == value)
	{
		pa(ab, stack);
		ra(ab);
	}
	else
	{
		if (!*be->end)
			*be->end = *stack;
		*be->begin = *stack;
		pa(ab, stack);
	}
	return (0);
}

/**
 * If the number is biger then value, puts it at 
 * the *be->end of the current stack, otherwise push it on the other stack
 * @param ab	pointer on the struct tu coco
 * @param stack	current node (on which the loop iterates)
 * @param value	median pivot value
 **/
int	divide_stack(t_stacks *ab, t_dlist **st, int value, t_norm *be)
{
	if (find_node(ab->stack_a, get_value(*st)))
		return (push_on_a(ab, st, value, be));
	else
		return (push_on_b(ab, st, value, be));
}
