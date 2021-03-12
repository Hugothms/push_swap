/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/12 21:21:24 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** ALGO
 * tant que size list > 3
 * 		trouver le plus petit element
 * 		le mettre en haut de a
 * 		le push sur b (pb)
 * ensuite trier les 3 elem restants
 * remettre tout sur a (pa)
 * DONE
 **/

/**
 * Sort a stack of 3 element with the smallest number of instructions possible
 * @param list	stack of size 3 to sort
 **/
// void	sort_3(t_dlist *list)
// {

// }

/**
 * Check if the given element is in the first half of the stack
 * @param list	the stack containing elem
 * @param elem	element to check the position
 * @return		1 if elem is in the first half, 0 otherwie
 **/
int		first_half(t_dlist *list, t_dlist *elem)
{
	t_dlist	*tmp;
	int		half;
	int		pos;
	
	half = ft_dlstsize(list) / 2 + 1;
	pos = 0;
	tmp = list;
	if (tmp == elem)
	while (pos < half)
	{
		if (tmp == elem)
			return (1);
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

/**
 * Put an element at the top of the stack without changing the order of 
 * the other elements
 * @param list	stack to modify
 * @param elem	element to put at the top
 **/
// void	put_at_top(t_dlist *list, t_dlist *elem)
// {
	
	
// }

/**
 * Find and return the smallest element of the stack 
 * @param list	stack where to find the smallest element
 * @return		the smalest element found in the stack
 **/
t_dlist	*find_smaller(t_dlist *list)
{
	t_dlist	*tmp;
	t_dlist	*smaller;

	smaller = list;
	tmp = list->next;
	if (get_value(tmp) < get_value(smaller))
			smaller = tmp;
	while (tmp != list)
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
 * @param list	pointer on the first elem of the stack to sort
 **/
// void	sort(t_dlist **list)
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
	t_dlist	*a;
	// t_dlist	*b;
	
	if (argc == 1)
		return (0);
	if (scan_input(argc, argv, &a))
		error();
	print_dlist_line("a", a);

	t_dlist	*b;
	int		*num;
	t_dlist	*tmp;
	num = malloc(sizeof(int));
	*num = 42;
	ft_dlstadd_back(&b, (tmp = ft_dlstnew(num)));
	// print_dlist_line("b", b);
	// ft_printf("%d\n", first_half(b, tmp));
	// sort(&a);
	return (0);
}
