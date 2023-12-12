/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:31:03 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:53:46 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
1. First, a2b function gets which is the number that is going to travel 
from stack a to stack b.

2. Then, it calls to which_moves function in order to decide which movements 
will be needed to make the number travel from stack_a to stack_b.
-----------------------------------------------------------------*/
void	a2b(int **stack_a, int **stack_b, int *struct_4)
{
	int	index_travel_nb;

	index_travel_nb = get_cheapest_nb(stack_a, stack_b, struct_4);
	which_moves(stack_a, stack_b, struct_4, index_travel_nb);
}

/*DESCRIPTION:
ft_sort_it_first takes the first 2 steps to sorting our stack_a: 

1.- pb x 2
2.- n times pushes rest of integers in stack_a to stack_b 1 by 1
by calling a2b.

After this first 2 steps, 1 single integer is left in stack_a.
-----------------------------------------------------------------*/
void	ft_sort_it_start(int **stack_a, int **stack_b, int *struct_4)
{
	int	len_a;

	decide_move_2_stacks("pb", stack_a, stack_b, struct_4);
	decide_move_2_stacks("pb", stack_a, stack_b, struct_4);
	len_a = struct_4[0] - 1;
	while (len_a > 0)
	{
		a2b(stack_a, stack_b, struct_4);
		len_a--;
	}
}

/*DESCRIPTION: 
ft_sort_it_last_a2b pushes the last integer left in stack_a
to stack_b, making stack_b being organised for receiving the last 
integer.

After this process, all of the integers will be in stack_b.
-----------------------------------------------------------------*/
void	ft_sort_it_last_a2b(int **stack_a, int **stack_b, int *struct_4)
{
	int		travel_nb;
	int		index_top_b;
	int		numof_moves_org_b;
	char	*move_type_org_b;

	travel_nb = (*stack_a)[0];
	index_top_b = org_b_1 (stack_b, struct_4[1], travel_nb);
	numof_moves_org_b = org_b_2 (struct_4[1], index_top_b);
	if (numof_moves_org_b == 0)
		decide_move_2_stacks("pb", stack_a, stack_b, struct_4);
	else
	{
		move_type_org_b = org_b_2s_move (struct_4[1], index_top_b);
		while (numof_moves_org_b > 0)
		{
			decide_move_stack_b(move_type_org_b, stack_b, struct_4[1]);
			numof_moves_org_b--;
		}
		decide_move_2_stacks("pb", stack_a, stack_b, struct_4);
	}
}

/*DESCRIPTION: 
ft_sort_it_finish_b2a function pushes all the integers from stack_b
back to stack_a so that they are sorted.

For doing so, it identifies biggest integer in stack_b, as it will
be the first integer being pushed back to stack_a.

Once this process is done, our stack_a will have its integers sorted
and our push_swap program will have completed its objective.
-----------------------------------------------------------------*/
void	ft_sort_it_finish_b2a(int **stack_a, int **stack_b, int *struct_4)
{
	int		index_biggest_in_stack_b;
	int		index_top_b;
	int		numof_moves_org_b;
	char	*move_type_org_b;
	int		keep_len_b;

	index_biggest_in_stack_b = ft_index_biggest (stack_b, struct_4[1]);
	index_top_b = index_biggest_in_stack_b;
	numof_moves_org_b = org_b_2 (struct_4[1], index_top_b);
	move_type_org_b = org_b_2s_move (struct_4[1], index_top_b);
	while (numof_moves_org_b > 0)
	{
		decide_move_stack_b(move_type_org_b, stack_b, struct_4[1]);
		numof_moves_org_b--;
	}
	keep_len_b = struct_4[1];
	while (keep_len_b > 0)
	{
		decide_move_2_stacks("pa", stack_a, stack_b, struct_4);
		keep_len_b--;
	}
}

/*DESCRIPTION:

👉 About struct_4:
· [0] = len_a
· [1] = len_b
· [2] = numof_moves_top_stack
· [3] = numof_moves_org_b

👉 About struct_2:
· First, (from [0] on) = move_type_top_stack
· Then, (from [4] on) = move_type_org_b
-----------------------------------------------------------------*/
void	sort_it(int **stack_a, int **stack_b, int *struct_4)
{
	ft_sort_it_start(stack_a, stack_b, struct_4);
	ft_sort_it_last_a2b(stack_a, stack_b, struct_4);
	ft_sort_it_finish_b2a(stack_a, stack_b, struct_4);
}
