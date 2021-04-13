/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/13 12:01:45 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str, t_dlist *a, t_stacks *ab, t_sp *norm)
{
	printf("Error: %s\n", str);
	if (a)
		ft_dlstclear(&a, a, free);
	if (ab)
	{
		if (ab->stack_a)
			ft_dlstclear(&ab->stack_a, ab->stack_a, free);
		if (ab->stack_b)
			ft_dlstclear(&ab->stack_b, ab->stack_b, free);
		if (ab->oper)
			ft_dlstclear(&ab->oper, ab->oper, free);
		free(ab);
	}
	if (norm)
		free(norm);
	exit(1);
}

void	error_a_b(char *str, t_dlist *a, t_dlist *b, char *line)
{
	printf("Error: %s\n", str);
	if (a)
		ft_dlstclear(&a, a, free);
	if (b)
		ft_dlstclear(&b, b, free);
	if (line)
		free(line);
	exit(1);
}

int		get_value(t_dlist *stack)
{
	return (*(int *)(stack->content));
}

char	*get_str(t_dlist *stack)
{
	return ((char *)(stack->content));
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
