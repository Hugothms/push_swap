/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:26:40 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/11 15:41:38 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>

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
void	print_dlist_line(char *str, t_dlist *list);
void	print_first_item_dlist(t_dlist *dlist);
void	print_clean_dlist(t_dlist *a, t_dlist *b);

#endif