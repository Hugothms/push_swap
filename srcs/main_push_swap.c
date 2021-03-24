/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 09:39:20 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_stacks *ab;
	
	if (argc == 1)
		return (0);
	if (!(ab = malloc(sizeof(*ab))))
		error("u");
	if (!(ab->stack_a = scan_input(argc, argv, NULL, NULL)))
		error("i");
	ab->stack_b = NULL;
	ab->name_a = 'a';
	ab->name_b = 'b';
	ab->size_a = ft_dlstsize(ab->stack_a);
	ab->size_b = 0;	
	if (ab->size_a > 5)
		sort_quick_maintenance(ab, ab->stack_a, ab->stack_a->prev, 0);
	else if (ab->size_a > 1)
		sort_naif(&ab->stack_a, 'a');
	ft_dlstclear(&ab->stack_a, ab->stack_a, &free);
	return (0);
}
