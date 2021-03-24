/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 16:35:41 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_sp		*norm;
	t_stacks	*ab;

	if (argc == 1)
		return (0);
	norm = malloc(sizeof(*norm));
	if (!norm)
		error("u");
	norm->i = 0;
	ab = malloc(sizeof(*ab));
	if (!ab)
		error("u");
	ab->stack_a = scan_input(argc, argv, NULL, NULL);
	if (!ab->stack_a)
		error("i");
	ab->stack_b = NULL;
	if (ft_dlstsize(ab->stack_a) > 5)
		sort_quick(ab, ab->stack_a, ab->stack_a->prev, 0);
	else if (ft_dlstsize(ab->stack_a) > 1)
		sort_naif(&ab->stack_a, 'a');
	ft_dlstclear(&ab->stack_a, ab->stack_a, &free);
	return (0);
}
