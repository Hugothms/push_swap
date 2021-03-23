/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:13:23 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/23 15:26:51 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(char *str)
{
	printf("Error: %s\n", str);
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

void	function(t_dlist **a, char const *argv[], int *i)
{
	int		*num;
	int		j;

	j = 0;
	if (argv[*i][j] == '-' && argv[*i][j])
		j++;
	if (ft_strlen(&argv[*i][j]) > 10 || int_overflow(&argv[*i][j], j))
		error(NULL);
	while (argv[*i][j])
	{
		if (!ft_isdigit(argv[*i][j]))
			error(NULL);
		j++;
	}
	num = malloc(sizeof(int));
	if (!num)
		error(NULL);
	*num = ft_atol(argv[(*i)++]);
	ft_dlstadd_back(a, ft_dlstnew(num));
}

t_dlist	*scan_input(int argc, char const *argv[], int *print)
{
	int		i;
	t_dlist	*a;

	a = NULL;
	if (print)
		*print = 0;
	if (print && ((argv[1] && !ft_strcmp(argv[1], "-v"))
			|| !ft_strcmp(argv[argc - 1], "-v"))) // pb on passe pas le premier argv si -v
	{
		argc--;
		*print = 1;
	}
		i = 1;
	while (i < argc)
	{
		function(&a, argv, &i);
	}
	if (duplicates(a))
		error(NULL);
	return (a);
}
