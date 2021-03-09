/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:34:17 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/09 06:01:25 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Allocates (with malloc(3)) and returns a new element.
** The variable ’content’ is initialized with the value of the
**  parameter ’content’. 
** The variables ’next’ and 'prev' are initialized to NULL.
** @param content The content to create the new element with
** @return			The new element
*/

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	if (!(new = malloc(sizeof(t_dlist))))
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
