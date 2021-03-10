/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:56:00 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/10 11:25:57 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libft.h"

/*
** Remove the element 'dlst' of the list and return it.
** @param dlst	The address of the element to remove from the list.
*/

t_dlist	*ft_dlstremove_one(t_dlist **adlst, t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	if (*adlst == dlst)
		return (NULL);
	if (dlst->prev)
		dlst->prev->next = dlst->next;
	if (dlst->next)
		dlst->next->prev = dlst->prev;
	dlst->next = NULL;
	dlst->prev = NULL;
	return (dlst);
}
