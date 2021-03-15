/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/15 09:41:59 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

	sort_naif(&a, 'a');
	return (0);
}
