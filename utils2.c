/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:29:44 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:56:22 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_biggest_ind(int **stack_a, int len_a)
{
	int	i;
	int	nb_biggest;
	int	ind_biggest;

	i = 0;
	nb_biggest = (*stack_a)[0];
	ind_biggest = 0;
	while (i < len_a)
	{
		if ((*stack_a)[i] > nb_biggest)
		{
			nb_biggest = (*stack_a)[i];
			ind_biggest = i;
		}
		i++;
	}
	return (ind_biggest);
}

int	ft_get_smallest_ind(int **stack_a, int len_a)
{
	int	i;
	int	nb_smallest;
	int	ind_smallest;

	i = 0;
	nb_smallest = (*stack_a)[0];
	ind_smallest = 0;
	while (i < len_a)
	{
		if ((*stack_a)[i] < nb_smallest)
		{
			nb_smallest = (*stack_a)[i];
			ind_smallest = i;
		}
		i++;
	}
	return (ind_smallest);
}

void	ft_sort_3_opt_a(int ind_biggest, int **stack_a)
{
	if (ind_biggest == 1)
	{
		decide_move_stack_a("sa", stack_a, 3);
		decide_move_stack_a("ra", stack_a, 3);
	}
}

void	ft_sort_3_opt_b(int ind_biggest, int **stack_a)
{
	if (ind_biggest == 0)
		decide_move_stack_a("ra", stack_a, 3);
	if (ind_biggest == 2)
		decide_move_stack_a("sa", stack_a, 3);
}

void	ft_sort_3_opt_c(int ind_biggest, int **stack_a)
{
	if (ind_biggest == 0)
	{
		decide_move_stack_a("sa", stack_a, 3);
		decide_move_stack_a("rra", stack_a, 3);
	}
	if (ind_biggest == 1)
		decide_move_stack_a("rra", stack_a, 3);
}
