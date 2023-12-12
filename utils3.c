/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:32:18 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:44:11 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getnumof_smaller_values(int **stack_b, int len_b, int travel_nb)
{
	int	i;
	int	numof_smaller_values;

	i = 0;
	numof_smaller_values = 0;
	while (len_b > 0)
	{
		if ((*stack_b)[i] <= travel_nb)
			numof_smaller_values++;
		i++;
		len_b --;
	}
	return (numof_smaller_values);
}

void	ft_fill_arr(int **arr, int len_b, int travel_nb, int **stack_b)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (len_b > 0)
	{
		if ((*stack_b)[i] < travel_nb)
		{
			(*arr)[y] = (*stack_b)[i];
			y++;
		}
		i++;
		len_b--;
	}
}

/*DESCRIPTION:
ft_nb_ns function returns the value of the number in stack b that is 
the biggest, among the ones that are smaller than the travel_nb. 

It compares the travel_nb from stack a with the values in stack b 
and returns the "next smallest" value of stack b. 
---------------------------------------------------------------------*/
int	ft_nb_ns(int **stack_b, int len_b, int travel_nb)
{
	int	num;
	int	*arr_smaller_values_tmp;
	int	keep_len_b;
	int	y;
	int	biggest_among_smallers;

	keep_len_b = len_b;
	num = ft_getnumof_smaller_values(stack_b, len_b, travel_nb);
	arr_smaller_values_tmp = malloc(sizeof(int) * (num + 4));
	ft_fill_arr(&arr_smaller_values_tmp, keep_len_b, travel_nb, stack_b);
	y = 0;
	biggest_among_smallers = arr_smaller_values_tmp[y];
	while (num > 0)
	{
		if (arr_smaller_values_tmp[y] > biggest_among_smallers)
			biggest_among_smallers = arr_smaller_values_tmp[y];
		y++;
		num--;
	}
	free (arr_smaller_values_tmp);
	return (biggest_among_smallers);
}

/*DESCRIPTION:
ft_index_ns function gets a value from stack b as an argument 
and returns its index.

In our implementation, we will use it to get the indext of the "next smallest"
value in stack b, based on the travelling number from stack a.
---------------------------------------------------------------------*/
int	ft_index_ns(int **stack_b, int len_b, int value_next_smallest)
{
	int	index;

	index = 0;
	while (len_b > 0)
	{
		if ((*stack_b)[index] == value_next_smallest)
			return (index);
		len_b--;
		index++;
	}
	return (0);
}

/*DESCRIPTION:
ft_get_move function gets src string, which contains movements for 
both stacks and returns the one movement we are looking for 
(either stack A's move or B' move).
---------------------------------------------------------------------*/
char	*ft_get_move(char	*src, char	*move, int start)
{
	int	i;

	i = 0;
	while (src[start] == 'r' || src[start] == 'a'
		|| src[start] == 's' || src[start] == 'b')
	{
		move[i] = src[start];
		start++;
		i++;
	}
	move[i] = '\0';
	return (move);
}
