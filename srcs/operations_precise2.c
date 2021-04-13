/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_precise2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:07:39 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/13 12:01:45 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stacks *ab)
{
	reverse(&ab->stack_b);
	ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rrb")));
}
