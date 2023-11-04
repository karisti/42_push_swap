/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:24:03 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/25 18:52:52 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_numbers(t_stacks **s)
{
	t_stacks	*stacks;
	long		size;

	stacks = *s;
	size = ft_lstsize(stacks->stack_a);
	ft_lstadd_front(&stacks->cklist_a, ft_lstnew((void *)size));
	while (stacks->cklist_a)
		from_a_to_b(&stacks, 1);
	while (stacks->cklist_b)
	{
		while (stacks->cklist_a && !stack_is_ordered(stacks->stack_a, 1))
			from_a_to_b(&stacks, 0);
		from_b_to_a(&stacks);
	}
}

void	from_a_to_b(t_stacks **s, int first_exec)
{
	t_stacks	*stacks;
	long		pending_nums;
	long		cksize;

	stacks = *s;
	pending_nums = (int)stacks->cklist_a->content;
	if ((int)stacks->cklist_a->content > 2)
	{
		if (!first_exec)
			stacks->cklist_a->content = (void *)get_last_disordered(
					stacks->stack_a, (int)stacks->cklist_a->content);
		cksize = (int)stacks->cklist_a->content / 2;
		process_chunk_a(&stacks, (int)stacks->cklist_a->content,
			cksize, first_exec);
		ft_lstadd_front(&stacks->cklist_b, ft_lstnew((void *)cksize));
		stacks->cklist_a->content -= cksize;
	}
	if ((int)stacks->cklist_a->content == 2 && (int)stacks->stack_a->content
		> (int)stacks->stack_a->next->content)
		op_swap(&stacks, "sa");
	if ((int)stacks->cklist_a->content <= 2)
		ft_lstrem(&stacks->cklist_a, stacks->cklist_a->content);
}

void	from_b_to_a(t_stacks **s)
{
	t_stacks	*stacks;
	long		cksize;

	stacks = *s;
	if ((int)stacks->cklist_b->content > 2)
	{
		cksize = (int)stacks->cklist_b->content / 2;
		if ((int)stacks->cklist_b->content % 2 == 0)
			cksize--;
		process_chunk_b(&stacks, (int)stacks->cklist_b->content, cksize);
		if (cksize > 1)
			ft_lstadd_front(&stacks->cklist_a, ft_lstnew((void *)cksize));
		stacks->cklist_b->content -= cksize;
	}
	if ((int)stacks->cklist_b->content == 2)
	{
		if ((int)stacks->stack_b->content < (int)stacks->stack_b->next->content)
			op_swap(&stacks, "sb");
		op_push(&stacks, "pa");
		stacks->cklist_b->content--;
	}
	if ((int)stacks->cklist_b->content == 1)
		op_push(&stacks, "pa");
	if ((int)stacks->cklist_b->content < 2)
		ft_lstrem(&stacks->cklist_b, stacks->cklist_b->content);
}

void	process_chunk_a(t_stacks **s, int cksize, int new_cksize, int first)
{
	t_stacks	*stacks;
	int			mid_num;
	int			rotate_count;

	stacks = *s;
	mid_num = get_mid_num(stacks->stack_a, cksize);
	rotate_count = 0;
	while (new_cksize)
	{
		if ((int)stacks->stack_a->content < mid_num)
		{
			op_push(&stacks, "pb");
			new_cksize--;
		}
		else if ((int)ft_lstlast(stacks->stack_a)->content < mid_num && first)
			op_reverse_rotate(&stacks, "rra");
		else
		{
			op_rotate(&stacks, "ra");
			rotate_count++;
		}
	}
	while ((!stacks->cklist_a || ft_lstsize(stacks->stack_a)
			> (int)stacks->cklist_a->content) && rotate_count--)
		op_reverse_rotate(&stacks, "rra");
}

void	process_chunk_b(t_stacks **s, int cksize, int new_cksize)
{
	t_stacks	*stacks;
	int			mid_num;
	int			rotate_count;

	stacks = *s;
	mid_num = get_mid_num(stacks->stack_b, cksize);
	rotate_count = 0;
	while (new_cksize)
	{
		if ((int)stacks->stack_b->content > mid_num)
		{
			op_push(&stacks, "pa");
			new_cksize--;
		}
		else
		{
			op_rotate(&stacks, "rb");
			rotate_count++;
		}
	}
	while (ft_lstsize(stacks->cklist_b) > 1 && rotate_count--)
		op_reverse_rotate(&stacks, "rrb");
}
