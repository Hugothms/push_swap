/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:14 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 14:50:58 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void function()
{
	
}

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them. 
 * The algo used is kind of a quick sort modified to work with 2 stacks
 * @param ab		pointer on the struct tu coco
 * @param begin		start of the stack to sort
 * @param end		end of the stack to sort
 * @param p_a	change the comparaison in divide_stack
 **/
int	sort_quick(t_stacks *ab, t_dlist *begin, t_dlist *end, int p_a)
{
	t_dlist	*median;
	t_dlist	*tmp;
	int		i;

	if (!ab || !begin || !end)
		return (0);
	if (p_a)
	{
		begin = find_node(ab->stack_b, get_value(begin));
		end = find_node(ab->stack_b, get_value(end));
	}
	else
	{
		begin = find_node(ab->stack_a, get_value(begin));
		end = find_node(ab->stack_a, get_value(end));
	}
	if (size_stack(begin, end) <= 3)
		return (sort_stack_under_3(ab, &begin, end, p_a));
	median = find_median(begin, end);
	if (!median)
		return (0);
	tmp = begin;
	i = size_stack(begin, end);
	begin = NULL;
	end = NULL;
	int	later;
	t_norm *be;

	later = 0;
	be = malloc(sizeof(*be));
	be->begin = &begin;
	be->end = &end;
	while (i--)
		later += divide_stack(ab, &tmp, get_value(median), be);
	if (p_a)
		rra(ab);
	else
		rrb(ab);
	while (later--)
	{
		reverse(&ab->stack_a);
		printf("rr%c\n", 'a');
	}
	int	cpt;
	cpt = 0;
	if (ab->stack_b)
		cpt = sort_quick(ab, ab->stack_b, ab->stack_b->prev, ft_dlstsize(ab->stack_b));
	while (cpt--)
		ra(ab);
	if (begin != ab->stack_a)
		ra(ab);
	if (ab->stack_a)
		cpt = sort_quick(ab, begin, end, ft_dlstsize(ab->stack_b));
	while (cpt--)
		ra(ab);
	return (0);
}

/** ALGO QUICK SORT
 * 	if size 2 or 3
 * 		sort + push on a if needed
 * 		return
 * 	find median node
 * 	if (on stack a):
 * 		put lowers than median on stack b and median at the end of stack (with rb after pb)
 * 		then rrb to put the median at the rigth place
 * 	else:
 * 		put biggers than median on stack a and median at the end of stack (with ra after pa)
 * 		then rra to put the median at the rigth place
 * 
 * 	recursion on lowers (stack to median)
 * 	recursion on biggers (stack from median)
 * 	push on current stack all nodes from other stack (smallers)
 * 	(median is now in place)
 * DONE
 **/
