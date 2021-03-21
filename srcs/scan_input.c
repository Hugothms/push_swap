/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:13:23 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 01:16:44 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit (1);
}

/**
 * check if there are duplicates in the list
 * @return	0 if no duplicates where found, 1 otherwise
 **/
int	duplicates(t_dlist *a)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = a;
	while (tmp && tmp->next != a)
	{
		tmp2 = tmp->next;
		while (tmp2 && tmp2 != a)
		{
			if (get_value(tmp) == get_value(tmp2))
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	int_overflow(char const *str, int sign)
{
	if (sign)
		return (ft_strlen(str) == 10 && (ft_strcmp(str, "2147483648")) > 0);
	else
		return (ft_strlen(str) == 10 && (ft_strcmp(str, "2147483647")) > 0);
}

t_dlist	*scan_input(int argc, char const *argv[])
{
	int		i;
	int		j;
	int		*num;
	t_dlist	*a;

	i = 1;
	a = NULL;
	while (i < argc)
	{
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
		if (!(num = malloc(sizeof(int))))
			error();
		*num = ft_atol(argv[i++]);
		ft_dlstadd_back(&a, ft_dlstnew(num));
	}
	if (duplicates(a))
		error();
	return (a);
}
