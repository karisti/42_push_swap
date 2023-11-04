/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:22:03 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/25 18:59:39 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parse_numbers(t_stacks **s, char *argv[], int argc)
{
	t_stacks	*stacks;
	long		nbr;

	stacks = *s;
	while (argc-- > 0)
	{
		check_valid_number(*argv);
		nbr = ft_atol(*argv);
		if (nbr < -2147483648 || nbr > 2147483647)
			exit_error();
		check_duplicates(&stacks->stack_a, nbr);
		ft_lstadd_back(&stacks->stack_a, ft_lstnew((void *)nbr));
		argv++;
	}
	return (0);
}

void	check_valid_number(char *str)
{
	if (!ft_isdigit(*str) && ft_strncmp(str++, "-", 1) != 0 )
		exit_error();
	if (strlen(str) <= 0)
		exit_error();
	while (*str)
	{
		if (!ft_isdigit(*(str++)))
			exit_error();
	}
}

void	check_duplicates(t_list **alst, long number)
{
	t_list	*lista;

	lista = *alst;
	if (lista)
	{
		while (lista->next != NULL)
		{
			if ((int)lista->content == number)
				exit_error();
			lista = lista->next;
		}
		if ((int)lista->content == number)
			exit_error();
	}
}
