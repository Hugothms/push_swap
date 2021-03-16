/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:26:40 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/16 09:17:47 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** sort_naif
*/
int		pos_node(t_dlist *stack, t_dlist *node);
int		first_half(t_dlist *stack, int pos);
void	put_at_top(t_dlist **stack, t_dlist *node, char name);
t_dlist	*find_smallest(t_dlist *stack);
void	sort_naif(t_dlist **stack, char name);

/*
** sort_quick
*/
t_dlist	*sort_quick(t_dlist **stack, char name);

/*
** operations_redir
*/
void	swap_help(t_dlist **a, t_dlist **b, char *line, int *ret);
void	push_help(t_dlist **a, t_dlist **b, char *line, int *ret);
void	rotate_help(t_dlist **a, t_dlist **b, char *line, int *ret);
void	reverse_help(t_dlist **a, t_dlist **b, char *line, int *ret);

/*
** operations
*/
int		checker(t_dlist *stack);
void	swap(t_dlist **stack);
void	push(t_dlist **a, t_dlist **b);
void	rotate(t_dlist **stack);
void	reverse(t_dlist **stack);

/*
** print
*/
void	print_dlist_line(t_dlist *stack, char name);
void	print_first_item_dlist(t_dlist *dlist);
void	print_clean_dlist(t_dlist *a, t_dlist *b);

/*
** scan_input
*/
void	error(void);
int		duplicates(t_dlist *a);
int		int_overflow(char const *str, int sign);
t_dlist *scan_input(int argc, char const *argv[]);

/*
** sort_utils
*/
void	sort1(t_dlist **stack, char name);
void	sort2(t_dlist **stack, char name);
void	sort3(t_dlist **stack, char name);
void	sort4(t_dlist **stack, char name);
void	sort5(t_dlist **stack, char name);

/*
** utils
*/
int		get_value(t_dlist *stack);

#endif