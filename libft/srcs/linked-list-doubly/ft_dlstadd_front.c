/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:34:27 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/08 16:34:28 by hthomas          ###   ########.fr       */
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
	t_dlist	*tmp;

	tmp = *adlst;
	*adlst = new;
	new->next = tmp;
}
