/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:07:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 15:44:09 by cjulienn         ###   ########.fr       */
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
t_stack		*algo_case_two_nums(t_stack *pile_a);
/* algo_case_3.c */
t_stack		*algo_case_three_nums(t_stack *pile_a, int *nums);
/* algo_case_5.c*/
t_stack		*algo_case_five_nums(t_stack *pile_a, t_stack *pile_b);
/*algo_case_100.c*/
t_stack		*algo_case_100_nums(t_stack *pile_a, t_stack *pile_b);
/*algo_case_500.c*/
t_stack		*algo_case_500_nums(t_stack *pile_a, t_stack *pile_b);

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

int			*pile_to_int_arr(t_stack *pile);
int			move_chunk_to_b(t_stack *pile_a, t_stack *pile_b, int chunk);
int			sort_outlier(t_stack *pile_a, t_stack *pile_b, int outlier);
int			sort_pile_bravo(t_stack *pile_b, t_stack *pile_a);
int			sort_pile_alpha(t_stack *pile_a, int chunk);

/* check args validity */

int			check_if_already_sorted(int *nums, int nbr_c);
int			*check_args_are_valid(int argc, char **argv, t_data *data);

/* debug_utils.c */

void		display_pile(t_stack *pile_a, t_stack *pile_b);

/* decision_tree.c*/

int			decision_tree(t_data *data, int arr_len);

/* push_swap.c */

void		error_and_exit(void);

/* manage_piles.c */

int			calc_pile_size(t_stack *pile);
int			distance_to_top_pile(int value, t_stack *pile);
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
