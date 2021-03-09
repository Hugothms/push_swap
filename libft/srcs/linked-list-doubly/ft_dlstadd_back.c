/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:32:54 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/09 06:24:47 by hthomas          ###   ########.fr       */
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
	t_dlist	*tmp;

	if (!*adlst)
	{
		*adlst = new;
		return ;
	}
	tmp = *adlst;
	while (tmp->next && tmp->next != *adlst)
		tmp = tmp->next; 
	tmp->next = new;
	new->next = *adlst;
	(*adlst)->prev = new;
	new->prev = tmp;
}
