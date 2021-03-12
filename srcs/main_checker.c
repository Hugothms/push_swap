/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/12 19:35:20 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char const *argv[])
{
	t_dlist	*a;
	t_dlist	*b;
	char	*line;
	int		ret;

	b = NULL;
	if (argc == 1)
		return (0);
	if (scan_input(argc, argv, &a))
		error();
	print_dlist_line("a", a);
	// print_clean_dlist(a, b);
	while(get_next_line(&line ,0))
	{
		ft_printf("---------\nExec %s:\n", line);
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
	ft_printf("%s\n", (checker(a, b) ? "KO" : "OK"));
	return (0);
}
