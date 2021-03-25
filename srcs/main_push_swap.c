/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 17:14:21 by hthomas          ###   ########.fr       */
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
		error("Malloc failed", NULL, NULL, NULL);
	norm->i = 0;
	ab = malloc(sizeof(*ab));
	if (!ab)
		error("Malloc failed", NULL, NULL, norm);
	ab->stack_a = scan_input(argc, argv, NULL, NULL);
	if (!checker(ab->stack_a))
		return (0);
	ab->stack_b = NULL;
	ab->operations = NULL;
	if (ft_dlstsize(ab->stack_a) > 50)
		sort_quick(ab, ab->stack_a, ab->stack_a->prev, norm);
	else if (ft_dlstsize(ab->stack_a) > 1)
		sort_naif(ab, &ab->stack_a, 'a');
	print_clean_dlist(ab->operations);
	ft_dlstclear(&ab->stack_a, ab->stack_a, &free);
	return (0);
}
