/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:14 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/15 09:40:20 by hthomas          ###   ########.fr       */
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