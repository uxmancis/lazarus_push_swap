/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:33:59 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:57:48 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_there_more_integers(char **argv, int *x_y, int len_arg)
{
	int	aux;

	aux = x_y[1];
	while (aux < len_arg)
	{
		if (ft_isdigit(argv[x_y[0]][x_y[1]]) == 1)
			return (x_y[1]);
		aux++;
	}
	return (0);
}

/*DESCRIPTION
are_there_smaller_values

Returns: 
0: NO smaller values in stack_b
1: YES there are smaller values than travelling number in stack_b
---------------------------------------------------------------------*/
int	are_there_smaller_values(int **stack_b, int len_b, int travel_nb)
{
	int	numof_smaller_values;
	int	i;

	numof_smaller_values = 0;
	i = 0;
	while (len_b > 0)
	{
		if ((*stack_b)[i] <= travel_nb)
			numof_smaller_values++;
		i++;
		len_b --;
	}
	if (numof_smaller_values == 0)
		return (0);
	else
		return (1);
}

/*DESCRIPTION:
ft_strcpy is used to copy src string to dst string.
src string = move_type that has been chosen to be executed
dst string = struct_2, where we will send the moves to be executed
			to call2moves (both moves for stack_a and stack_b are
			included). struct_2 is used as a pseudo-structure.
start = indicates in which part of struct_2 (dst string) will
the src string be copied.

👉 About struct_2:
· [0-2] = move_type_top_stack --> start = 0
· [3] = blank
· [4-6] = move_type_org_b --> start = 4
· [7] = '\0'
---------------------------------------------------------*/
char	*ft_strcpy(char *str_src, char *str_dst, int start)
{
	int	i;

	i = 0;
	while (str_src[i] != '\0')
	{
		str_dst[start] = str_src[i];
		i++;
		start++;
	}
	return (str_dst);
}

int	ft_get_value_biggest(int **stack_b, int len_b)
{
	int	i;
	int	value_biggest;

	i = 0;
	value_biggest = (*stack_b)[i];
	while (len_b > 0)
	{
		if ((*stack_b)[i] > value_biggest)
			value_biggest = (*stack_b)[i];
		i++;
		len_b--;
	}
	return (value_biggest);
}

/*DESCRIPTION:
index_biggest returns the index of the biggest value in the 
stack we pass as an argument.

We use it to get biggest value in stack_b. 

When? After travelling_nb is identified, we check which is next 
smallest value in stack_b. But, sometimes, 
there will NOT be any smaller value than travelling_nb in stack_b. 
In those cases, the way of organising stack_b
will be putting the biggest value on the top of it. In index_biggest 
we identify the value we want to put on the top of stack_b in order 
to receive travelling_nb, when this travelling_nb will become the 
new smallest value in stack_b.

Comments: 
1. line "while (len_b > 0)" //get the value of the biggest value 
in stack_b
2. line "while (keep_len_b > 0)" ////identificar el índice del biggest 
value, que es lo que nos interesa para poder ver cuál es el movimiento 
que vamos a necesitar hacer
---------------------------------------------------------------------*/
int	ft_index_biggest(int **stack_b, int len_b)
{
	int	value_biggest;
	int	ind_biggest;
	int	i;
	int	keep_len_b;

	keep_len_b = len_b;
	i = 0;
	value_biggest = ft_get_value_biggest(stack_b, len_b);
	i = 0;
	while (keep_len_b > 0)
	{
		if ((*stack_b)[i] == value_biggest)
		{
			ind_biggest = i;
			return (ind_biggest);
		}
		keep_len_b--;
		i++;
	}
	return (0);
}
