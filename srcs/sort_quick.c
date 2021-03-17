/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:14 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/17 12:37:50 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*ft_dlst_to_tabn(t_dlist *dlst, int max)
{
	t_dlist	*tmp;
	int		*tab;
	int		i;

	if (!dlst)
		return (NULL);
	if (!(tab = malloc(sizeof(int) * max)))
		return (NULL);
	tab[0] = get_value(dlst);
	tmp = dlst->next;
	max--;
	i = 1;
	while (tmp != dlst && max--)
	{		
		tab[i] = get_value(tmp);
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

int		*ft_dlst_to_tab(t_dlist *dlst)
{
	t_dlist	*tmp;
	int		*tab;
	int		i;

	if (!dlst)
		return (NULL);
	if (!(tab = malloc(sizeof(int) * ft_dlstsize(dlst))))
		return (NULL);
	tab[0] = get_value(dlst);
	tmp = dlst->next;
	i = 1;
	while (tmp != dlst)
	{		
		tab[i] = get_value(tmp);
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

/**
 * Find the node with the corresponding value in the stack
 * @param stack	the stack containing node
 * @param value	value of the node we are looking for
 * @return		node with the corresponding value
 **/
t_dlist	*find_node(t_dlist *stack, int value)
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
t_dlist	*find_median(t_dlist *stack, int max)
{
	int		*tab;
	int		median_value;
	
	ft_printf("start:%d\nsize: %d\n", get_value(stack), max);
	if (!stack || max < 0)
		return (NULL);
	tab = ft_dlst_to_tabn(stack, max);
	sort_int(tab, max);
	median_value = tab[(max - 1) / 2];
	free(tab);
	ft_printf("median_value:%d\n", median_value);
	return (find_node(stack, median_value));
}

/**
 * Find and return the first found node smaller than a given number
 * @param stack	stack where to find the node
 * @param value	value max to accept a node
 * @return		the closest node (from the top or the bottom of stack)
 * 				smaller than value
 **/
t_dlist	*find_smaller_than(t_dlist *stack, int value)
{
	t_dlist	*start;
	t_dlist	*end;

	if (!stack)
		return (NULL);
	start = stack;
	end = stack->prev;
	if (get_value(start) < value)
			return (start);
	if (get_value(end) < value)
			return (end);
	while (start != stack)
	{
		if (get_value(start) < value)
			return (start);
		if (get_value(end) < value)
			return (end);
		start = start->next;
		end = end->prev;
	}
	return (NULL);
}

/**
 * If the number is biger then value, puts it at 
 * the end of the current stack, otherwise push it on the other stack
 * @param ab	pointer on the struct tu coco
 * @param stack	current node (on which the loop iterates)
 * @param value	pivot value (median)
 **/
void put_in_place(t_stacks *ab, t_dlist **stack, int value, int parity)
{
	if (parity == 1)
	{
		if (get_value(*stack) > value)
		{
			*stack = (*stack)->next;
			rotate(&ab->stack_a);
			ft_printf("%sr%c%s\n", BLU, ab->name_a, RESET);
		}
		else
		{
			*stack = (*stack)->next;
			push(&ab->stack_b, &ab->stack_a);
			ab->size_b++;
			ab->size_a--;
			ft_printf("%sp%c%s\n", BLU, ab->name_b, RESET);
		}
	}
	else
	{
		if (get_value(*stack) < value)
		{
			*stack = (*stack)->next;
			rotate(&ab->stack_a);
			ft_printf("%sr%c%s\n", BLU, ab->name_a, RESET);
		}
		else
		{
			*stack = (*stack)->next;
			push(&ab->stack_b, &ab->stack_a);
			ab->size_a++;
			ab->size_b--;
			ft_printf("%sp%c%s\n", BLU, ab->name_b, RESET);
		}
	}
}

void	swap_stacks(t_stacks *ab)
{
	t_dlist *swap = ab->stack_a;
	ab->stack_a = ab->stack_b;
	ab->stack_b = swap;
	char c = ab->name_a;
	ab->name_a = ab->name_b;
	ab->name_b = c;
	int s = ab->size_a;
	ab->size_a = ab->size_b;
	ab->size_b = s;
}

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them
 * The algo used is a kind of quick sort modified to work with 2 stacks
 * @param ab		pointer on the struct tu coco
 * @param size		max number of nodes to iterate on the stack a
 * @param size_b	change the comparaison in put_in_place
 **/
t_dlist	*sort_quick_maintenance(t_stacks *ab, int size, int size_b)
{
	t_dlist	*median;
	t_dlist	*tmp;
	int		i;

	ft_printf("____________________________________\n");
	if (!ab->stack_a || size < 1)
		return (NULL);
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);
	if (!(median = find_median(ab->stack_a, size)))
		return (NULL);
	if (size_b)
		tmp = ab->stack_b;
	else
		tmp = ab->stack_a;
	i = size;
	while (i--)
	{
		ft_printf("%d", get_value(tmp));
		put_in_place(ab, &tmp, get_value(median), ft_dlstsize(ab->stack_b));
	}
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);

	
	ft_putstr("SUB-a\n");
	sort_quick(ab, ab->size_a, ft_dlstsize(ab->stack_b));
	// swap_stacks(ab);
	// ft_putstr("SUB-b\n");
	// sort_quick(ab, ab->size_a, size_b);

	put_at_top(&ab->stack_b, find_node(ab->stack_b, get_value(median)), ab->name_b);

	i = size / 2;
	size = ab->size_b;
	while (i--)
	{
		ft_printf("%d", get_value(ab->stack_b));
		reverse(&ab->stack_a);
		ft_printf("%srr%c%s\n", MAG, ab->name_a, RESET);
	}
	while (ab->stack_b)
	{
		ft_printf("%d", get_value(ab->stack_b));
		push(&ab->stack_a, &ab->stack_b);
		ab->size_a++;
		ab->size_b--;
		ft_printf("%sp%c%s\n", MAG, ab->name_a, RESET);
	}
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);
	return (ab->stack_a);
}

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them
 * The algo used is a kind of quick sort modified to work with 2 stacks
 * @param ab		pointer on the struct tu coco
 * @param size		max number of nodes to iterate on the stack a
 * @param parity	change the comparaison in put_in_place
 **/
t_dlist	*sort_quick(t_stacks *ab, int size, int parity)
{
	t_dlist	*median;
	t_dlist	*tmp;
	int		i;

	ft_printf("____________________________________\n");
	if (!ab->stack_a || size < 1)
		return (NULL);
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);
	if (!(median = find_median(ab->stack_a, size)))
		return (NULL);
	tmp = ab->stack_a;
	i = size;
	while (i--)
	{
		ft_printf("%d", get_value(tmp));
		put_in_place(ab, &tmp, get_value(median), parity);
	}
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);

	put_at_top(&ab->stack_b, find_node(ab->stack_b, get_value(median)), ab->name_b);
	
	ft_putstr("SUB-a\n");
	sort_quick(ab, ab->size_a, parity);
	// swap_stacks(ab);
	// ft_putstr("SUB-b\n");
	// sort_quick(ab, ab->size_a, parity);

	i = size / 2;
	size = ab->size_b;
	while (i--)
	{
		ft_printf("%d", get_value(ab->stack_b));
		reverse(&ab->stack_a);
		ft_printf("%srr%c%s\n", MAG, ab->name_a, RESET);
	}
	while (ab->stack_b)
	{
		ft_printf("%d", get_value(ab->stack_b));
		push(&ab->stack_a, &ab->stack_b);
		ab->size_a++;
		ab->size_b--;
		ft_printf("%sp%c%s\n", MAG, ab->name_a, RESET);
	}
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);
	return (ab->stack_a);
}

/** ALGO QUICK SORT
 * tant que swap
 * 		trouver le node median
 * 		mettre les 50% plus petits noeuds sur l'autre stack (il reste les 50% 
 * 		plus grands sur la stack actuelle)
 * 		recursion sur (stack jusqu'a median)
 * 		recursion sur (stack depuis median)
 * 		faire remonter le median
 * 		push sur la stack courrante tous les nodes de l'autre (les plus petits)
 * 		(le median se retrouve donc bien place et separe 2 parties)
 * DONE
 **/
