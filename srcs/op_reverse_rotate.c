/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:28:46 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/24 19:25:41 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_reverse_rotate(t_stacks **s, char *op)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_strncmp(op, "rra", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		stack_reverse_rotate(&stacks->stack_a);
	if (ft_strncmp(op, "rrb", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		stack_reverse_rotate(&stacks->stack_b);
	ft_putendl_fd(op, 1);
}

void	stack_reverse_rotate(t_list **s)
{
	t_list	*stack;
	t_list	*last_elem;
	t_list	*aux;

	stack = *s;
	if (ft_lstsize(stack) < 2)
		return ;
	aux = stack;
	while (aux->next->next)
		aux = aux->next;
	last_elem = aux->next;
	aux->next = NULL;
	last_elem->next = stack;
	*s = last_elem;
}
