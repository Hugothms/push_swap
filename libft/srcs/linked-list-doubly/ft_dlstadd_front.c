/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:34:27 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/10 10:31:37 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Adds the element ’new’ at the beginning of the list
** @param adlst	The address of a pointer to the first link of a list
** @param new	The address of a pointer to the element to be added to the list
*/

void	ft_dlstadd_front(t_dlist **adlst, t_dlist *new)
{
	t_dlist	*second;
	t_dlist	*last;

	if (!*adlst)
	{
		*adlst = new;
		(*adlst)->prev = *adlst;
		(*adlst)->next = *adlst;
		return ;
	}
	second = *adlst;
	*adlst = new;
	new->next = second;
	last = second->prev;
	second->prev = new;
	new->prev = last;
	last->next = *adlst;
}
