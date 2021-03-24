/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:13:23 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/24 09:40:02 by hthomas          ###   ########.fr       */
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

void	scan_input2(t_dlist **a, char const *argv[], int *i)
{
	int		*num;
	int		j;

	j = 0;
	if (argv[*i][j] && argv[*i][j] == '-')
		j++;
	if (ft_strlen(&argv[*i][j]) > 10 || int_overflow(&argv[*i][j], j))
		error("a");
	while (argv[*i][j])
	{
		if ((argv[*i][j] == 'f' || argv[*i][j] == 'v') && !argv[*i][j + 1])
		{
			(*i)++;
			return ;
		}
		if (!ft_isdigit(argv[*i][j]) && argv[*i][j] != 'f' && argv[*i][j] != 'v')
			error("z");
		j++;
	}
	num = malloc(sizeof(int));
	if (!num)
		error("e");
	*num = ft_atol(argv[(*i)++]);
	ft_dlstadd_back(a, ft_dlstnew(num));
}

// void	remove_elem_from_tab(int argc, char const *argv[], int i)
// {
// 	while (i < argc - 1)
// 	{
// 		argv[i] = argv[i + 1];
// 		i++;
// 	}
// 	// free(argv[i]);
// 	argv[i] = NULL;
// 	argc--;
// }

void	scan_input_bonus(int argc, char const *argv[], int *print, int *fd)
{
	int	i;

	i = 1;
	*print = 0;
	*fd = 0;
	while (i < argc)
	{
		if (argv[i] && !ft_strcmp(argv[i], "-v")) // pb on passe pas le premier argv si -v
			*print = 1;
		else if (argv[i] && argv[i + 1] && !ft_strcmp(argv[i], "-f"))
			*fd = open(argv[i + 1], O_RDONLY);
		i++;
	}
}

t_dlist	*scan_input(int argc, char const *argv[], int *print, int *fd)
{
	int		i;
	t_dlist	*a;

	a = NULL;
	if (print && fd)
		scan_input_bonus(argc, argv, print, fd);
	i = 1;
	while (i < argc)
		scan_input2(&a, argv, &i);
	if (duplicates(a))
		error("t");
	return (a);
}
