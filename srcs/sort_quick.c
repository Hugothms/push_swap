/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:14 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 11:41:34 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Sort a stack of 3 node with the smallest number of instructions possible
 * @param stack	stack of size 3 to sort
 * @param name	name of the stack we are working on
 **/
void	sort_stack_2_reverse(t_dlist **st, int p_a, char n_a, char n_b)
{
	if (!p_a && get_value(*st) > get_value((*st)->next))
	{
		swap(st);
		printf("s%c\n", n_a);
	}
	else if (p_a && get_value(*st) < get_value((*st)->next))
	{
		swap(st);
		printf("s%c\n", n_b);
	}
}

/**
 * Sort a stack of 3 node with the smallest number of instructions possible
 * @param stack	stack of size 3 to sort
 * @param name	name of the stack we are working on
 **/
void	sort_stack_3_reverse(t_dlist **st, char name)
{
	if (ft_dlstsize((*st)) != 3)
		return ;
	if (get_value((*st)) > get_value((*st)->next)
		&& get_value((*st)->next) < get_value((*st)->next->next)
		&& get_value((*st)->next->next) > get_value((*st)))
		sort5(st, name);
	else if (get_value((*st)) < get_value((*st)->next)
		&& get_value((*st)->next) < get_value((*st)->next->next)
		&& get_value((*st)->next->next) > get_value((*st)))
		sort2(st, name);
	else if (get_value((*st)) > get_value((*st)->next)
		&& get_value((*st)->next) < get_value((*st)->next->next)
		&& get_value((*st)->next->next) < get_value((*st)))
		sort4(st, name);
	else if (get_value((*st)) < get_value((*st)->next)
		&& get_value((*st)->next) > get_value((*st)->next->next)
		&& get_value((*st)->next->next) > get_value((*st)))
		sort3(st, name);
	else if (get_value((*st)) < get_value((*st)->next)
		&& get_value((*st)->next) > get_value((*st)->next->next)
		&& get_value((*st)->next->next) < get_value((*st)))
		sort1(st, name);
}

