/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:26:45 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_operation(t_dlist **a, t_dlist **b, char *line, int print)
{
	int		ret;

	if (print)
		printf("\nOperation: %s\n", line);
	if (!ft_strncmp(line, "s", 1))
		swap_help(a, b, line, &ret);
	else if (!ft_strncmp(line, "p", 1))
		push_help(a, b, line, &ret);
	else if (!ft_strncmp(line, "rr", 2))
		reverse_help(a, b, line, &ret);
	else
		rotate_help(a, b, line, &ret);
	if (ret)
		error("Operation invalid");
	if (print)
	{
		print_dlist_line(*a, 'a');
		print_dlist_line(*b, 'b');
	}
}

void	main2(t_dlist **a, t_dlist **b, int print)
{
	char	*line;

	if (print)
	{
		print_dlist_line(*a, 'a');
		print_dlist_line(*b, 'b');
	}
	while (get_next_line(&line, 0))
		exec_operation(a, b, line, print);
	if (*b || (checker(*a)))
		printf("KO\n");
	else
		printf("OK\n");
}

int		main(int argc, char const *argv[])
{
	t_dlist	*a;
	t_dlist	*b;
	int		print;
	int		fd;

	b = NULL;
	if (argc == 1)
		return (0);
	a = scan_input(argc, argv, &print, &fd);
	if (!a)
		error("Malloc failed");
	main2(&a, &b, print);
	return (0);
}
