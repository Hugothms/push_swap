/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:26:40 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/26 19:37:32 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_stacks
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	t_dlist		*oper;
}				t_stacks;

typedef struct	s_begin_end
{
	t_dlist		**begin;
	t_dlist		**end;
}				t_begin_end;

/*
** divide_stack
*/
int				divide_stack(t_stacks *ab, t_dlist **stack, int value,
					t_begin_end *be);

/*
** find_median
*/
t_dlist			*find_node(t_dlist *stack, int value);
int				size_stack(t_dlist *begin, t_dlist *end);
t_dlist			*find_median(t_dlist *stack, t_dlist *end);

/*
** operations_precise
*/
void			pb(t_stacks *ab, t_dlist **stack);
void			pa(t_stacks *ab, t_dlist **stack);
void			ra(t_stacks *ab);
void			rb(t_stacks *ab);
void			rra(t_stacks *ab);

/*
** operations_precise2
*/
void			rrb(t_stacks *ab);

/*
** operations_redir
*/
void			swap_help(t_dlist **a, t_dlist **b, char *line, int *ret);
void			push_help(t_dlist **a, t_dlist **b, char *line, int *ret);
void			rotate_help(t_dlist **a, t_dlist **b, char *line, int *ret);
void			reverse_help(t_dlist **a, t_dlist **b, char *line, int *ret);

/*
** operations
*/
int				checker(t_dlist *stack);
void			swap(t_dlist **stack);
void			push(t_dlist **a, t_dlist **b);
void			rotate(t_dlist **stack);
void			reverse(t_dlist **stack);

/*
** print
*/
void			print_dlist_line(t_dlist *stack, char name);
void			print_clean_dlist(t_dlist *operations);

/*
** scan_input
*/
int				duplicates(t_dlist *a);
int				int_overflow(char const *str, int sign);
t_dlist			*scan_input(int argc, char const *argv[], int *print, int *fd);

/*
** sort_naif_utils
*/
void			sort1(t_stacks *ab, t_dlist **stack, char name);
void			sort2(t_stacks *ab, t_dlist **stack, char name);
void			sort3(t_stacks *ab, t_dlist **stack, char name);
void			sort4(t_stacks *ab, t_dlist **stack, char name);
void			sort5(t_stacks *ab, t_dlist **stack, char name);

/*
** sort_naif
*/
int				pos_node(t_dlist *stack, t_dlist *node);
int				first_half(t_dlist *stack, int pos);
void			put_at_top(t_stacks *ab, t_dlist **stack, t_dlist *node,
					char name);
t_dlist			*find_smallest(t_dlist *stack);
void			sort_naif(t_stacks *ab, t_dlist **stack, char name);

/*
** sort_quick
*/
int				sort_quick(t_stacks *ab, t_dlist *begin, t_dlist *end,
					t_sp *norm);

/*
** sort_stack_2
*/
void			sort_stack_2(t_stacks *ab, t_dlist **st, char name);
void			sort_stack_2_reverse(t_stacks *ab, t_dlist **st, int push_on_a);

/*
** sort_stack_2
*/
void			sort_stack_3(t_stacks *ab, t_dlist **st, char name);
void			sort_stack_3_reverse(t_stacks *ab, t_dlist **st, char name);

/*
** sort_stack_under_3
*/
int				sort_stack_under_3(t_stacks *ab, t_dlist **begin, t_dlist *end,
					int p_a);

/*
** utils
*/
void			error(char *str, t_dlist *a, t_stacks *ab, t_sp *norm);
void			error_a_b(char *str, t_dlist *a, t_dlist *b, char *line);
int				get_value(t_dlist *stack);
char			*get_str(t_dlist *stack);
void			push_n_times(t_stacks *ab, t_dlist **begin, char c, int n);

# define RESET	"\x1B[0m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define CLR	"\e[1;1H\e[?25l"

#endif
