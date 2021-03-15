/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:14 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/15 10:38:38 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** ALGO QUICK SORT
 * tant que le dernier node n'est pas atteint
 * 		trouver le node median
 * 		mettre les 50% plus petits noeuds sur l'autre stack (il reste les 50% plus grands sur la stack actuelle)
 * 		mettre le mediant au milieu (quelle stack ?)
 * recursion sur (stack jusqu'a median)
 * recursion sur (stack depuis median)
 * DONE
 **/









int		*ft_dlst_to_tab(t_dlist *dlst)
{
	t_dlist	*tmp;
	int		*tab;
	int		i;

	if (!dlst)
		return (NULL);
	if (!(tab = malloc(sizeof(int) * ft_dlstsize(dlst))))
		return (NULL);
	i = 0;
	tab[i] = get_value(dlst);
	tmp = dlst->next;
	while (tmp != dlst)
	{		
		tab[i] = get_value(tmp);
		tmp = tmp->next;
	}
	return (tab);
}

/**
 * Find the node with the corresponding value in the stack
 * @param stack	the stack containing node
 * @param value	value of the node we are looking for
 * @return		node with the corresponding value
 **/
t_dlist	*c(t_dlist *stack, int value)
{
	t_dlist	*tmp;
	
	if (get_value(stack) == value)
		return (stack);
	tmp = stack->next;
	while (tmp != stack)
	{
		if (get_value(tmp) == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * Find and return median node (relative to the value) in the given stack
 * @param stack	stack where to find the node
 * @return		the median node
 **/
t_dlist	*find_median(t_dlist *stack)
{
	int		*tab;
	int		size;
	int		median_value;
	t_dlist	*median;
	
	size = ft_dlstsize(stack);
	tab = ft_dlst_to_tab(stack);
	sort_int(tab, size);
	median_value = tab[size / 2];
	return (NULL);
}

/**
 * Find and return the first found node smaller (or equal) than a given number
 * @param stack	stack where to find the node
 * @param value	value max to accept a node
 * @return		the closest node (from the top or the bottom of stack)
 * 				smaller (or equal) than value
 **/
t_dlist	*find_smaller_than(t_dlist *stack, int value)
{
	t_dlist	*start;
	t_dlist	*end;

	start = stack->next;
	end = stack->prev;
	if (get_value(start) <= value)
			return (start);
	if (get_value(end) <= value)
			return (end);
	while (start != stack)
	{
		if (get_value(start) <= value)
			return (start);
		if (get_value(end) <= value)
			return (end);
		start = start->next;
		start = start->prev;
	}
	return (NULL);
}

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them
 * @param stack	pointer on the first node of the stack to sort
 **/
void	sort_quick(t_dlist **stack, char name)
{
	t_dlist	*b;
	t_dlist	*tmp;

	b = NULL;
	(void)name;
	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		push(&b, stack);
	}
	
}
