/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/10 16:36:56 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

	// t_dlist	*tmp1;
	// t_dlist	*tmp;
	// int		*num;
	// if (!(num = malloc(sizeof(int))))
	// 	exit(1);
	// *num = 42;
	// ft_dlstadd_front(&a, (tmp = ft_dlstnew(num)));
	// ft_dlstadd_front(&b, (tmp1 = ft_dlstnew(num)));
	// ft_dlstadd_front(&b, (tmp = ft_dlstnew(num)));
	// ft_dlstremove_one(&b, tmp1);
	// ft_dlstremove_one(&b, tmp);

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
	printf("%s\n", (checker(a) ? "KO" : "OK"));
	return (0);
}
