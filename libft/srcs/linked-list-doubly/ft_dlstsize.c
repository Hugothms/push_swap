/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:33:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/13 11:16:02 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Counts the number of nodes in a list
** @param dlst	The beginning of the list
** @return		Length of the list
*/

int	ft_dlstsize(t_dlist *dlst)
{
	int		cpt;
	t_dlist	*tmp;

	if (!dlst)
		return (0);
	cpt = 1;
	tmp = dlst;
	while ((tmp = tmp->next) && tmp != dlst)
		cpt++;
	return (cpt);
}
