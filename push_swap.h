/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:17:00 by uxmancis          #+#    #+#             */
/*   Updated: 2023/10/15 17:51:25 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//push_swap.c
int		check_sorted(int *stack_a, int argc, char **argv, int ind_error);
int		is_there_error(int argc, char **argv);
int		push_swap(int argc, char **argv);

//check_errors.c
int		checker_last(int argc, char **argv);
int		checker_3(int argc, char **argv);
int		checker_2(int argc, char **argv);
int		checker_1(int argc, char **argv);
int		checkers_index(int argc, char **argv);

//fill_stack.c
int		fill_list(char **argv, int *x_y, int **ind_error);
int		ft_duplicate(int *arr, int len);
int		ft_is_sorted(int *stack_a, int len_stack_a);
int		checker_4(char *str);
void	fill_stack(int *arr_pre_check, int argc, char **argv, int *ind_error);

//ft_sort_exceptions.c
void	ft_sort_2(int **stack_a);
void	ft_sort_3(int **stack_a, int len_stack_a);
void	ft_sort_5(int **stack_a, int **stack_b, int *struct_4);
int		case_mngmt(int numof_int, int **sa, int **sb, int *struct_4);

//sort_it.c
void	a2b(int **stack_a, int **stack_b, int *struct_4);
void	sort_it(int **stack_a, int **stack_b, int *struct_4);

//2s_moves.c
int		top_stack(int len, int index);
int		org_b_1(int **stack_b, int len_b, int travel_nb);
char	*top_a_2s_move(int len, int index);
char	*org_b_2s_move(int len_b, int index_top_b);

//get_numof_moves.c
int		top_stack(int len, int index);
int		org_b_2(int len_b, int index_top_stack);
int		org_b_2(int len_b, int index_top_stack);

//get_travel_nb.c
int		sum_moves(int **s_a, int ind, int **s_b, int *struct_4);
void	ft_getarr_sumof_moves(int **sa, int **sb, int *struct_4, int **arr);
int		ft_getnum_least_moves(int *arr, int len_a);
int		ft_get_ind_tb(int *arr, int num);
int		get_cheapest_nb(int **stack_a, int **stack_b, int *struct_4);

//exec_moves.c
void	call2moves(int **stack_a, int **stack_b, int *struct_4, char *struct_2);
void	which_moves(int **stack_a, int **stack_b, int *struct_4, int ind_t_nb);

//decide_moves.c
void	decide_move_stack_a(char *move_type, int **stack_a, int len_a);
void	decide_move_stack_b(char *move_type, int **stack_b, int len_b);
void	decide_move_2_stacks(char *m, int **s_a, int **s_b, int *struct_4);

//moves.c
void	push_pa(int **stack_src, int **stack_dst, int *struct_4);
void	push_pb(int **stack_src, int **stack_dst, int *struct_4);
void	reverse_rotate(int **stack, int len);
void	rotate(int **stack, int len);
void	swap(int **stack);

//utils.c
void	put_arr(int **stack, int len); //stack_a
//void	put_arr2(int **stack, int len); //stack_b
void	ft_get_new_dst(int *new_dst, int **old_dst, int len);
void	ft_get_new_src(int *new_src, int **old_src, int len);
void	ft_str_fit(char *str, char *new_str_fit);
int		ft_strcmp(char *str1, char *str2);

//utils2.c
int		ft_get_biggest_ind(int **stack_a, int len_a);
int		ft_get_smallest_ind(int **stack_a, int len_a);
void	ft_sort_3_opt_a(int ind_biggest, int **stack_a);
void	ft_sort_3_opt_b(int ind_biggest, int **stack_a);
void	ft_sort_3_opt_c(int ind_biggest, int **stack_a);

//utils3.c
int		ft_getnumof_smaller_values(int **stack_b, int len_b, int travel_nb);
void	ft_fill_arr(int **arr, int len_b, int travel_nb, int **stack_b);
int		ft_nb_ns(int **stack_b, int len_b, int travel_nb);
int		ft_index_ns(int **stack_b, int len_b, int value_next_smallest);
char	*ft_get_move(char	*src, char	*move, int start);
//void	ft_get_move(char	*src, char	**move, int start);

//utils4.c
int		are_there_more_integers(char **argv, int *x_y, int len_arg);
int		are_there_smaller_values(int **stack_b, int len_b, int travel_nb);
char	*ft_strcpy(char *str_src, char *str_dst, int start);
int		ft_get_value_biggest(int **stack_b, int len_b);
int		ft_index_biggest(int **stack_b, int len_b);

//utils5.c
int		ft_atoi(char *str, int ***ind_error);
int		ft_get_smallest_int(int **stack_a, int len_stack_a);
int		ft_numof_int(int argc, char **argv);
int		ft_isdigit_2(char c);
void	assign_len(int	*len, int *keep_len, char *arg);

//utils6.c
int		ft_isdigit(char c);
int		numof_digits(char **argv, int *x_y);
char	*fill_str(char **argv, int *x_y, char *str, int counter);
int		ft_strlen(char *str);
void	ft_free_mem(int *stack_a, int	*stack_b, int	*struct_4);

#endif
