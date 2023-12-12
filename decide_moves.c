/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:52:35 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:58:26 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
decide_move_stack_a function calls to moves and writes them once they've 
been executed.
We use decide_move_stack_a for movements related to stack_a. 

Explanation: 
We had to divide the function due to the number of lines, and decided to 
separate it the following way: stack_a moves (decide_move_stack_a), then 
stack_b moves, and finally pa and pb, which involve both of the stacks.

👉 About struct_4:
· [0] = len_a
-------------------------------------------------------------------*/
void	decide_move_stack_a(char *move_type, int **stack_a, int len_a)
{
	char	*move_type_fit;

	move_type_fit = malloc(sizeof(char) * 4);
	ft_str_fit (move_type, move_type_fit);
	if (ft_strcmp(move_type_fit, "sa") == 0)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (ft_strcmp(move_type_fit, "ra") == 0)
	{
		rotate(stack_a, len_a);
		write(1, "ra\n", 3);
	}
	else if (ft_strcmp(move_type_fit, "rra") == 0)
	{
		reverse_rotate(stack_a, len_a);
		write(1, "rra\n", 4);
	}
	free (move_type_fit);
}

/*DESCRIPTION:
decide_move_stack_b function calls to moves and writes them. 
We use decide_move_stack_b for movements related to stack_b. 

Explanation: 
We had to divide the function due to the number of lines, and 
decided to separate it the following way: stack_a moves (decide_move_stack_a), 
then stack_b moves (decide_move_stack_b), and finally pa and pb, 
which involve both of the stacks.

👉 About struct_4:
· [1] = len_b
-------------------------------------------------------------------*/
void	decide_move_stack_b(char *move_type, int **stack_b, int len_b)
{
	char	*move_type_fit;

	move_type_fit = malloc(sizeof(char) * 4);
	ft_str_fit (move_type, move_type_fit);
	if (ft_strcmp(move_type, "sb") == 0)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
	else if (ft_strcmp(move_type, "rb") == 0)
	{
		rotate(stack_b, len_b);
		write(1, "rb\n", 3);
	}
	else if (ft_strcmp(move_type, "rrb") == 0)
	{
		reverse_rotate(stack_b, len_b);
		write(1, "rrb\n", 4);
	}
	free (move_type_fit);
}

/*DESCRIPTION:
decide_move_both_stacks function calls to moves and writes them. 
We use decide_move_both_stacks for movements related to stack_b. 

m = movement type 

Explanation: 
We had to divide the function due to the number of lines, and 
decided to separate it the following way: stack_a moves (decide_move_stack_a), 
then stack_b moves (decide_move_stack_b), and finally pa and pb, 
(decide_move_both_stacks) which involve both of the stacks.
-------------------------------------------------------------------*/
void	decide_move_2_stacks(char *m, int **s_a, int **s_b, int *struct_4)
{
	char	*move_type_fit;

	move_type_fit = malloc(sizeof(char) * 4);
	ft_str_fit (m, move_type_fit);
	if (ft_strcmp(move_type_fit, "pa") == 0)
	{
		push_pa(s_b, s_a, struct_4);
		write(1, "pa\n", 3);
	}
	else if (ft_strcmp(move_type_fit, "pb") == 0)
	{
		push_pb(s_a, s_b, struct_4);
		write(1, "pb\n", 3);
	}
	free (move_type_fit);
}
