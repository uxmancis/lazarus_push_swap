/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:15:32 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:40:42 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	put_arr(int **stack, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		len--;
		printf("stack_a[%d] = %d\n", i, (*stack)[i]);
		i++;
	}
}

void	put_arr2(int **stack, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		len--;
		printf("stack_b[%d] = %d\n", i, (*stack)[i]);
		i++;
	}
}*/

void	ft_get_new_dst(int *new_dst, int **old_dst, int len)
{
	int	i;

	i = 0;
	while ((len - 1) > 0)
	{
		new_dst[i + 1] = (*old_dst)[i];
		i++;
		len--;
	}
}

void	ft_get_new_src(int *new_src, int **old_src, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		new_src[i] = (*old_src)[i + 1];
		i++;
		len--;
	}
}

void	ft_str_fit(char *str, char *new_str_fit)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			new_str_fit[i] = str[i];
		else
			break ;
		i++;
	}
	new_str_fit[i] = '\0';
}

/*DESCRIPTION
strcmp function compares str1 and str2.
Returns:
1: NOT the same, they are different
0: 100% same str.
------------------------------------------------*/
int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (1);
	}
	return (0);
}
