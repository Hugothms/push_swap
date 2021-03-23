/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/23 14:05:45 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Check if the given list is sorted
 * @return	0 if the list is sorted, otherwise return 1
 **/
int	checker(t_dlist *stack)
{
	t_dlist	*tmp;

	if (!stack | !stack->next)
		return (0);
	tmp = stack;
	if (*(int *)(stack->content) > *(int *)(stack->next->content))
		return (1);
	tmp = tmp->next;
	while (tmp && tmp->next != stack)
	{
		if (*(int *)(tmp->content) > *(int *)(tmp->next->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/**
 * Swap the ﬁrst 2 nodes at the top of stack
 * Do nothing if there is only one or no nodes)
 **/
void	swap(t_dlist **stack)
{
	int		*num;

	if (*stack && (*stack)->next)
	{
		num = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = num;
	}
}

/**
 * Take the ﬁrst node at the top of b and put it at the top of a
 * Do nothing if b is empty
 **/
void	push(t_dlist **a, t_dlist **b)
{
	int		*num;
	t_dlist	*tmp;

	if (!*b)
		return ;
	num = (*b)->content;
	tmp = *b;
	ft_dlstremove_one(b, *b);
	if (!(tmp = ft_dlstnew(num)))
		return ;
	ft_dlstadd_front(a, tmp);
}

/**
 * Shift up all nodes of stack a by 1
 * The ﬁrst node becomes the last one
 **/
void	rotate(t_dlist **stack)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstremove_one(stack, *stack)))
		ft_dlstadd_back(stack, tmp);
}

/**
 * Shift down all nodes of stack a by 1
 * The last node becomes the ﬁrst one.
 **/
void	reverse(t_dlist **stack)
{
	t_dlist	*tmp;

	if ((tmp = ft_dlstremove_one(stack, ft_dlstlast(*stack))))
		ft_dlstadd_front(stack, tmp);
}
