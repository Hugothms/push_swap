/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 11:08:15 by hthomas          ###   ########.fr       */
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
