/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:12:46 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/24 19:23:52 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_push(t_stacks **s, char *op)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_strncmp(op, "pa", 2) == 0)
		stack_push_a(&stacks);
	else if (ft_strncmp(op, "pb", 2) == 0)
		stack_push_b(&stacks);
	ft_putendl_fd(op, 1);
}

void	stack_push_a(t_stacks **s)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_lstsize(stacks->stack_b) < 1)
		return ;
	ft_lstadd_front(&stacks->stack_a, ft_lstnew(stacks->stack_b->content));
	ft_lstrem(&stacks->stack_b, stacks->stack_a->content);
}

void	stack_push_b(t_stacks **s)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_lstsize(stacks->stack_a) < 1)
		return ;
	ft_lstadd_front(&stacks->stack_b, ft_lstnew(stacks->stack_a->content));
	ft_lstrem(&stacks->stack_a, stacks->stack_b->content);
}
