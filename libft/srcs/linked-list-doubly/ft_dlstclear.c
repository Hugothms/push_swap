/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:50:33 by hthomas           #+#    #+#             */
/*   Updated: 2020/10/05 11:37:01 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Deletes and frees the given element and every successor of that element,
**  using the function ’del’ and free(3).
** Finally, the pointer to the list must be set to NULL.
** @param dlst	The adress of a pointer to an element.
** @param del	The adress of the function used to delete the content of the
**  element.
*/

void	ft_dlstclear(t_dlist **adlst, void (*del)(void*))
{
	if (!*adlst)
		return ;
	if ((*adlst)->next)
	{
		ft_dlstclear(&((*adlst)->next), del);
		free((*adlst)->next);
	}
	ft_dlstdelone(*adlst, del);
	*adlst = NULL;
}
