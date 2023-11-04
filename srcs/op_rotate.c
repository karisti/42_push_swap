/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:28:46 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/24 19:27:01 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rotate(t_stacks **s, char *op)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_strncmp(op, "ra", 2) == 0 || ft_strncmp(op, "rr", 2) == 0)
		stack_rotate(&stacks->stack_a);
	if (ft_strncmp(op, "rb", 2) == 0 || ft_strncmp(op, "rr", 2) == 0)
		stack_rotate(&stacks->stack_b);
	ft_putendl_fd(op, 1);
}

void	stack_rotate(t_list **s)
{
	t_list	*stack;
	t_list	*first_elem;

	stack = *s;
	if (ft_lstsize(stack) < 2)
		return ;
	first_elem = stack;
	stack = stack->next;
	first_elem->next = NULL;
	ft_lstlast(stack)->next = first_elem;
	*s = stack;
}
