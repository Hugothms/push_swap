/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/13 15:02:11 by hthomas          ###   ########.fr       */
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
	if (!(a = scan_input(argc, argv)))
		error();
	print_dlist_line(a, 'a');
	// print_clean_dlist(a, b);
	while(get_next_line(&line ,0))
	{
		ft_printf("---------\nExec %s:\n", line);
		if (!ft_strncmp(line, "s", 1))
			swap_it(&a, &b, line, &ret);
		else if (!ft_strncmp(line, "p", 1))
			push_it(&a, &b, line, &ret);
		else if (!ft_strncmp(line, "rr", 2))
			reverse_it(&a, &b, line, &ret);
		else
			rotate_it(&a, &b, line, &ret);
		if (ret)
			error();
		print_clean_dlist(a, b);
	}
	ft_printf("%s\n", (b || (checker(a)) ? "KO" : "OK"));
	return (0);
}
