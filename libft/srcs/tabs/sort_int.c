/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:20:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/15 10:21:24 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	sort_int(int *tab, int size)
{
	int swap;
	int i;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 1;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				swap = 1;
			}
			i++;
		}
	}
}
