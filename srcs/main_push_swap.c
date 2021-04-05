/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/05 15:19:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		useless_sequence(t_dlist *l)
{
	return (
		!(ft_strcmp(get_str(l), "pa") || ft_strcmp(get_str(l->next), "pb")) ||
		!(ft_strcmp(get_str(l), "pb") || ft_strcmp(get_str(l->next), "pa")) ||
		!(ft_strcmp(get_str(l), "ra") || ft_strcmp(get_str(l->next), "rra")) ||
		!(ft_strcmp(get_str(l), "rra") || ft_strcmp(get_str(l->next), "ra")) ||
		!(ft_strcmp(get_str(l), "rb") || ft_strcmp(get_str(l->next), "rrb")) ||
		!(ft_strcmp(get_str(l), "rrb") || ft_strcmp(get_str(l->next), "rb")));
}

void	remove_useless_operations(t_dlist **oper)
{
	t_dlist	*tmp;

	while ((*oper)->next && *oper != (*oper)->next && useless_sequence(*oper))
	{
		free(ft_dlstremove_one(oper, *oper));
		free(ft_dlstremove_one(oper, *oper));
	}
	tmp = (*oper)->next;
	while (tmp != *oper && tmp != (*oper)->prev)
	{
		if (tmp->next && useless_sequence(tmp))
		{
			tmp = tmp->prev;
			free(ft_dlstremove_one(oper, tmp->next));
			free(ft_dlstremove_one(oper, tmp->next));
			if (tmp != *oper)
				tmp = tmp->prev;
		}
		tmp = tmp->next;
	}
}

void	init_structs(t_sp **norm, t_stacks **ab, int argc, char const *argv[])
{
	*norm = malloc(sizeof(**norm));
	if (!*norm)
		error("Malloc failed", NULL, NULL, NULL);
	(*norm)->i = 0;
	*ab = malloc(sizeof(**ab));
	if (!*ab)
		error("Malloc failed", NULL, NULL, *norm);
	(*ab)->stack_a = scan_input(argc, argv, NULL);
	(*ab)->stack_b = NULL;
	(*ab)->oper = NULL;
}

int		main(int argc, char const *argv[])
{
	t_sp		*norm;
	t_stacks	*ab;

	if (argc == 1)
		return (0);
	init_structs(&norm, &ab, argc, argv);
	if (!checker(ab->stack_a))
	{
		ft_dlstclear(&ab->stack_a, ab->stack_a, &free);
		ft_dlstclear(&ab->oper, ab->oper, &free);
		free(norm);
		free(ab);
		return (0);
	}
	if (ft_dlstsize(ab->stack_a) > 50)
		sort_quick(ab, ab->stack_a, ab->stack_a->prev, norm);
	else if (ft_dlstsize(ab->stack_a) > 1)
		sort_naif(ab, &ab->stack_a, 'a');
	remove_useless_operations(&ab->oper);
	print_clean_dlist(ab->oper);
	ft_dlstclear(&ab->stack_a, ab->stack_a, &free);
	ft_dlstclear(&ab->oper, ab->oper, &free);
	free(norm);
	free(ab);
	return (0);
}
