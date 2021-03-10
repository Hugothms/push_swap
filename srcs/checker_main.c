/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/10 17:04:32 by hthomas          ###   ########.fr       */
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

void	swap_it(t_dlist **a, t_dlist **b, char *line, int *ret)
{
	*ret = 0;
	if (!ft_strcmp(line, "sa"))
		swap(a);
	else if (!ft_strcmp(line, "sb"))
		swap(b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(a);
		swap(b);
	}
	else
		*ret = 1;
}

void	push_it(t_dlist **a, t_dlist **b, char *line, int *ret)
{
	*ret = 0;
	if (!ft_strcmp(line, "pa"))
		push(a, b);
	else if (!ft_strcmp(line, "pb"))
		push(b, a);
	else
		*ret = 1;
}

void	rotate_it(t_dlist **a, t_dlist **b, char *line, int *ret)
{
	*ret = 0;
	if (!ft_strcmp(line, "ra"))
		rotate(a);
	else if (!ft_strcmp(line, "rb"))
		rotate(b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else
		*ret = 1;
}
void	reverse_it(t_dlist **a, t_dlist **b, char *line, int *ret)
{
	*ret = 0;
	if (!ft_strcmp(line, "rra"))
		reverse(a);
	else if (!ft_strcmp(line, "rrb"))
		reverse(b);
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse(a);
		reverse(b);
	}
	else
		*ret = 1;
}


int		main(int argc, char const *argv[])
{
	t_dlist	*a;
	t_dlist	*b;
	char	*line;
	int		ret;

	b = NULL;
	if (scan_args(argc, argv, &a))
		return (1);
	print_clean_dlist(a, b);
	while(get_next_line(&line ,0))
	{
		printf("---------\nExec %s:\n", line);
		if (!ft_strncmp(line, "s", 1))
			swap_it(&a, &b, line, &ret);
		else if (!ft_strncmp(line, "p", 1))
			push_it(&a, &b, line, &ret);
		else if (!ft_strncmp(line, "rr", 2))
			reverse_it(&a, &b, line, &ret);
		else if (!ft_strncmp(line, "r", 1))
			rotate_it(&a, &b, line, &ret);
		else
			exit (1);
		if (ret)
			exit (1);
		print_clean_dlist(a, b);
	}
	printf("%s\n", (checker(a) ? "KO" : "OK"));
	return (0);
}
