/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:48:53 by hthomas           #+#    #+#             */
/*   Updated: 2020/10/02 18:57:56 by hthomas          ###   ########.fr       */
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
