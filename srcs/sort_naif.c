/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_naif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:37:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/19 11:56:58 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** ALGO NAIF
 * tant que size list > 3
 * 		trouver le plus petit node
 * 		le mettre en haut de a
 * 		le push sur b (pb)
 * ensuite trier les 3 node restants
 * remettre tout sur a (pa)
 * DONE
 **/

/**
 * Sort a stack of 3 node with the smallest number of instructions possible
 * @param stack	stack of size 3 to sort
 * @param name	name of the stack we are working on
 **/
void	sort_stack_size_2(t_dlist **st, char name)
{
	if (ft_dlstsize((*st)) != 2 || !checker((*st)))
		return ;
	swap(st);
	ft_printf("s%c\n", name);
}

/**
 * Sort a stack of 3 node with the smallest number of instructions possible
 * @param stack	stack of size 3 to sort
 * @param name	name of the stack we are working on
 **/
void	sort_stack_size_3(t_dlist **st, char name)
{
	if (ft_dlstsize((*st)) != 3 || !checker((*st)))
		return ;
	if (get_value((*st))					> get_value((*st)->next) &&
			get_value((*st)->next)			< get_value((*st)->next->next) &&
			get_value((*st)->next->next)	> get_value((*st)))
		sort1(st, name);
	else if (get_value((*st))				> get_value((*st)->next) &&
			get_value((*st)->next)			> get_value((*st)->next->next) &&
			get_value((*st)->next->next)	< get_value((*st)))
		sort2(st, name);
	else if (get_value((*st))				> get_value((*st)->next) &&
			get_value((*st)->next)			< get_value((*st)->next->next) &&
			get_value((*st)->next->next)	< get_value((*st)))
		sort3(st, name);
	else if (get_value((*st))				< get_value((*st)->next) &&
			get_value((*st)->next)			> get_value((*st)->next->next) &&
			get_value((*st)->next->next)	> get_value((*st)))
		sort4(st, name);
	else if (get_value((*st))				< get_value((*st)->next) &&
			get_value((*st)->next)			> get_value((*st)->next->next) &&
			get_value((*st)->next->next)	< get_value((*st)))
		sort5(st, name);
}

/**
 * Find the position of the node in the stack
 * @param stack	the stack containing node
 * @param node	node to check the position
 * @return		position of the given node
 **/
int		pos_node(t_dlist *stack, t_dlist *node)
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

/**
 * Check if the given node is in the first half of the stack
 * @param stack	the stack containing node
 * @param node	node to check the position
 * @return		1 if node is in the first half, 0 otherwise
 **/
int		is_in_first_half(t_dlist *stack, int pos)
{
	return (pos < (ft_dlstsize(stack) + 1) / 2);
}

/**
 * Put an node at the top of the stack without changing the order of 
 * the other nodes
 * @param stack	stack to modify
 * @param node	node to put at the top
 * @param name	name of the stack we are working on
 **/
void	put_at_top(t_dlist **stack, t_dlist *node, char name)
{
	int	pos;
	int	top;

	pos = pos_node(*stack, node);
	// if (pos >= ft_dlstsize(*stack))
	// 	ft_printf("Ca va pas chef\n");
	// ft_printf("node:%d is at pos:%d\n", get_value(node), pos);
	top = is_in_first_half(*stack, pos);
	if (top)
	{
		while (pos--)
		{
			ft_printf("r%c\n", name);
			rotate(stack);
		}
	}
	else
	{
		while (pos++ % ft_dlstsize(*stack))
		{
			ft_printf("rr%c\n", name);
			reverse(stack);
		}
	}
}

/**
 * Find and return the smallest node of the stack 
 * @param stack	stack where to find the smallest node
 * @return		the smallest node found in the stack
 **/
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

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them
 * @param stack	pointer on the first node of the stack to sort
 * @param name	name of the stack we are working on
 **/
void	sort_naif(t_dlist **stack, char name)
{
	t_dlist	*b;
	b = NULL;

	while (ft_dlstsize(*stack) > 3)
	{		
		t_dlist *smallest = find_smallest(*stack);
		// print_dlist_line(*stack, 'a');
		// ft_printf("smallest Node:\nstack[%d]", pos_node(*stack, smallest));
		// ft_printf("=%d\n", get_value(smallest));
		// ft_printf("size:%d ", ft_dlstsize(*stack));
		// ft_printf("%s\n", is_in_first_half(*stack, pos_node(*stack, smallest)) ? "top" : "bottom");
	
		put_at_top(stack, smallest, name);
		ft_printf("pb\n");
		push(&b, stack);
	}
	sort_stack_size_3(stack, name);
	while(ft_dlstsize(b))
	{
		ft_printf("pa\n");
		push(stack, &b);
	}
}
