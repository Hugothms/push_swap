/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:34:17 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/08 16:34:18 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a new element.
** The variable ’content’ is initialized with the value of the
**  parameter ’content’. The variable ’next’ is initialized to NULL.
** @param content The content to create the new element with
** @return			The new element
*/

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	if (!(new = malloc(sizeof(t_dlist))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
