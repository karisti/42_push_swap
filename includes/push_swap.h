/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:27:40 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/25 18:59:00 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>

# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*cklist_a;
	t_list	*cklist_b;
}				t_stacks;

t_stacks	*init_stacks(void);
void		free_stacks(t_stacks **s);
void		free_single_stack(t_list **l);
void		check_valid_number(char *str);
void		check_duplicates(t_list **alst, long number);
int			parse_numbers(t_stacks **stacks, char *argv[], int argc);
void		op_swap(t_stacks **s, char *op);
void		stack_swap(t_list **s);
void		op_push(t_stacks **s, char *op);
void		stack_push_a(t_stacks **s);
void		stack_push_b(t_stacks **s);
void		op_rotate(t_stacks **s, char *op);
void		stack_rotate(t_list **s);
void		op_reverse_rotate(t_stacks **s, char *op);
void		stack_reverse_rotate(t_list **s);
int			stack_is_ordered(t_list *stack, int asc);
void		sort_numbers(t_stacks **s);
void		sort_3numbers(t_stacks **s);
int			get_mid_num(t_list *stack, int limit);
int			get_min_value(t_list **l);
int			get_stack_disord_idx(t_list *stack, t_stacks *stacks);
void		copy_stack(t_list **src, t_list **dst, int limit);
void		process_chunk_a(t_stacks **s, int cksize, int new_cksize,
				int first_exec);
void		process_chunk_b(t_stacks **s, int cksize, int new_cksize);
void		from_a_to_b(t_stacks **s, int first_exec);
void		from_b_to_a(t_stacks **s);
int			*lst_to_int_array(t_list *stack, int limit);
long		get_last_disordered(t_list *stack, int n);
void		exit_error(void);
// void		print_stacks(t_stacks **s, char *str);

#endif
