/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/13 11:21:57 by hthomas          ###   ########.fr       */
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
// void	sort_3(t_dlist *stack)
// {

// }

/**
 * Check if the given node is in the first half of the stack
 * @param stack	the stack containing node
 * @param node	node to check the position
 * @return		1 if node is in the first half, 0 otherwise
 **/
int		first_half(t_dlist *stack, t_dlist *node)
{
	t_dlist	*tmp;
	int		half;
	int		pos;
	
	half = (ft_dlstsize(stack) + 1) / 2;
	pos = 0;
	tmp = stack;
	if (tmp == node)
		return (1);
	while (pos < half)
	{
		if (tmp == node)
			return (1);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

/**
 * Put an node at the top of the stack without changing the order of 
 * the other nodes
 * @param stack	stack to modify
 * @param node	node to put at the top
 **/
// void	put_at_top(t_dlist *stack, t_dlist *node)
// {
	
	
// }

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
// void	sort(t_dlist **stack)
// {
// 	t_dlist	*b;

// 	while (ft_dlstsize(*list) > 3)
// 	{
// 		put_at_top(*list, find_smaller(*list));
// 		ft_printf("pb\n");
// 		push(&b, list);
// 	}
// 	sort_3(*list);
// 	while(ft_dlstsize(b))
// 	{
// 		ft_printf("pa\n");
// 		push(list, &b);
// 	}
// }

int		main(int argc, char const *argv[])
{
	// (void)argc;
	// (void)argv;
	
	t_dlist	*a;
	
	if (argc == 1)
		return (0);
	if (!(a = scan_input(argc, argv)))
		error();
	print_dlist_line("a", a);

	// t_dlist	*b=NULL;
	// int		*num;
	// t_dlist	*tmp;
	// num = malloc(sizeof(int));
	// *num = -1;
	// ft_dlstadd_back(&b, (ft_dlstnew(num)));

	// num = malloc(sizeof(int));
	// *num = 4;
	// ft_dlstadd_back(&b, (tmp = ft_dlstnew(num)));

	// num = malloc(sizeof(int));
	// *num = 4;
	// ft_dlstadd_back(&b, (ft_dlstnew(num)));

	// num = malloc(sizeof(int));
	// *num = 45;
	// ft_dlstadd_back(&b, (ft_dlstnew(num)));

	// print_dlist_line("b", b);
	// printf("node:%d is in fisrt half ?%d\n", get_value(tmp), first_half(b, tmp));
	
	
	// sort(&a);
	return (0);
}
