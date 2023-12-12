/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_exceptions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:31:46 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:57:23 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(int **stack_a)
{
	int	a;
	int	b;

	a = (*stack_a)[0];
	b = (*stack_a)[1];
	if (a > b)
		decide_move_stack_a("sa", stack_a, 2);
}

void	ft_sort_3(int **stack_a, int len_stack_a)
{
	int	ind_smallest;
	int	ind_biggest;

	ind_smallest = ft_get_smallest_ind(stack_a, len_stack_a);
	ind_biggest = ft_get_biggest_ind(stack_a, len_stack_a);
	if (ind_smallest == 0)
		ft_sort_3_opt_a(ind_biggest, stack_a);
	if (ind_smallest == 1)
		ft_sort_3_opt_b(ind_biggest, stack_a);
	if (ind_smallest == 2)
		ft_sort_3_opt_c(ind_biggest, stack_a);
}

void	ft_sort_5_a2b(int **stack_a, int **stack_b, int *struct_4)
{
	int		ind_smallest;
	char	*m_top_a;
	int		nb_smallest;

	m_top_a = malloc(sizeof(char) * 4);
	m_top_a[0] = '\0';
	m_top_a[1] = '\0';
	m_top_a[2] = '\0';
	m_top_a[3] = '\0';
	ind_smallest = ft_get_smallest_int(stack_a, struct_4[0]);
	struct_4[2] = top_stack (struct_4[0], ind_smallest);
	m_top_a = ft_strcpy(top_a_2s_move(struct_4[0], ind_smallest), m_top_a, 0);
	while (struct_4[2] > 0)
	{
		decide_move_stack_a(m_top_a, stack_a, struct_4[0]);
		struct_4[2]--;
	}
	decide_move_2_stacks("pb", stack_a, stack_b, struct_4);
	ind_smallest = 0;
	nb_smallest = (*stack_a)[0];
	free (m_top_a);
}

/*DESCRIPTION:
ft_sort_5 manages to sort the case when 5 integers are to be sorted.


👉 Remember! About struct_4:
· [0] = len_a
· [1] = len_b
· [2] = numof_moves_top_stack
· [3] = numof_moves_org_b
-------------------------------------------------*/
void	ft_sort_5(int **stack_a, int **stack_b, int *struct_4)
{
	ft_sort_5_a2b(stack_a, stack_b, struct_4);
	ft_sort_5_a2b(stack_a, stack_b, struct_4);
	ft_sort_3 (stack_a, 3);
	if ((*stack_b)[0] < (*stack_b)[1])
		decide_move_stack_b("sb", stack_b, 2);
	decide_move_2_stacks("pa", stack_a, stack_b, struct_4);
	decide_move_2_stacks("pa", stack_a, stack_b, struct_4);
}

/*DESCRIPTION:
case_mngmt function analyses and decides how to deal with the particular case
we've been given, based on the number of integers found among the total
sum of arguments.
----------------------------------------------------------------------------*/
int	case_mngmt(int numof_int, int **sa, int **sb, int *struct_4)
{
	if (numof_int == 1)
		return (0);
	if (numof_int == 2)
	{
		ft_sort_2(sa);
		return (0);
	}
	if (numof_int == 3)
	{
		ft_sort_3(sa, 3);
		return (0);
	}
	if (numof_int == 5)
	{
		ft_sort_5(sa, sb, struct_4);
		return (0);
	}
	return (1);
}
