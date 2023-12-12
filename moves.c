/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:14:01 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 16:28:06 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
push, pb (From a to b): Take the first element at the top of a and put it 
at the top of b.

stack_src = A
stack_dst = B

Remember: 
· struct_4[0] = len_a
· struct_4[1] = len_b
-------------------------------------------------------------------------*/
void	push_pb(int **stack_src, int **stack_dst, int *struct_4)
{
	int	tmp;
	int	*new_stack_src;
	int	*new_stack_dst;
	int	local_len_src;
	int	local_len_dst;

	struct_4[0] = struct_4[0] - 1;
	local_len_src = struct_4[0];
	tmp = (*stack_src)[0];
	new_stack_src = malloc(sizeof(int) * struct_4[0]);
	ft_get_new_src(new_stack_src, stack_src, local_len_src);
	free(*stack_src);
	*stack_src = new_stack_src;
	struct_4[1] = struct_4[1] + 1;
	local_len_dst = struct_4[1];
	new_stack_dst = malloc(sizeof(int) * (struct_4[1]));
	ft_get_new_dst(new_stack_dst, stack_dst, local_len_dst);
	new_stack_dst[0] = tmp;
	free(*stack_dst);
	*stack_dst = new_stack_dst;
}

/*DESCRIPTION:
push, pa (From b to a): stack_b[0] to stack_a[0]

stack_src = B
stack_dst = A

Remember: 
· struct_4[0] = len_a
· struct_4[1] = len_b
-------------------------------------------------------------------------*/
void	push_pa(int **stack_src, int **stack_dst, int *struct_4)
{
	int	tmp;
	int	*new_stack_src;
	int	*new_stack_dst;
	int	local_len_src;
	int	local_len_dst;

	struct_4[1] = struct_4[1] - 1;
	local_len_src = struct_4[1];
	tmp = (*stack_src)[0];
	new_stack_src = malloc(sizeof(int) * struct_4[1]);
	ft_get_new_src(new_stack_src, stack_src, local_len_src);
	free(*stack_src);
	*stack_src = new_stack_src;
	struct_4[0] = struct_4[0] + 1;
	local_len_dst = struct_4[0];
	new_stack_dst = malloc(sizeof(int) * (struct_4[0]));
	ft_get_new_dst(new_stack_dst, stack_dst, local_len_dst);
	new_stack_dst[0] = tmp;
	free(*stack_dst);
	*stack_dst = new_stack_dst;
}

void	reverse_rotate(int **stack, int len)
{
	int	tmp;
	int	i;
	int	keep_len;

	keep_len = len;
	tmp = (*stack)[len - 1];
	i = 1;
	while (len > 1)
	{
		(*stack)[keep_len - i] = (*stack)[keep_len - (i + 1)];
		i++;
		len--;
	}
	(*stack)[0] = tmp;
}

//rotate: 1 stack is involved. Len of array doesn't change.
void	rotate(int **stack, int len)
{
	int	tmp;
	int	keep_len;
	int	i;

	keep_len = len;
	tmp = (*stack)[0];
	i = 1;
	while (len > 1)
	{
		(*stack)[i - 1] = (*stack)[i];
		i++;
		len--;
	}
	(*stack)[keep_len - 1] = tmp;
}

//swap: 1 stack is involved. Len of array doesn't change.
void	swap(int **stack)
{
	int	tmp;

	tmp = (*stack)[0];
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = tmp;
}
