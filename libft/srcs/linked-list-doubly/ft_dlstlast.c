/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:54:08 by hthomas           #+#    #+#             */
/*   Updated: 2020/10/02 16:07:55 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Returns the last element of the list
** @param dlst	The beginning of the list
** @return		Last element of the list
*/

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return (NULL);
	tmp = dlst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
