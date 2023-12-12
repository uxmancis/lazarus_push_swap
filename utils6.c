/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:40:49 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:51:54 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION:
isdigit function:
returns 1: if YES: '-', or [0-9]
returns 0: if NOT
-----------------------------------------------------------*/
int	ft_isdigit(char c)
{
	if (c == '-' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*DESCRIPTION:
numof_digits cuenta el número de dígitos total que tiene cada integer
---------------------------------------------------------------------*/
int	numof_digits(char **argv, int *x_y)
{
	int	counter;
	int	x;
	int	y;

	x = x_y[0];
	y = x_y[1];
	counter = 0;
	while (ft_isdigit(argv[x][y]) == 1)
	{
		counter++;
		y++;
	}
	return (counter);
}

/*DESCRIPTION:
Generates each str that will be sent as argument to our ft_atoi function. 
Each of the generated str-s will become each of the integers of our stack_a.

Received parameters: 
· x_y: x and y, which are the exact position of first digit of the integer 
found in fill_stack.
---------------------------------------------------------------------*/
char	*fill_str(char **argv, int *x_y, char *str, int counter)
{
	int	i;
	int	x;
	int	y;

	x = x_y[0];
	y = x_y[1];
	i = 0;
	while (counter > 0)
	{
		str[i] = argv[x][y];
		i++;
		y++;
		counter--;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_free_mem(int *stack_a, int	*stack_b, int	*struct_4)
{
	free (stack_a);
	free (stack_b);
	free (struct_4);
}
