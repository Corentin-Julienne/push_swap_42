/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:07:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/02 12:58:46 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define 	ALPHA		1
# define 	BRAVO		2
# define	COMBINED	3

# define	UP			1
# define	DOWN		2

# define	CLOCK		1
# define	REVERSE		2

typedef struct s_data
{
	int				i;
	int				j;
	int				*nums;
	int				stack_size;
	int				chunk_num;
	int				transfer;
	int				ajust;
	int				counter;
	void			**storage;
	struct s_stack	*pile_a;
	struct s_stack	*pile_b;
}					t_data;

typedef struct s_stack
{
	int				num;
	int				sorted_pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* ALGOS */

/*algo_case_2.c*/
void		algo_case_two_nums(t_data *data);
/* algo_case_3.c */
void		algo_case_three_nums(t_data *data, int *nums);
/* algo_case_4.c */
void		algo_case_four_nums(t_data *data);
/* algo_case_5.c*/
void		algo_case_five_nums(t_data *data);
/*algo_case_100.c*/
void		algo_case_6_inf_nums(t_data *data);
int			move_chunk_to_b(t_data *data, int chunk);

/* ACTIONS */

/* actions_1.c */
int			sab(t_stack **pile, int	a_or_b, t_data *data);
int			ss(t_stack **pile_a, t_stack **pile_b, t_data *data);
int			pa(t_stack **pile_a, t_stack **pile_b, t_data *data);
int			pb(t_stack **pile_a, t_stack **pile_b, t_data *data);
/* actions_2.c */
int			rab(t_stack **stack, int a_or_b, t_data *data);
int			rr(t_stack **pile_a, t_stack **pile_b, t_data *data);
int			rrab(t_stack **stack, int a_or_b, t_data *data);
int			rrr(t_stack **pile_a, t_stack **pile_b, t_data *data);

/* algo_utils.c */

int			*pile_to_int_arr(t_stack *pile);
void		sort_outlier(t_data *data, int outlier);
void		sort_pile_bravo(t_data *data);
void		sort_pile_alpha(t_data *data);

/* check args validity */

int			check_if_already_sorted(int *nums, int nbr_c);
int			*check_args_are_valid(char **input, t_data *data);

/* debug_utils.c */

void		display_pile(t_stack *pile_a, t_stack *pile_b);

/* decision_tree.c*/

int			decision_tree(t_data *data, int arr_len);

/* format_input.c */

char		**format_input(int argc, char **argv, t_data *data);

/* quicksort.c */

int			*int_arr_dup(int *to_cpy, int arr_size);
int			are_arr_equals(int *arr_a, int *arr_b, int arr_size);
void		quicksort(int *nums, int begin, int end);

/* manage_piles.c */

int			calc_pile_size(t_stack *pile);
int			distance_to_top_pile(int value, t_stack *pile);
void		push_to_top_pile(t_data *data, int num, int pile_id);
int			distance_from_sorted_pos(int value, t_stack *pile);
t_stack		*create_pile_a(int *nums, int arnb);

/* outliers.c */

int			*find_outliers(t_stack *pile);

/* STACK UTILS */

/* stack_utils_1.c */
void		stack_delone(t_stack **stack);
void		stack_clear(t_stack **stack);
void		stack_add_front(t_stack **stack, t_stack *new);
void		stack_add_back(t_stack **stack, t_stack *new);
/* stack_utils_2.c */
t_stack		*stack_last(t_stack *stack);
t_stack		*stack_penultimate(t_stack *stack);
int			stack_size(t_stack *stack);
t_stack		*stack_new(int nb);

#endif
