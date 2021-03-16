/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/16 13:39:47 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char const *argv[])
{
	t_stacks *ab;
	
	if (argc == 1)
		return (0);
	if (!(ab = malloc(sizeof(*ab))))
		error();
	if (!(ab->stack_a = scan_input(argc, argv)))
		error();
	ab->stack_b = NULL;
	ab->name_a = 'a';
	ab->name_b = 'b';
	
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

	sort_quick(ab);
	ft_dlstclear(&ab->stack_a, ab->stack_a, &free);
	return (0);
}
