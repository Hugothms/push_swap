/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:33:49 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/08 16:33:51 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Takes as a parameter an element and frees the memory of
**  the element’s content using the function ’del’ given as a parameter
**  and free the element. The memory of ’next’ must not be freed
** @param dlst	The adress of a pointer to an element.
** @param del	The adress of the function used to delete the content of the
**				 element.
*/

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void*))
{
	if (!dlst)
		return ;
	del(dlst->content);
	free(dlst);
}
