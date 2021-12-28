/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_naif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:37:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/12/28 12:32:48 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ALGO NAIF
** tant que size list > 3
** 		trouver le plus petit node
** 		le mettre en haut de a
** 		le push sur b (pb)
** ensuite trier les 3 node restants
** remettre tout sur a (pa)
** DONE
*/
/*
** Find the position of the node in the stack
** @param stack	the stack containing node
** @param node	node to check the position
** @return		position of the given node
*/
int	pos_node(t_dlist *stack, t_dlist *node)
{
	t_dlist	*tmp;
	int		pos;

	if (stack == node)
		return (0);
	pos = 1;
	tmp = stack->next;
	while (tmp != stack && tmp != node)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

/*
** Check if the given node is in the first half of the stack
** @param stack	the stack containing node
** @param node	node to check the position
** @return		1 if node is in the first half, 0 otherwise
*/
int	is_in_first_half(t_dlist *stack, int pos)
{
	return (pos < (ft_dlstsize(stack) + 1) / 2);
}

/*
** Put an node at the top of the stack without changing the order of
** the other nodes
** @param stack	stack to modify
** @param node	node to put at the top
** @param name	name of the stack we are working on
*/
void	put_at_top(t_stacks *ab, t_dlist **stack, t_dlist *node, char name)
{
	int	pos;

	pos = pos_node(*stack, node);
	if (is_in_first_half(*stack, pos))
	{
		while (pos--)
		{
			if (name == 'a')
				ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("ra")));
			else
				ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rb")));
			rotate(stack);
		}
	}
	else
	{
		while (pos++ % ft_dlstsize(*stack))
		{
			if (name == 'a')
				ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rra")));
			else
				ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rrb")));
			reverse(stack);
		}
	}
}

/*
** Find and return the smallest node of the stack
** @param stack	stack where to find the smallest node
** @return		the smallest node found in the stack
*/
t_dlist	*find_smallest(t_dlist *stack)
{
	t_dlist	*tmp;
	t_dlist	*smallest;

	smallest = stack;
	tmp = stack->next;
	if (get_value(tmp) < get_value(smallest))
		smallest = tmp;
	while (tmp != stack)
	{
		if (get_value(tmp) < get_value(smallest))
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

/*
** Sort a stack with the help of a second stack using only the
** autorized operations and print them
** @param stack	pointer on the first node of the stack to sort
** @param name	name of the stack we are working on
*/
void	sort_naif(t_stacks *ab, t_dlist **stack, char name)
{
	t_dlist	*b;
	t_dlist	*smallest;

	b = NULL;
	while (ft_dlstsize(*stack) > 3)
	{
		smallest = find_smallest(*stack);
		put_at_top(ab, stack, smallest, name);
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("pb")));
		push(&b, stack);
	}
	sort_stack_3(ab, stack, name);
	sort_stack_2(ab, stack, name);
	while (ft_dlstsize(b))
	{
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("pa")));
		push(stack, &b);
	}
}
