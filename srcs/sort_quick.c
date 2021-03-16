/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:14 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/16 17:25:07 by hthomas          ###   ########.fr       */
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
	
	printf("text%d,%d\n", get_value(stack), max);
	if (!stack)
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
 * @param tmp	current node on which the loop iterates
 * @param value	pivot value (median)
 **/
void put_in_place(t_stacks *ab, t_dlist **tmp, int value, int parity)
{
	if (parity == 1)
	{
		if (get_value(*tmp) - value > 0)
		{
			*tmp = (*tmp)->next;
			rotate(&ab->stack_a);
			ft_printf("r%c\n", ab->name_a);
		}
		else
		{
			*tmp = (*tmp)->next;
			push(&ab->stack_b, &ab->stack_a);
			ab->size_b++;
			ab->size_a--;
			ft_printf("p%c\n", ab->name_b);
		}
	}
	else
	{
		if (get_value(*tmp) + value <= 0)
		{
			*tmp = (*tmp)->next;
			rotate(&ab->stack_a);
			ft_printf("r%c\n", ab->name_a);
		}
		else
		{
			*tmp = (*tmp)->next;
			push(&ab->stack_b, &ab->stack_a);
			ab->size_a++;
			ab->size_b--;
			ft_printf("p%c\n", ab->name_b);
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
 * @param ab	pointer on the struct tu coco
 **/
t_dlist	*sort_quick(t_stacks *ab, int size, int parity)
{
	t_dlist	*median;
	t_dlist	*tmp;

	printf("____________________________________\n");
	if (!ab->stack_a)
		return (NULL);
	if (!(median = find_median(ab->stack_a, size)))
		return (NULL);
	tmp = ab->stack_a;
	while (size--)
	{
		ft_putnbr(get_value(tmp));
		put_in_place(ab, &tmp, get_value(median), parity);
	}
	
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);

	put_at_top(&ab->stack_a , median, ab->name_a);
	while (ab->stack_b)
	{
		ft_putnbr(get_value(ab->stack_b));
		push(&ab->stack_a, &ab->stack_b);
		ab->size_a++;
		ab->size_b--;
		size++;
		ft_printf("p%c\n", ab->name_a);
	}
	// ft_putnbr(get_value(tmp));
	// put_in_place(ab, &tmp, get_value(median), - parity);
	
	
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);

	// swap_stacks(ab);
	sort_quick(ab, size, parity);

	// swap_stacks(ab);
	// sort_quick(ab, ab->size_a, parity);

	// put_at_top(ab->stack_a, median, ab->name_a);
	// push(other, ab->stack_a);
	// ft_putstr("pb\n");
	// ft_putstr("SUB-a\n");
	// sort_quick(ab->stack_a, ab->stack_a);
	// ft_putstr("SUB-other\n");
	// sort_quick(other, 'other');
	return (ab->stack_a);
}

/** ALGO QUICK SORT
 * tant que swap
 * 		trouver le node median
 * 		mettre les 50% plus petits noeuds sur l'autre stack (il reste les 50% 
 * 		plus grands sur la stack actuelle)
 * 		faire remonter le median
 * 		push sur la stack courrante tous les nodes de l'autre (les plus petits)
 * 		(le median se retrouve donc bien place et separe 2 parties)
 * recursion sur (stack jusqu'a median)
 * recursion sur (stack depuis median)
 * DONE
 **/
