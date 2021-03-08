/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/08 17:10:09 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int argc, char const *argv[])
{
	int		i;
	int		*elt;
	t_dlist	*list;
	t_dlist	*tmp;

	i = 1;
	while (i < argc)
	{
		if (!(elt = malloc(sizeof(int))))
			return (1);
		*elt = ft_atoi(argv[i]);
		ft_dlstadd_back(&list, ft_dlstnew(elt));
		i++;
	}
	putchar('q');
	tmp = list;
	while (tmp->next != list)
	{
		int *num = tmp->content;
		ft_printf("%d", *num);
		tmp = tmp->next;
	}
	ft_printf("\n");
	return (0);
}
