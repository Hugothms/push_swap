/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:50:47 by hthomas           #+#    #+#             */
/*   Updated: 2020/10/03 17:15:23 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Iterates the list ’dlst’ and applies the function ’f’ to the content of each
**  element.
** @param dlst	The adress of a pointer to an element.
** @param f		The adress of the function used to iterate on the list.
*/

void	ft_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	t_dlist	*tmp;

	if (!dlst)
		return ;
	tmp = dlst;
	while (tmp->next)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
	f(tmp->content);
}
