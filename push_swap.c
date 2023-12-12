/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:22:23 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 16:33:09 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(int *sa, int argc, char **argv, int ind_error)
{
	if (ft_is_sorted (sa, ft_numof_int(argc, argv)) == 1 || ind_error == -1)
	{
		if (ind_error == -1)
			write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

/*DESCRIPTION:
is_there_error writes Error message in standard output and
tells push_swap function if it has to end prgram.
------------------------------------------------------------*/
int	is_there_error(int argc, char **argv)
{
	if (checkers_index (argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	push_swap_2(int *stack_a, int *stack_b, int *struct_4, int numof_int)
{
	if (case_mngmt(numof_int, &stack_a, &stack_b, struct_4) == 0)
	{
		ft_free_mem(stack_a, stack_b, struct_4);
		return (0);
	}
	sort_it(&stack_a, &stack_b, struct_4);
	ft_free_mem(stack_a, stack_b, struct_4);
	return (0);
}

/*DESCRIPTION:

👉 About struct_4:
· [0] = len_a
· [1] = len_b
· [2] = numof_moves_top_stack
· [3] = numof_moves_org_b
· [4] = keep_len_a //un auxiliar que me acabo de inventar
------------------------------------------------------------*/
int	push_swap(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	*struct_4;
	int	ind_error;
	int	numof_int;

	if (argc == 1 || is_there_error (argc, argv) == 1)
		return (0);
	struct_4 = malloc(sizeof(int) * 5);
	struct_4[0] = ft_numof_int(argc, argv);
	struct_4[1] = 0;
	stack_a = malloc(sizeof(int) * (struct_4[0]));
	stack_b = malloc(sizeof(int) * (struct_4[1]));
	ind_error = 0;
	fill_stack(stack_a, argc, argv, &ind_error);
	if (check_sorted(stack_a, argc, argv, ind_error) == 1)
	{
		ft_free_mem(stack_a, stack_b, struct_4);
		return (0);
	}
	numof_int = ft_numof_int(argc, argv);
	push_swap_2(stack_a, stack_b, struct_4, numof_int);
	return (0);
}
