/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:13:10 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 16:09:48 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*DESCRITION:
call2moves function gets the instructions of moves to be executed and 
passes them to: 
1. decide_move_stack_a
2. decide_move_stack_b
3. decide_move_both_stacks

These 3 functions will call directly to the moves by indicating 
which stack should be updated (a or b) + in which way (s, r, rr, p).

Remember: 
👉 About struct_4:
· [0] = len_a
· [1] = len_b
· [2] = numof_moves_top_stack
· [3] = numof_moves_org_b

👉 About struct_2:
· [0] = move_type_top_stack
· [1] = move_type_org_b
----------------------------------------------------------------*/
void	call2moves(int **stack_a, int **stack_b, int *struct_4, char *struct_2)
{
	char	*move_type_top_a;
	char	*move_type_org_b;
	char	*last_move;

	move_type_top_a = malloc(sizeof(char) * 4);
	move_type_top_a = ft_get_move(struct_2, move_type_top_a, 0);
	move_type_org_b = malloc(sizeof(char) * 4);
	move_type_org_b = ft_get_move(struct_2, move_type_org_b, 4);
	last_move = "pb";
	while (struct_4[2] > 0)
	{
		decide_move_stack_a(move_type_top_a, stack_a, struct_4[0]);
		struct_4[2]--;
	}
	while (struct_4[3] > 0)
	{
		decide_move_stack_b(move_type_org_b, stack_b, struct_4[1]);
		struct_4[3]--;
	}
	decide_move_2_stacks(last_move, stack_a, stack_b, struct_4);
	free (move_type_top_a);
	free (move_type_org_b);
}

/*DESCRIPTION:
which_moves generates intructions to send to call2moves function. It indicates
which movements and how many movements are going to be executed.

It receives de index of the travelling number (which has already being decided)
and based on stack_len and the index, decides which is the optimal way of 
sorting the stack, by choosing the moves to be called.

Remember: 
👉 About struct_4
· [0] = len_a
· [1] = len_b
· [2] = numof_moves_top_stack
· [3] = numof_moves_org_b

👉 ind_t_nb = index of travelling number (from stack A to B)

👉 About struct_2:
· [0-2] = move_type_top_stack
· [3] = blank
· [4-6] = move_type_org_b
· [7] = '\0'
----------------------------------------------------------------------------*/
void	which_moves(int **stack_a, int **stack_b, int *struct_4, int ind_t_nb)
{
	int		ind_top_b;
	char	*struct_2;
	char	*move_type_top_a;
	int		i;

	struct_2 = malloc(sizeof(char) * 8);
	i = 0;
	while (i < 8)
	{
		struct_2[i] = '\0';
		i++;
	}
	struct_2[7] = '\0';
	struct_4[2] = top_stack (struct_4[0], ind_t_nb);
	move_type_top_a = top_a_2s_move(struct_4[0], ind_t_nb);
	struct_2 = ft_strcpy(move_type_top_a, struct_2, 0);
	ind_top_b = org_b_1 (stack_b, struct_4[1], (*stack_a)[ind_t_nb]);
	struct_4[3] = org_b_2 (struct_4[1], ind_top_b);
	struct_2 = ft_strcpy (org_b_2s_move (struct_4[1],
				ind_top_b), struct_2, 4);
	call2moves(stack_a, stack_b, struct_4, struct_2);
	free (struct_2);
}