int	*ft_dlst_to_tabn(t_dlist *dlst, int max)
{
	t_dlist	*tmp;
	int		*tab;
	int		i;

	if (!dlst)
		return (NULL);
	tab = malloc(sizeof(int) * max);
	if (!tab)
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

/**
 * Find the node with the corresponding value in the stack
 * @param stack	the stack containing node
 * @param value	value of the node we are looking for
 * @return		node with the corresponding value
 **/
t_dlist	*find_node(t_dlist *stack, int value)
{
	t_dlist	*tmp;

	if (!stack)
		return (NULL);
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

	if (!stack || max < 0)
		return (NULL);
	tab = ft_dlst_to_tabn(stack, max);
	sort_int(tab, max);
	median_value = tab[(max - 1) / 2];
	free(tab);
	return (find_node(stack, median_value));
}

int	size_stack(t_dlist *begin, t_dlist *end)
{
	int		cpt;
	t_dlist	*tmp;

	cpt = 0;
	tmp = begin;
	if (!begin || !end || !find_node(begin, get_value(end)))
		return (0);
	while (tmp != end)
	{
		cpt++;
		tmp = tmp->next;
	}
	return (cpt + 1);
}

/**
 * Find and return median node (relative to the value) in the given stack
 * @param stack	stack where to find the node
 * @return		the median node
 **/
t_dlist	*find_median_maintenance(t_dlist *stack, t_dlist *end)
{
	int		*tab;
	int		median_value;
	int		size;

	size = size_stack(stack, end);
	if (!stack || size < 0)
		return (NULL);
	tab = ft_dlst_to_tabn(stack, size);
	sort_int(tab, size);
	median_value = tab[(size - 1) / 2];
	free(tab);
	return (find_node(stack, median_value));
}

/**
 * If the number is biger then value, puts it at 
 * the end of the current stack, otherwise push it on the other stack
 * @param ab	pointer on the struct tu coco
 * @param stack	current node (on which the loop iterates)
 * @param value	median pivot value
 **/
int	divide_stack(t_stacks *ab, t_dlist **stack, int value, int p_a, t_dlist **begin, t_dlist **end)
{
	if (find_node(ab->stack_a, get_value(*stack)))
	{
		if (p_a)
		{
			if (get_value(*stack) < value)
			{
				if (!*begin)
					*begin = *stack;
				if (get_value(*stack) != value)
					*end = *stack;
				ra(ab);
				*stack = (*stack)->next;
				return (1);
			}
			else
			{
				pb(ab, stack);
				return (0);
			}
		}
		else
		{
			if (get_value(*stack) == value)
			{
				pb(ab, stack);
				rb(ab);
				return (0);
			}
			else if (get_value(*stack) > value)
			{
				if (!*begin)
					*begin = *stack;
				if (get_value(*stack) != value)
					*end = *stack;
				ra(ab);
				*stack = (*stack)->next;
				return (1);
			}
			else
			{
				pb(ab, stack);
				return (0);
			}
		}
	}
	else
	{
		if (p_a)
		{
			if (get_value(*stack) == value)
			{
				pa(ab, stack);
				ra(ab);
				return (0);
			}
			else if (get_value(*stack) < value)
			{
				rb(ab);
				*stack = (*stack)->next;
				return (0);
			}
			else
			{
				if (!*end)
					*end = *stack;
				*begin = *stack;
				pa(ab, stack);
				return (0);
			}
		}
		else
		{
			if (get_value(*stack) > value)
			{
				rb(ab);
				*stack = (*stack)->next;
				return (0);
			}
			else
			{
				if (!*end)
					*end = *stack;
				*begin = *stack;
				pa(ab, stack);
				return (0);
			}
		}
	}
}

void	push_n_times(t_stacks *ab, t_dlist **begin, char c, int n)
{
	while (n--)
	{
		if (c == 'a')
			pa(ab, begin);
		else
			pb(ab, begin);
	}
}

int	sort_stack_under_3_pre(t_stacks *ab, t_dlist **begin, int p_a)
{
	if (!p_a)
		push_n_times(ab, begin, 'b', 3);
	sort_stack_3_reverse(&ab->stack_b, 'b');
	if (!p_a)
		push_n_times(ab, begin, 'a', 3);
	if (p_a && find_node(ab->stack_a, get_value(*begin)))
		push_n_times(ab, &ab->stack_b, 'a', 3);
	else if (p_a)
		push_n_times(ab, &ab->stack_b, 'a', 3);
	return (3);
}

int	sort_stack_under_3(t_stacks *ab, t_dlist **begin, t_dlist *end, int p_a)
{
	if (size_stack(*begin, end) == 3)
		return (sort_stack_under_3_pre(ab , begin, p_a));
	else if (size_stack(*begin, end) == 2)
	{
		sort_stack_2_reverse(begin, p_a, 'a', 'b');
		if (!find_node(ab->stack_a, get_value(*begin)))
		{
			if (p_a)
				push_n_times(ab, begin, 'a', 2);
			else
				push_n_times(ab, begin, 'b', 2);
		}
		return (2);
	}
	else if (size_stack(*begin, end) == 1)
	{
		if (p_a)
			pa(ab, begin);
		else
			pb(ab, begin);
		return (1);
	}
	return (0);
}

int	first_is_smaller_in_stack_n(t_dlist *stack, int size)
{
	t_dlist *tmp;

	tmp = stack;
	while (size-- && tmp != stack)
	{
		if (get_value(tmp) < get_value(stack))
			return (1);
		tmp = tmp->next;
	}
	return (0);	
}

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them
 * The algo used is a kind of quick sort modified to work with 2 stacks
 * @param ab		pointer on the struct tu coco
 * @param begin		start of the stack to sort
 * @param end		end of the stack to sort
 * @param p_a	change the comparaison in divide_stack
 **/
int	sort_quick_maintenance(t_stacks *ab, t_dlist *begin, t_dlist *end, int p_a)
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
	median = find_median_maintenance(begin, end);
	if (!median)
		return (0);
	tmp = begin;
	i = size_stack(begin, end);
	begin = NULL;
	end = NULL;
	int	later;
	later = 0;
	while (i--)
		later += divide_stack(ab, &tmp, get_value(median), p_a, &begin, &end);
	if (p_a)
		rra(ab);
	else
		rrb(ab);
	while (later--)
	{
		reverse(&ab->stack_a);
		printf("rr%c\n", ab->name_a);
	}
	int	cpt;
	cpt = 0;
	p_a = ab->size_b;
	if (ab->stack_b)
		cpt = sort_quick_maintenance(ab, ab->stack_b, ab->stack_b->prev, ab->size_b);
	while (cpt--)
		ra(ab);
	if (begin != ab->stack_a)
		ra(ab);
	if (ab->stack_a)
		cpt = sort_quick_maintenance(ab, begin, end, ab->size_b);
	while (cpt--)
		ra(ab);
	return (0);
}

/** ALGO QUICK SORT
 * tant que swap
 * 		si size == 2 ou 3
 * 			tri + push sur lautre
 * 			return
 * 		trouver le node median
 * 
 * 		si (sur stack a):
 * 			mettre les inferieurs au median sur la stack b en mettant
 * 			le median au fond de la stack (rb)
 * 			puis rrb
 * 		sinon:
 * 			mettre les superieurs au median sur la stack a en mettant
 * 			le median au fond de la stack (ra)
 * 			puis rra
 * 
 * 		recursion sur inf (stack jusqu'a median)
 * 		recursion sur sup (stack depuis median)
 
 * 		faire remonter le median
 * 		push sur la stack courrante tous les nodes de l'autre (les plus petits)
 * 		(le median se retrouve donc bien place et separe 2 parties)
 * DONE
 **/
