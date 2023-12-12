/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:23:59 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:56:58 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
checker_2 makes sure that there are no duplicated numbers
along the arguments.
Returns: 
1: error found
0: NO error found, OK!

How?
1. Convert arguments in integers of an array
    1.0 counts how many integers are among arguments (counter)
    1.1 allocates "counter" size memory for int *stack_a
    1.1 splits numbers of arguments. Every space = split!
    1.2 each number = 1 position of array as integer
2. Compares integers (is there any value repeated? YES/NO)
---------------------------------------------------------------*/
int	checker_last(int argc, char **argv)
{
	int	*list_pre_checker2;
	int	len_stack;
	int	ind;

	ind = 0;
	len_stack = ft_numof_int(argc, argv);
	list_pre_checker2 = malloc(sizeof(int) * 10000);
	fill_stack(list_pre_checker2, argc, argv, &ind);
	if (ind == -1)
	{
		free (list_pre_checker2);
		return (1);
	}
	if (ft_duplicate(list_pre_checker2, len_stack) == 1)
	{
		free (list_pre_checker2);
		return (1);
	}
	free (list_pre_checker2);
	return (0);
}

/*DESCRIPTION:
checker_3 makes sure none of the arguments provided to our push_swap
program is ""
--------------------------------------------------------------------*/
int	checker_3(int argc, char **argv)
{
	int	x;

	x = 1;
	while (x < argc)
	{
		if (ft_strlen(argv[x]) == 0)
			return (1);
		else
			x++;
	}
	return (0);
}

/*DESCRIPTION:
checker_2 checks whether if after every single negative sign '-'
only digits [0-9] are allowed. That means any space or '-' after 
a negative sign will lead to Error.
---------------------------------------------------------------*/
int	checker_2(int argc, char **argv)
{
	int	x;
	int	y;
	int	aux;

	x = 1;
	while (x < argc)
	{
		y = 0;
		while (argv[x][y] != '\0')
		{
			if (argv[x][y] == '-')
			{
				aux = ft_isdigit_2((char)argv[x][y + 1]);
				if (aux == 0)
					y++;
				else
					return (1);
			}
			else
				y++;
		}
		x++;
	}
	return (0);
}

/*DESCRIPTION:
checker_1 makes sure that only digits (0-9), space ' ' and negative sign '-'
are found along the arguments and returns a integer indicating whether if
the error has been found or not.
1: error found
0: NO error found, OK!
--------------------------------------------------------------------------*/
int	checker_1(int argc, char **argv)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	while (x < argc)
	{
		y = 0;
		while (argv[x][y] != '\0')
		{
			if (ft_isdigit(argv[x][y]) == 1 || argv[x][y] == (char)32)
				y++;
			else
				return (1);
		}
		x++;
	}
	return (0);
}

/*DESCRITION:
checkers_index calls to each of the checkers:
· checker_1: only digits [0-9], ' ' space and '-' negative sign 
are allowed as arguments.
· checker_last: duplicated integers are not allowed as arguments.

 If NONE of the errors actually happens, then
it returns a 0.

If any of the checkers tells there IS an ERROR, checkers_index returns 1.
--------------------------------------------------------------------------*/
int	checkers_index(int argc, char **argv)
{
	if (checker_1(argc, argv) == 0)
	{
		if (checker_2(argc, argv) == 0)
		{
			if (checker_3(argc, argv) == 0)
			{
				if (checker_last(argc, argv) == 0)
					return (0);
				return (1);
			}
			return (1);
		}
		return (1);
	}
	return (1);
}
