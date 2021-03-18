/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:26:40 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/18 19:31:41 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stacks
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	int			size_a;
	int			size_b;
	char		name_a;
	char		name_b;
}				t_stacks;


/*
** sort_naif
*/
void	sort_stack_size_2(t_dlist **st, char name);
void	sort_stack_size_3(t_dlist **st, char name);
int		pos_node(t_dlist *stack, t_dlist *node);
int		first_half(t_dlist *stack, int pos);
void	put_at_top(t_dlist **stack, t_dlist *node, char name);
t_dlist	*find_smallest(t_dlist *stack);
void	sort_naif(t_dlist **stack, char name);

/*
** sort_quick
*/
int		sort_quick_maintenance(t_stacks *ab, t_dlist *begin, t_dlist *end, int parity);
t_dlist	*sort_quick(t_stacks *ab, int size, int parity);

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
** operations_precise
*/
void	pb(t_stacks *ab, t_dlist **stack);
void	pa(t_stacks *ab, t_dlist **stack);
void	ra(t_stacks *ab);
void	rb(t_stacks *ab);
void	rra(t_stacks *ab);
void	rrb(t_stacks *ab);

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