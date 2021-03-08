/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:32:54 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/08 16:33:08 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Adds the element ’new’ at the end of the list
** @param adlst	The address of a pointer to the first link of a list.
** @param new	The address of a pointer to the element to be added to the list.
*/

void	ft_dlstadd_back(t_dlist **adlst, t_dlist *new)
{
	t_dlist	*pt;

	if (!*adlst)
	{
		*adlst = new;
		return ;
	}
	pt = *adlst;
	while (pt->next)
		pt = pt->next;
	pt->next = new;
}
