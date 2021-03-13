/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:43:36 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/13 12:12:53 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort1(t_dlist *stack)
{
	ft_printf("sa\n");
	swap(&stack);
}

void	sort2(t_dlist *stack)
{
	ft_printf("sa\n");
	swap(&stack);
	ft_printf("rra\n");
	reverse(&stack);
}

void	sort3(t_dlist *stack)
{
	ft_printf("ra\n");
	rotate(&stack);
}

void	sort4(t_dlist *stack)
{
	ft_printf("sa\n");
	swap(&stack);
	ft_printf("ra\n");
	rotate(&stack);
}

void	sort5(t_dlist *stack)
{
	ft_printf("rra\n");
	reverse(&stack);
}
