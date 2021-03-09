/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:34:09 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/09 06:04:48 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Iterates the list ’dlst’ and applies the function ’f’ to the content of each
**  element. Creates a newlist resulting of the successive applications of the
**  function ’f’. The ’del’ function is used to delete the content of an
**  element if needed.
** @param dlst	The adress of a pointer to an element.
** @param f		The adress of the function used to iterate on the list.
** @param del	The adress of the function used to delete the content of an
**				 element if needed.
** @return		The new list. NULL if the allocation fails.
*/

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*tmp;
	t_dlist	*new;
	t_dlist	*mapeddlst;

	if (!dlst || !f || !del)
		return (NULL);
	tmp = dlst;
	if (!(mapeddlst = ft_dlstnew(f(tmp->content))))
		ft_dlstclear(&mapeddlst, del);
	tmp = tmp->next;
	while (tmp && tmp->next != dlst)
	{
		if (!(new = ft_dlstnew(f(tmp->content))))
			ft_dlstclear(&mapeddlst, del);
		ft_dlstadd_back(&mapeddlst, new);
		tmp = tmp->next;
	}
	return (mapeddlst);
}
