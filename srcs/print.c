/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:37:07 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/26 11:11:27 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_dlist_line(t_dlist *stack, char name)
{
	t_dlist	*tmp;
	int		*num;

	tmp = stack;
	printf("%c: ", name);
	while (tmp && tmp->next != stack)
	{
		num = tmp->content;
		printf("%d ", *num);
		tmp = tmp->next;
	}
	if (tmp)
	{
		num = tmp->content;
		printf("%d", *num);
	}
	printf("\n");
}

void	print_clean_dlist(t_dlist *oper)
{
	t_dlist	*tmp;

	tmp = oper;
	if (tmp)
	{
		printf("%s\n", get_str(tmp));
		tmp = tmp->next;
	}
	while (tmp && tmp != oper)
	{
		if (tmp != oper)
		{
			printf("%s\n", get_str(tmp));
			tmp = tmp->next;
		}
	}
}
