/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/09 07:23:06 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_dlist(t_dlist *list)
{
	t_dlist	*tmp;
	int		*num;
	
	tmp = list;
	while (tmp && tmp->next != list)
	{
		num = tmp->content;
		ft_printf("%d", *num);
		tmp = tmp->next;
	}
	num = tmp->next->content;
	ft_printf("\nnext:%d", *num);
	ft_printf("\n");
}

void	print_first_item_dlist(t_dlist *dlist)
{
	int		*num;

	if (dlist)
	{
		num = dlist->content;
		ft_printf("%d ", *num);
	}
}

void	print_clean_dlist(t_dlist *a, t_dlist *b)
{
	t_dlist	*tmp_a;
	t_dlist	*tmp_b;
	
	tmp_a = a;
	tmp_b = b;
	print_first_item_dlist(a);
	print_first_item_dlist(b);
	ft_printf("\n");
	tmp_a = tmp_a->next;
	tmp_b = tmp_b->next;
	while ((tmp_a && tmp_a != a) || (tmp_b && tmp_b != b))
	{
		if (tmp_a != a)
		{
			print_first_item_dlist(tmp_a);
			tmp_a = tmp_a->next;
		}
		if (tmp_b != b)
		{
			print_first_item_dlist(tmp_b);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("- -\na b\n");
}

int		main(int argc, char const *argv[])
{
	int		i;
	int		*elt;
	t_dlist	*a;
	t_dlist	*b;

	i = 1;
	while (i < argc)
	{
		if (!(elt = malloc(sizeof(int))))
			return (1);
		*elt = ft_atoi(argv[i]);
		ft_dlstadd_back(&a, ft_dlstnew(elt));
		// printf("%d\n", *elt);
		i++;
	}
	if (!(elt = malloc(sizeof(int))))
		return (1);
	*elt = 8;
	ft_dlstadd_back(&b, ft_dlstnew(elt));
	if (!(elt = malloc(sizeof(int))))
		return (1);
	*elt = 4;
	ft_dlstadd_back(&b, ft_dlstnew(elt));
	print_clean_dlist(a, b);
	return (0);
}
