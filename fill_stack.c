/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:27:43 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 18:00:54 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
fill_list function function assigns value to each position of array of 
integers (our future stack_a).
For doing so, fill_list calls to fill_str and ft_atoi functions.

Gets as parameters:
· x_y --> x and y, which are the position of the first digit that has been 
found in fill_stack function (which calls to our fill_list)
---------------------------------------------------------------------------*/
int	fill_list(char **argv, int *x_y, int **ind_error)
{
	char	*str;
	int		result;
	int		nb;

	str = malloc(sizeof(char) * (numof_digits(argv, x_y) + 1));
	str = fill_str(argv, x_y, str,
			numof_digits(argv, x_y));
	if (checker_4(str) == -1)
		**ind_error = -1;
	x_y[1] = x_y[1] + ft_strlen(str);
	result = ft_atoi(str, &ind_error);
	nb = result;
	free (str);
	return (nb);
}

/*DESCRIPTION:
ft_duplicate function indicates whether if an integer is repeated on an array.

If YES, it returns 1.
Else, (no duplicated integers found) it returns 0.
--------------------------------------------------------------------------*/
int	ft_duplicate(int *arr, int len)
{
	int	i;
	int	y;

	i = 0;
	while (i < len)
	{
		y = i + 1;
		while (y < len)
		{
			if (arr[i] == arr[y])
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

/*DESCRIPTION:
ft_is_sorted checks whether is stack_a is already sorted or not.
Returns:
1: YES, it is sorted
0: NO, it's not sorted

If YES (1), then our push_swap program will print nothing on the standard output
and program will stop executing.
-----------------------------------------------------------------------*/
int	ft_is_sorted(int *stack_a, int len_stack_a)
{
	int	i;

	i = 1;
	while (i < len_stack_a)
	{
		if (stack_a[i] > stack_a[i -1])
			i++;
		else
			return (0);
	}
	return (1);
}

/*DESCRIPTION:
checker_4 makes sure there is no negative sign after a digit in 
each of the strings that are analysed.

How does it do it? If a digit is found [0-9], and there is still 
more len to analyse, then checkes that next character is not '-' 
negative sign.
· Error FOUND: returns -1
· No error was found: returns 0

If no error (negative sign intercalado) has been found, the string 
will become integer for our future stack in ft_atoi.
--------------------------------------------------------------------------*/
int	checker_4(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (ft_isdigit_2(str[i]) == 0 && i < len)
		{
			if (str[i + 1] == '-')
				return (-1);
		}
		i++;
	}
	return (0);
}

/*DESCRIPTION:
fill_stack function updates arr_pre_check (before called: list_pre_checker2)
by filling it with values.

It iterates through every single argument along argv (primary loop: x < argc).
   > It iterates through each of the arguments with secondary loops: len_arg > 0
      > Each time it finds a digit or negative sign (ft_isdigit == 1)

y++ until it finds a digit [0-9] or a negative '-' sign.
--------------------------------------------------------------------------*/
void	fill_stack(int *arr_pre_check, int argc, char **argv, int *ind_error)
{
	int		x_y[2];
	int		m;
	int		len_arg;
	int		keep_len_arg;

	m = 0;
	x_y[0] = 1;
	while (x_y[0] < argc)
	{
		assign_len(&len_arg, &keep_len_arg, argv[x_y[0]]);
		x_y[1] = 0;
		while (len_arg > 0)
		{
			while (argv[x_y[0]][x_y[1]] == ' ' && x_y[1] < keep_len_arg)
				x_y[1]++;
			if (ft_isdigit(argv[x_y[0]][x_y[1]]) == 1)
			{
				arr_pre_check[m] = fill_list(argv, x_y, &ind_error);
				m++;
			}
			len_arg--;
		}
		x_y[0]++;
	}
}
