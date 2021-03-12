/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:26:40 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/12 18:00:44 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

/*
** operations_redir
*/
void	swap_it(t_dlist **a, t_dlist **b, char *line, int *ret);
void	push_it(t_dlist **a, t_dlist **b, char *line, int *ret);
void	rotate_it(t_dlist **a, t_dlist **b, char *line, int *ret);
void	reverse_it(t_dlist **a, t_dlist **b, char *line, int *ret);

/*
** operations
*/
int		checker(t_dlist *a, t_dlist *b);
void	swap(t_dlist **list);
void	push(t_dlist **a, t_dlist **b);
void	rotate(t_dlist **list);
void	reverse(t_dlist **list);

/*
** print
*/
void	print_dlist_line(char *name, t_dlist *list);
void	print_first_item_dlist(t_dlist *dlist);
void	print_clean_dlist(t_dlist *a, t_dlist *b);

/*
** scan_input
*/
void	error(void);
int		duplicates(t_dlist *a);
int		int_overflow(char const *str, int sign);
int		scan_input(int argc, char const *argv[], t_dlist **a);

#endif