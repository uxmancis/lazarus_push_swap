/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:37:40 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:54:53 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
The str that is converted into an integer contains
each integer. That's why if we can take advantage of 
if len > 11 (minimum value and max value of integer in C are
-214748364 and 2147483647).

Why do we do this? We've used long long int. However, an 
integer which is even bigger that those capabilities has to be stopped
as well. Then, we've taken advantage of the len of the string to 
identify that error and print "Error" if maximum and minimum values of
integers in C are surpassed along the arguments provided to our 
push_swap program.
---------------------------------------------------------------------*/
int	ft_atoi(char *str, int ***ind_error)
{
	int				i;
	long long int	result;

	if (ft_strlen(str) == 1)
		return (str[0] - 48);
	i = 0;
	result = 0;
	if (str[0] == '-')
		i = 1;
	if (ft_strlen(str) > 12)
		***ind_error = -1;
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	if (result > 2147483647 || result < (-2147483647))
		***ind_error = -1;
	return (result);
}

/*DESCRIPTION:
ft_smallest_int identifies which is the smallest integer in our stack 
and tells us what's its index.
---------------------------------------------------------------------*/
int	ft_get_smallest_int(int **stack_a, int len_stack_a)
{
	int	i;
	int	nb_smallest;
	int	index_smallest;

	i = 0;
	nb_smallest = (*stack_a)[0];
	index_smallest = 0;
	while (i < len_stack_a)
	{
		if ((*stack_a)[i] < nb_smallest)
		{
			nb_smallest = (*stack_a)[i];
			index_smallest = i;
		}
		i++;
	}
	return (index_smallest);
}

/*DESCRIPTION: 
numof_int function returns the number of integers we will find along 
the arguments, which we'll use to define the len of our stack_a.
In our project, we will also use this len for defining the size of stack_b.

Additional notes: 
- argc also counts name of executable (./a.out) as 1 argument, that's 
why we initialize x = 1-
- Primary loop (x < argc), then secondary loop for each argument based on 
its len
- counter++ after space, when digit or negative sign '-' are found
---------------------------------------------------------------------*/
int	ft_numof_int(int argc, char **argv)
{
	int	x;
	int	y;
	int	counter;
	int	len_arg;

	x = 1;
	counter = 0;
	while (x < argc)
	{
		len_arg = ft_strlen(argv[x]);
		y = 0;
		while (y < len_arg)
		{
			if (argv[x][y] != ' ')
			{
				counter++;
				while (argv[x][y] != ' ' && y < len_arg)
					y++;
			}
			y++;
		}
		x++;
	}
	return (counter);
}

/*DESCRIPTION:
isdigit_2 function:
returns 1: if NOT
returns 0: if YES: [0-9]
__________________________________*/
int	ft_isdigit_2(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

//assign_len functions assigns a value to len and keep_len variables
void	assign_len(int	*len, int *keep_len, char *arg)
{
	*len = ft_strlen(arg);
	*keep_len = *len;
}
