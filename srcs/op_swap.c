/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:28:46 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/24 19:28:05 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_swap(t_stacks **s, char *op)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_strncmp(op, "sa", 2) == 0 || ft_strncmp(op, "ss", 2) == 0)
		stack_swap(&stacks->stack_a);
	if (ft_strncmp(op, "sb", 2) == 0 || ft_strncmp(op, "ss", 2) == 0)
		stack_swap(&stacks->stack_b);
	ft_putendl_fd(op, 1);
}

void	stack_swap(t_list **s)
{
	t_list	*stack;
	int		*aux;

	stack = *s;
	if (ft_lstsize(stack) < 2)
		return ;
	aux = stack->next->content;
	stack->next->content = stack->content;
	stack->content = aux;
}
