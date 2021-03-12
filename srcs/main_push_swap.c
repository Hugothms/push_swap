/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/12 19:13:58 by hthomas          ###   ########.fr       */
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
void	sort_3(t_dlist *list)
{

}

/**
 * Put an element at the top of the stack without changing the order of 
 * the other elements
 * @param list	stack to modify
 * @param elem	element to put at the top
 **/
void	put_at_top(t_dlist *list, t_dlist *elem)
{

}

/**
 * Find and return the smallest element of the stack 
 * @param list	stack where to find the smallest element
 * @return		the smalest element found in the stack
 **/
t_dlist	*find_smaller(t_dlist const *list)
{
	t_dlist *tmp;
	int		num;

	tmp = list;
	while (tmp->next != list)
	{
		
		tmp = tmp->next;
	}
}

/**
 * Sort a stack with the help of a second stack using only the 
 * autorized operations and print them
 * @param list	pointer on the first elem of the stack to sort
 **/
void	sort(t_dlist **list)
{
	t_dlist	*b;

	while (ft_dlstsize(*list) > 3)
	{
		put_at_top(*list, find_smaller(*list));
		ft_printf("pb\n");
		push(&b, list);
	}
	sort_3(*list);
	while(ft_dlstsize(b))
	{
		ft_printf("pa\n");
		push(list, &b);
	}
}

int		main(int argc, char const *argv[])
{
	t_dlist	*a;
	// t_dlist	*b;
	
	if (argc == 1)
		return (0);
	if (scan_input(argc, argv, &a))
		error();
	sort(&a);
	return (0);
}
