/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:00:46 by karisti-          #+#    #+#             */
/*   Updated: 2021/10/02 17:59:58 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stacks **s, char *str)
{
	static int	i = 0;
	t_stacks	*stacks;

	stacks = *s;
	printf("\n________ %i  %s  ________\n\n", i, str);
	printf("STACK A:\n");
	ft_lstprint_nbr(stacks->stack_a);
	printf("\nSTACK B:\n");
	ft_lstprint_nbr(stacks->stack_b);
	printf("\n--------\n");
	printf("CHUNK LIST A:\n");
	ft_lstprint_nbr(stacks->cklist_a);
	printf("CHUNK LIST B:\n");
	ft_lstprint_nbr(stacks->cklist_b);
	printf("\n______________________\n\n");
	i++;
}

/*
	printf("_______________FIN_______________\n\n");
	//////////////////////////////////////////////////////////
	printf("*****************************************\n\n");
	printf("***************** LEAKS *****************\n\n");
	printf("*****************************************\n\n");
	system("leaks push_swap");
	printf("*****************************************\n\n");
*/

void	exit_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void	sort_3numbers(t_stacks **s)
{
	t_stacks	*stacks;

	stacks = *s;
	if ((long)stacks->stack_a->content
		< (long)ft_lstlast(stacks->stack_a)->content)
		op_swap(&stacks, "sa");
	while ((long)stacks->stack_a->content
		> (long)ft_lstlast(stacks->stack_a)->content)
		op_rotate(&stacks, "ra");
	if ((long)stacks->stack_a->content > (long)stacks->stack_a->next->content)
		op_swap(&stacks, "sa");
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	stacks = init_stacks();
	parse_numbers(&stacks, ++argv, --argc);
	if (stack_is_ordered(stacks->stack_a, 1))
		return (0);
	if (ft_lstsize(stacks->stack_a) == 3)
		sort_3numbers(&stacks);
	else
		sort_numbers(&stacks);
	free_stacks(&stacks);
	return (0);
}
