/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/10 15:59:40 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_dlist_line(t_dlist *list)
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
	printf("\n");
	if (tmp_a)
	tmp_a = tmp_a->next;
	if (tmp_b)
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
	ft_printf("- -\na b\n\n");
}

int		scan_args(int argc, char const *argv[], t_dlist **a)
{
	int		i;
	int		*num;

	i = 1;
	while (i < argc)
	{
		if (!(num = malloc(sizeof(int))))
			return (1);
		*num = ft_atoi(argv[i]);
		ft_dlstadd_back(a, ft_dlstnew(num));
		i++;
	}
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_dlist	*a;
	t_dlist	*b;

	b = NULL;
	if (scan_args(argc, argv, &a))
		return (1);


	print_clean_dlist(a, b);

	char	*line;
	while(get_next_line(&line ,0))
	{
		printf("---------\nExec %s:\n", line);
		if (!ft_strcmp(line, "sa"))
			swap(&a);
		else if (!ft_strcmp(line, "sb"))
			swap(&b);
		else if (!ft_strcmp(line, "ss"))
		{
			swap(&a);
			swap(&b);
		}
		else if (!ft_strcmp(line, "pa"))
			push(&a, &b);
		else if (!ft_strcmp(line, "pb"))
			push(&b, &a);
		else if (!ft_strcmp(line, "ra"))
			rotate(&a);
		else if (!ft_strcmp(line, "rb"))
			rotate(&b);
		else if (!ft_strcmp(line, "rr"))
		{
			rotate(&a);
			rotate(&b);
		}
		else if (!ft_strcmp(line, "rra"))
			reverse(&a);
		else if (!ft_strcmp(line, "rrb"))
			reverse(&b);
		else if (!ft_strcmp(line, "rrr"))
		{
			reverse(&a);
			reverse(&b);
		}
		else
			exit (1);
		print_clean_dlist(a, b);
	}
	printf("check a: %s\n", (checker(a) ? "KO" : "OK"));
	printf("check b: %s\n", (checker(b) ? "KO" : "OK"));
	return (0);
}
