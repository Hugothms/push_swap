/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:49:44 by hthomas           #+#    #+#             */
/*   Updated: 2020/10/02 17:56:14 by hthomas          ###   ########.fr       */
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
