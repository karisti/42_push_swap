/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:02:20 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/24 20:21:30 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->cklist_a = NULL;
	stacks->cklist_b = NULL;
	return (stacks);
}

void	free_stacks(t_stacks **s)
{
	t_stacks	*stacks;
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*cklist_a;
	t_list		*cklist_b;

	stacks = *s;
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	cklist_a = stacks->cklist_a;
	cklist_b = stacks->cklist_b;
	free_single_stack(&stack_a);
	free_single_stack(&stack_b);
	free_single_stack(&cklist_a);
	free_single_stack(&cklist_b);
	free(stacks);
}

void	free_single_stack(t_list **l)
{
	t_list	*stack;

	stack = *l;
	while (stack)
		ft_lstrem(&stack, stack->content);
}

void	copy_stack(t_list **src, t_list **dst, int limit)
{
	t_list	*source;
	int		i;

	source = *src;
	i = 0;
	while (source && i < limit)
	{
		ft_lstadd_back(&(*dst), ft_lstnew(source->content));
		source = source->next;
		i++;
	}
}

int	get_min_value(t_list **l)
{
	t_list	*lista;
	void	*min;

	lista = *l;
	min = lista->content;
	while (lista)
	{
		if ((int)lista->content < (int)min)
			min = lista->content;
		lista = lista->next;
	}
	lista = *l;
	ft_lstrem(&lista, min);
	*l = lista;
	return ((int)min);
}
