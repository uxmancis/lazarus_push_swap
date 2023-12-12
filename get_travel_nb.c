/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_travel_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:10:04 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:54:29 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION
sum_moves function returns the total number of movements a particular 
value from stack_a needs in order to travel to the correct position in stack_b.

For that, it will take into account the followings:
1. Number of movements value in stack_a needs in order to get to the 
top of stack_a
2. Number of movements stack_b needs in order to move and be ready for 
receiving value of stack_a
3. + 1 = push_b (pb) movement, to travel

Remember: 
· struct[0] = len_a
· struct[1] = len_b
· struct_4[4] = keep_len_a

ind = index
-------------------------------------------------------------------------*/
int	sum_moves(int **s_a, int ind, int **s_b, int *struct_4)
{
	int	numof_moves_top_stack;
	int	numof_moves_org_b;
	int	total_numof_moves;
	int	l_a;
	int	l_b;

	l_a = struct_4[4];
	l_b = struct_4[1];
	numof_moves_top_stack = top_stack (l_a, ind);
	numof_moves_org_b = org_b_2 (l_b, org_b_1(s_b, l_b, (*s_a)[ind]));
	total_numof_moves = numof_moves_top_stack + numof_moves_org_b + 1;
	return (total_numof_moves);
}

void	ft_getarr_sumof_moves(int **sa, int **sb, int *struct_4, int **arr)
{
	int	index;

	struct_4[4] = struct_4[0];
	index = 0;
	while (struct_4[0] > 0)
	{
		(*arr)[index] = sum_moves(sa, index, sb, struct_4);
		index++;
		(struct_4[0])--;
	}
}

int	ft_getnum_least_moves(int *arr, int len_a)
{
	int	index;
	int	numof_least_moves;

	index = 0;
	numof_least_moves = arr[0];
	while (len_a > 0)
	{
		if (arr[index] < numof_least_moves)
			numof_least_moves = arr[index];
		else
		{
			len_a--;
			index++;
		}
	}
	return (numof_least_moves);
}

int	ft_get_ind_tb(int *arr, int num)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (i);
}

/*DESCRIPTION
get_cheapest_nb function returns the index of number in stack_a that is going 
to travel to stack_b.
For doing so, it calculates which is the "cheapest" value of stack_a, meaning 
which is the value in stack_a which needs the least amount of movements to get 
to the correct position in stack_b.

Remember: 
· struct_4[0] = len_a
· struct_4[1] = len_b
· struct_4[4] = keep_len_a //un auxiliar que me acabo de inventar

Also: 
· arr = array with sum of total moves each position requires
· num = number of least moves, which is the smallest number in arr
---------------------------------------------------------------------------*/
int	get_cheapest_nb(int **stack_a, int **stack_b, int *struct_4)
{
	int	num;
	int	keep_len_a;
	int	*arr;
	int	index_travel_nb;

	arr = malloc(sizeof(int) *(struct_4[0]));
	keep_len_a = struct_4[0];
	ft_getarr_sumof_moves(stack_a, stack_b, struct_4, &arr);
	struct_4[0] = keep_len_a;
	num = ft_getnum_least_moves(arr, keep_len_a);
	index_travel_nb = ft_get_ind_tb(arr, num);
	free (arr);
	return (index_travel_nb);
}
