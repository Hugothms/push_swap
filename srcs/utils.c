/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 12:12:39 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(char *str)
{
	printf("Error: %s\n", str);
	exit (1);
}

int	get_value(t_dlist *stack)
{
	return (*(int *)(stack->content));
}

void	push_n_times(t_stacks *ab, t_dlist **begin, char c, int n)
{
	while (n--)
	{
		if (c == 'a')
			pa(ab, begin);
		else
			pb(ab, begin);
	}
}
