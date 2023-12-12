/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numof_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:01:29 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:52:25 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
top_stack returns the minimum number of movements (swap, rotate or 
reverse rotate) a number of a stack needs to get to the top of the stack 
(last position in array)

· len = len of stack
· index = position in stack of the number which numof_moves to get to the 
top of the stack
we want to analyse.

Depending on index, it movement type it's referring to differs: 
· Index = 0 --> No movement needed, 0 times
· Index = 1 --> Swap, 1 time
· Index <= len / 2 --> Rotate, n times
· Index > len / 2 --> Reverse rotate, n times
-----------------------------------------------------------------------------*/
int	top_stack(int len, int index)
{
	int	numof_moves;

	if (index >= len)
		return (0);
	if (index == 0)
		numof_moves = 0;
	if (index == 1)
		numof_moves = 1;
	if (index <= (len / 2))
		numof_moves = index;
	if (index > (len / 2) && index != len)
		numof_moves = (len - index);
	return (numof_moves);
}

/*DESCRIPTION:
1. org_stack_b_1 function decides in which way will we organise the 
stack_b in order to receive travelling number from stack_a.

There are 2 ways, depending on the answer to the question: "Is there 
any value in stack_b which is smaller than the travelling number?"
YES: 1. get next smallest number, 2. move it to the top
NO: 1. identify biggest value in stack_b, 2. move it to the top

2. Also, it returns the number of movements it will take to organise stack_b.
-----------------------------------------------------------------------------*/
int	org_b_1(int **stack_b, int len_b, int travel_nb)
{
	int	index_next_smallest;
	int	index_biggest;
	int	value_next_smallest;

	if (are_there_smaller_values(stack_b, len_b, travel_nb) == 1)
	{
		value_next_smallest = ft_nb_ns(stack_b, len_b, travel_nb);
		index_next_smallest = ft_index_ns (stack_b, len_b, value_next_smallest);
		return (index_next_smallest);
	}
	if (are_there_smaller_values(stack_b, len_b, travel_nb) == 0)
	{
		index_biggest = ft_index_biggest(stack_b, len_b);
		return (index_biggest);
	}
	return (0);
}

/*DESCRITION:
org_stack_b function returns the number of movements it takes to stack b 
to get ready to receive travelling number from stack a.

For that, it calculates which is the least number of movements the value 
with index_top_stack needs to get to the top.
This value can be either of the following 2: 
1. next smallest number in stack_b: when there are smaller numbers than 
travel_nb in stack_b)
2. biggest number in stack_b: when there is NOT any smaller number than 
travel_nb in stack_b
____________________________________________________________________________*/
int	org_b_2(int len_b, int index_top_stack)
{
	int	numof_moves;

	if (index_top_stack <= (len_b / 2))
		numof_moves = index_top_stack;
	if (index_top_stack > (len_b / 2))
		numof_moves = len_b - index_top_stack;
	return (numof_moves);
}
