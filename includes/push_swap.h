/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:07:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/23 19:27:15 by cjulienn         ###   ########.fr       */
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

/* ALGOS */

/*algo_case_2.c*/
int			algo_case_two_nums(int *nums, t_stack *pile_a);
/* algo_case_3.c */
int			algo_case_three_nums(int *nums, t_stack *pile_a);
/* algo_case_5.c*/
int			algo_case_five_nums(int *nums, t_stack *pile_a);
/*algo_case_100.c*/
int			algo_case_100_nums(int *nums, t_stack *pile_a);
/*algo_case_500.c*/
int			algo_case_500_nums(int *nums, t_stack *pile_a);

/* check args validity */

int			*check_args_are_valid(int argc, char **argv, t_data *data);

/* decision_tree.c*/

int			decision_tree(int *nums, t_stack *pile_a, int arr_len);

/* push_swap.c */

void		error_and_exit(void);

/* manage_piles.c */

void		display_pile(t_stack *pile);
t_stack		*create_pile_a(int *nums, int arnb);

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
