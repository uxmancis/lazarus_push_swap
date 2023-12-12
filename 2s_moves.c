/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2s_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:59:35 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/14 20:56:30 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRIPTION
top_stack_choose_move function indicates which is the type of movement the
travelling number will need to get to the top of the stack: "sa", "ra" or "rra".
-------------------------------------------------------------------------*/
char	*top_a_2s_move(int len, int index)
{
	char	*move_type;

	if (index >= len)
		return (0);
	if (index == (len - 2))
		move_type = "sa";
	if (index <= (len / 2))
		move_type = "ra";
	if (index > (len / 2) && index != len)
		move_type = "rra";
	return (move_type);
}

/*DESCRIPTION
org_stack_b_2s_move function indicates which is the type of movement the
travelling number will need to organise b stack: "rb" or "rrb".
____________________________________________________________________________*/
char	*org_b_2s_move(int len_b, int index_top_b)
{
	char	*move_type;

	if (index_top_b <= (len_b / 2))
		move_type = "rb";
	if (index_top_b > (len_b / 2))
		move_type = "rrb";
	return (move_type);
}
