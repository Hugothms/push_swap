/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:33:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/08 16:33:36 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Counts the number of elements in a list
** @param dlst	The beginning of the list
** @return		Length of the list
*/

int	ft_dlstsize(t_dlist *dlst)
{
	int		cpt;
	t_dlist	*pt;

	if (!dlst)
		return (0);
	cpt = 1;
	pt = dlst;
	while ((pt = pt->next))
		cpt++;
	return (cpt);
}
