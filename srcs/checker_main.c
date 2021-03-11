/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/11 15:01:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		duplicates(t_dlist *a)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = a;
	while (tmp && tmp->next != a)
	{
		tmp2 = a;
		while (tmp2 && tmp2->next != a)
		{
			if (tmp != tmp2 && *(int*)(tmp->content) == *(int*)(tmp2->content))
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	error(void)
{
	printf("Error\n");
	exit (1);
}

int		int_overflow(char const *str, int sign)
{
	if (sign)
		return (ft_strlen(str) == 10 && (ft_strcmp(str, "2147483648")) > 0);
	else
		return (ft_strlen(str) == 10 && (ft_strcmp(str, "2147483647")) > 0);
}

int		scan_args(int argc, char const *argv[], t_dlist **a)
{
	int		i;
	int		j;
	int		*num;

	i = 1;
	while (i < argc)
	{
		if (!(num = malloc(sizeof(int))))
			return (1);
		j = 0;
		if (argv[i][j] == '-' && argv[i][j])
			j++;
		if (ft_strlen(&argv[i][j]) > 10 || int_overflow(&argv[i][j], j))
			error();
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				error();
			j++;
		}
		*num = ft_atol(argv[i++]);
		ft_dlstadd_back(a, ft_dlstnew(num));
	}
	if (duplicates(*a))
		error();
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_dlist	*a;
	t_dlist	*b;
	char	*line;
	int		ret;

	b = NULL;
	if (argc == 1)
		return (0);
	if (scan_args(argc, argv, &a))
		return (1);
	// print_clean_dlist(a, b);
	while(get_next_line(&line ,0))
	{
		// printf("---------\nExec %s:\n", line);
		ret = 1;
		if (!ft_strncmp(line, "s", 1))
			swap_it(&a, &b, line, &ret);
		else if (!ft_strncmp(line, "p", 1))
			push_it(&a, &b, line, &ret);
		else if (!ft_strncmp(line, "rr", 2))
			reverse_it(&a, &b, line, &ret);
		else if (!ft_strncmp(line, "r", 1))
			rotate_it(&a, &b, line, &ret);
		if (ret)
			error();
		// print_clean_dlist(a, b);
	}
	printf("%s\n", (checker(a, b) ? "KO" : "OK"));
	return (0);
}
