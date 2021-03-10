/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:56:00 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/10 15:42:27 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/libft.h"

/*
** Remove the element 'dlst' of the list and return it.
** @param dlst	The address of the element to remove from the list.
*/

t_dlist	*ft_dlstremove_one(t_dlist **adlst, t_dlist *dlst)
{
	if (!*adlst || !dlst)
		return (NULL);
	if (*adlst == dlst)
	{
		if (*adlst == (*adlst)->next)
		{
			*adlst = NULL;
			return (NULL);
		}
		*adlst = dlst->next;
	}
	if (dlst->prev)
		dlst->prev->next = dlst->next;
	if (dlst->next)
		dlst->next->prev = dlst->prev;
	dlst->next = NULL;
	dlst->prev = NULL;
	return (dlst);
}
