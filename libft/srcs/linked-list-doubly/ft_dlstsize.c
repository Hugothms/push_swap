/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:49:16 by hthomas           #+#    #+#             */
/*   Updated: 2020/10/02 16:06:53 by hthomas          ###   ########.fr       */
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
