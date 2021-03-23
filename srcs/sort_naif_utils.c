/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_naif_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:43:36 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/23 15:17:22 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort1(t_dlist **stack, char name)
{
	printf("s%c\n", name);
	swap(stack);
}

void	sort2(t_dlist **stack, char name)
{
	printf("s%c\n", name);
	swap(stack);
	printf("rr%c\n", name);
	reverse(stack);
}

void	sort3(t_dlist **stack, char name)
{
	printf("r%c\n", name);
	rotate(stack);
}

void	sort4(t_dlist **stack, char name)
{
	printf("s%c\n", name);
	swap(stack);
	printf("r%c\n", name);
	rotate(stack);
}

void	sort5(t_dlist **stack, char name)
{
	printf("rr%c\n", name);
	reverse(stack);
}
