/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:07:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/24 16:58:32 by cjulienn         ###   ########.fr       */
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

typedef struct s_data
{
	int				i;
	int				j;
	int				*nums;
	int				*positions;
	int				stack_size;
	struct s_stack	*pile_a;
	struct s_stack	*pile_b;
}					t_data;

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/* ALGOS */

/*algo_case_2.c*/
int			algo_case_two_nums(int *nums, t_stack *pile_a);
/* algo_case_3.c */
int			algo_case_three_nums(int *nums, t_stack *pile_a);
/* algo_case_5.c*/
int			algo_case_five_nums(int *nums, t_stack *pile_a, t_data *data);
/*algo_case_100.c*/
int			algo_case_100_nums(t_stack *pile_a);
/*algo_case_500.c*/
int			algo_case_500_nums(int *nums, t_stack *pile_a);

/* ACTIONS */

/* actions_1.c */
int			sab(t_stack **pile, int	a_or_b);
int			ss(t_stack **pile_a, t_stack **pile_b);
int			pa(t_stack **pile_a, t_stack **pile_b);
int			pb(t_stack **pile_a, t_stack **pile_b);
/* actions_2.c */
int			rab(t_stack **stack, int a_or_b);
int			rr(t_stack **pile_a, t_stack **pile_b);
int			rrab(t_stack **stack, int a_or_b);
int			rrr(t_stack **pile_a, t_stack **pile_b);

/* algo_utils.c */

int			move_chunk_to_b(t_stack **pile_a, t_stack **pile_b,
			 int chunk, int errors);
int			sort_outlier(t_stack **pile_b, t_stack **pile_a,
				 int outlier, int errors);
int			sort_pile_bravo(t_stack **pile_b, t_stack **pile_a, int errors);
int			sort_pile_alpha(t_stack **pile_a, int chunk, int errors);

/* check args validity */

int			*check_args_are_valid(int argc, char **argv, t_data *data);

/* decision_tree.c*/

void		get_num_pos(int *nums, t_data *data);
int			decision_tree(t_data *data, int *nums,
				 t_stack *pile_a, int arr_len);

/* push_swap.c */

void		error_and_exit(void);

/* manage_piles.c */

void		display_pile(t_stack *pile);
int			calc_pile_size(t_stack *pile);
int			distance_to_sort(int value, t_stack *pile);
t_stack		*create_pile_a(int *nums, int arnb);

/* outliers.c */

int			*find_outliers(t_stack *pile);

/* quicksort.c */

void		ft_swap(int *a, int *b);
int			partition(int *nums, int low, int high);
void		quicksort(int *nums, int low, int high);

/* STACK UTILS */

/* stack_utils_1.c */
void		stack_delone(t_stack **stack);
void		stack_clear(t_stack **stack);
void		stack_add_front(t_stack **stack, t_stack *new);
void		stack_add_back(t_stack **stack, t_stack *new);
/* stack_utils_2.c */
t_stack		*stack_last(t_stack *stack);
int			stack_size(t_stack *stack);
t_stack		*stack_new(int nb);

#endif
