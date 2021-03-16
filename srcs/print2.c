/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:52:47 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/16 10:53:18 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_norm(t_dlist *s)
{
	int		i;
	t_dlist	*tmp;

	tmp = s;
	while (tmp != s)
	{
		i = 0;
		ft_putstr("         ");
		while (i <= get_value(tmp))
		{
			ft_putstr("█");
			i++;
		}
		// while (i <= che->llen)
		// {
		// 	ft_putchar(' ');
		// 	i++;
		// }
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

# define CYN "\x1B[36m"
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
# define CLR "\e[1;1H\e[?25l"

void	print_vis(t_dlist *a, t_dlist *b)
{
	ft_putstr(CYN);
	print_norm(a);
	ft_putstr(MAG);
	print_norm(b);
	ft_putstr(RESET);
	usleep(1000000);
}

void	print(t_dlist *a, t_dlist *b)
{
	ft_putstr(CLR);
	ft_putstr(WHT "\n\n\n");
	ft_putstr(CYN "STACK A is CYAN\n");
	ft_putstr(MAG "STACK B is MAGENTA\n"RESET);
	ft_putstr(RESET);
	print_vis(a, b);
}
