/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:14 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/18 12:57:42 by hthomas          ###   ########.fr       */
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
	
	ft_printf("start:%d\n", get_value(stack));
	ft_printf("size: %d\n", max);
	if (!stack || max < 0)
		return (NULL);
	tab = ft_dlst_to_tabn(stack, max);
	sort_int(tab, max);
	median_value = tab[(max - 1) / 2];
	free(tab);
	ft_printf("median_value:%d\n", median_value);
	return (find_node(stack, median_value));
}

int size_stack(t_dlist *begin, t_dlist *end)
{
	int		cpt;
	t_dlist	*tmp;

	cpt = 0;
	tmp = begin;
	if (!find_node(begin, get_value(end)))
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
	ft_printf("start:%d\n", get_value(stack));
	ft_printf("end: %d\n", get_value(end));
	ft_printf("size: %d\n", size);
	if (!stack || size < 0)
		return (NULL);
	tab = ft_dlst_to_tabn(stack, size);
	sort_int(tab, size);
	median_value = tab[(size - 1) / 2];
	free(tab);
	printf("%smedian_value:%d%s\n", RED, median_value, RESET);
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
 * @param value	median pivot value
 **/
void divide_stack(t_stacks *ab, t_dlist **stack, int value, int work_on_a)
{
	if (find_node(ab->stack_a, get_value(*stack)))
	{
		if (!work_on_a)
		{
			if (get_value(*stack) == value)
			{
				pb(ab, stack);
				rb(ab);
			}
			else if (get_value(*stack) > value)
			{
				ra(ab);
				*stack = (*stack)->next;
			}
			else
				pb(ab, stack);
		}
		else
		{
			if (get_value(*stack) < value)
			{
				ra(ab);
				*stack = (*stack)->next;
			}
			else
				pb(ab, stack);
		}
	}
	else
	{
		if (!work_on_a)
		{
			if (get_value(*stack) > value)
			{
				rb(ab);
				*stack = (*stack)->next;
			}
			else
				pa(ab, stack);
		}
		else
		{
			if (get_value(*stack) == value)
			{
				pa(ab, stack);
				ra(ab);
			}
			if (get_value(*stack) < value)
			{
				rb(ab);
				*stack = (*stack)->next;
			}
			else
				pa(ab, stack);
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

void under_3(t_stacks *ab, t_dlist *begin, t_dlist *end, int work_on_a)
{
	if (size_stack(begin, end) == 3)
	{
		ft_printf("SIZE = 3 CA DEGAGE\n");
		sort3(&begin, work_on_a ? 'a': 'b');
		if (work_on_a)
		{
			pa(ab, &begin);
			pa(ab, &begin);
			pa(ab, &begin);
			return ;
		}
		else
		{
			pb(ab, &begin);
			pb(ab, &begin);
			pb(ab, &begin);
			return ;
		}
	}
	else if (size_stack(begin, end) == 2)
	{
		ft_printf("SIZE = 2 CA DEGAGE\n");
		if (work_on_a)
		{
			rb(ab);
			pa(ab, &begin);
			pa(ab, &begin);
			return ;
		}
		else
		{
			ra(ab);
			pb(ab, &begin);
			pb(ab, &begin);
			return ;
		}
		return ;
	}
}

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them
 * The algo used is a kind of quick sort modified to work with 2 stacks
 * @param ab		pointer on the struct tu coco
 * @param begin		start of the stack to sort
 * @param end		end of the stack to sort
 * @param work_on_a	change the comparaison in divide_stack
 **/
t_dlist	*sort_quick_maintenance(t_stacks *ab, t_dlist *begin, t_dlist *end, int work_on_a)
{
	t_dlist	*median;
	t_dlist	*tmp;
	int		i;

	ft_printf("---------------------------------------\n");
	if (!ab || begin == end)
		return (NULL);
	under_3(ab, begin, end, work_on_a);	
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);
	if (!(median = find_median_maintenance(begin, end)))
		return (NULL);
	// work_on_a = ab->size_b;
	ft_printf("work_on_a:%d\n", work_on_a);
	tmp = begin;
	i = size_stack(begin, end);
	while (i--)
	{
		ft_printf("%d", get_value(tmp));
		divide_stack(ab, &tmp, get_value(median), work_on_a);
	}
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);
	if (work_on_a)
		rra(ab);
	else
		rrb(ab);
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);

	
	// swap_stacks(ab);
	work_on_a = ab->size_b;
	ft_printf("tmp = %d\n", get_value(tmp));
	ft_printf("prev= %d\n", get_value(tmp->prev));
	ft_printf("SUB-b\n");
	if (ab->stack_b)
		sort_quick_maintenance(ab, ab->stack_b, ab->stack_b->prev, work_on_a);
	else
		ft_printf("done-b\n");
	
	ft_printf("SUB-a\n");
	if (tmp)
		sort_quick_maintenance(ab, tmp, tmp->prev, work_on_a);
	else
		ft_printf("done-a\n");
	// ft_printf("SUB-b\n");
	// sort_quick(ab, ab->size_a, work_on_a);
	ft_printf("END FIRST PART\n");
	put_at_top(&ab->stack_b, find_node(ab->stack_b, get_value(median)), ab->name_b);

	i = size_stack(begin, end) / 2;
	// size = ab->size_b;
	while (i--)
	{
		ft_printf("%d", get_value(ab->stack_b));
		reverse(&ab->stack_a);
		ft_printf("rr%c\n", ab->name_a);
	}
	while (ab->stack_b)
	{
		ft_printf("%d", get_value(ab->stack_b));
		push(&ab->stack_a, &ab->stack_b);
		ab->size_a++;
		ab->size_b--;
		ft_printf("p%c\n", ab->name_a);
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
 * @param parity	change the comparaison in divide_stack
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
		divide_stack(ab, &tmp, get_value(median), parity);
	}
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);

	put_at_top(&ab->stack_b, find_node(ab->stack_b, get_value(median)), ab->name_b);
	
	ft_printf("SUB-a\n");
	sort_quick(ab, ab->size_a, parity);
	// swap_stacks(ab);
	// ft_printf("SUB-b\n");
	// sort_quick(ab, ab->size_a, parity);

	i = size / 2;
	size = ab->size_b;
	while (i--)
	{
		ft_printf("%d", get_value(ab->stack_b));
		reverse(&ab->stack_a);
		ft_printf("rr%c\n", ab->name_a);
	}
	while (ab->stack_b)
	{
		ft_printf("%d", get_value(ab->stack_b));
		push(&ab->stack_a, &ab->stack_b);
		ab->size_a++;
		ab->size_b--;
		ft_printf("p%c\n", ab->name_a);
	}
	print_dlist_line(ab->stack_a, ab->name_a);
	print_dlist_line(ab->stack_b, ab->name_b);
	return (ab->stack_a);
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
