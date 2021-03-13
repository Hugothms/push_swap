/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/13 13:54:05 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** ALGO
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
 **/
void	sort_stack_size_3(t_dlist *stack, char name)
{
	if (ft_dlstsize(stack) != 3 || checker(stack))
		return ;
	else if (get_value(stack)				> get_value(stack->next) &&
			get_value(stack->next)			< get_value(stack->next->next) &&
			get_value(stack->next->next)	> get_value(stack))
		sort1(stack, name);
	else if (get_value(stack)				> get_value(stack->next) &&
			get_value(stack->next)			> get_value(stack->next->next) &&
			get_value(stack->next->next)	< get_value(stack))
		sort2(stack, name);
	else if (get_value(stack)				> get_value(stack->next) &&
			get_value(stack->next)			< get_value(stack->next->next) &&
			get_value(stack->next->next)	< get_value(stack))
		sort3(stack, name);
	else if (get_value(stack)				< get_value(stack->next) &&
			get_value(stack->next)			> get_value(stack->next->next) &&
			get_value(stack->next->next)	> get_value(stack))
		sort4(stack, name);
	else if (get_value(stack)				< get_value(stack->next) &&
			get_value(stack->next)			> get_value(stack->next->next) &&
			get_value(stack->next->next)	< get_value(stack))
		sort5(stack, name);
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
int		first_half(t_dlist *stack, int pos)
{
	return (pos < (ft_dlstsize(stack) + 1) / 2);
}

/**
 * Put an node at the top of the stack without changing the order of 
 * the other nodes
 * @param stack	stack to modify
 * @param node	node to put at the top
 **/
void	put_at_top(t_dlist *stack, t_dlist *node, char name)
{
	int	pos;
	int	top;
	
	pos = pos_node(stack, node);
	// if (pos >= ft_dlstsize(stack))
	// 	ft_printf("Ca va paxs chef\n");
	// ft_printf("node:%d is at pos:%d\n", get_value(node), pos);
	top = first_half(stack, pos);
	if (top)
	{
		while (pos--)
		{
			ft_printf("r%c\n", name);
			rotate(&stack);
		}
	}
	else
	{
		while (pos--)
		{
			ft_printf("rr%c\n", name);
			reverse(&stack);
		}
	}		
}

/**
 * Find and return the smallest node of the stack 
 * @param stack	stack where to find the smallest node
 * @return		the smalest node found in the stack
 **/
t_dlist	*find_smaller(t_dlist *stack)
{
	t_dlist	*tmp;
	t_dlist	*smaller;

	smaller = stack;
	tmp = stack->next;
	if (get_value(tmp) < get_value(smaller))
			smaller = tmp;
	while (tmp != stack)
	{
		if (get_value(tmp) < get_value(smaller))
			smaller = tmp;
		tmp = tmp->next;
	}
	return (smaller);
}

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them
 * @param stack	pointer on the first node of the stack to sort
 **/
void	sort(t_dlist **stack, char name)
{
	t_dlist	*b;
	b = NULL;
	// int cpt = 0;
	while (ft_dlstsize(*stack) > 3)
	{		
		t_dlist *smaller = find_smaller(*stack);
		// print_dlist_line(*stack, 'a');
		// ft_printf("stack[%d]", pos_node(*stack, smaller));
		// ft_printf("=%d\n", get_value(smaller));
		// ft_printf("size:%d ", ft_dlstsize(*stack));
		// ft_printf("%s\n", first_half(*stack, pos_node(*stack, smaller)) ? "top" : "bottom");
	
		put_at_top(*stack, smaller, name);
		ft_printf("pb\n");
		push(&b, stack);
	}
	sort_stack_size_3(*stack, name);
	while(ft_dlstsize(b))
	{
		ft_printf("pa\n");
		push(stack, &b);
	}
}

int		main(int argc, char const *argv[])
{
	// (void)argc;
	// (void)argv;
	
	t_dlist	*a;
	
	if (argc == 1)
		return (0);
	if (!(a = scan_input(argc, argv)))
		error();
	// print_dlist_line(a, 'a');

	// t_dlist	*b=NULL;
	// int		*num;
	// t_dlist	*tmp;
	// num = malloc(sizeof(int));
	// *num = -1;
	// ft_dlstadd_back(&b, (ft_dlstnew(num)));

	// num = malloc(sizeof(int));
	// *num = 4;
	// ft_dlstadd_back(&b, (ft_dlstnew(num)));

	// num = malloc(sizeof(int));
	// *num = 8;
	// ft_dlstadd_back(&b, (ft_dlstnew(num)));

	// num = malloc(sizeof(int));
	// *num = 2;
	// ft_dlstadd_back(&b, (tmp = ft_dlstnew(num)));

	// print_dlist_line(b, 'b');
	// ft_printf("stack[%d]", pos_node(b, tmp));
	// ft_printf("=%d\n", get_value(tmp));
	// ft_printf("size:%d ", ft_dlstsize(b));
	// ft_printf("%s\n", first_half(b, pos_node(b, tmp)) ? "top" : "bottom");

	sort(&a, 'a');
	return (0);
}
