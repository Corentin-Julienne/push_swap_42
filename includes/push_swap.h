/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:07:27 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/14 16:37:47 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h> // remove every useless headers before pushing
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/* push swap */

void 		error_and_exit(void);

/* check args validity */

int			*check_args_are_valid(int argc, char **argv);

/* manage piles */

void		display_pile(t_stack *pile);
t_stack		*create_pile(int *nums, int arnb);

/* stack utils (1 and 2) */

void		stack_delone(t_stack **stack);
void		stack_clear(t_stack **stack);
void		stack_add_front(t_stack **stack, t_stack *new);
void		stack_add_back(t_stack **stack, t_stack *new);

t_stack		*stack_last(t_stack *stack);
int			stack_size(t_stack *stack);
t_stack		*stack_new(int nb);

/* actions 1 and 2 */

int			sab(t_stack **pile);
int			ss(t_stack **pile_a, t_stack **pile_b);
int			pa(t_stack **pile_a, t_stack **pile_b);
int			pb(t_stack **pile_a, t_stack **pile_b);

int			rab(t_stack **stack);
int			rr(t_stack **pile_a, t_stack **pile_b);
int			rrab(t_stack **stack);
int			rrr(t_stack **pile_a, t_stack **pile_b);

#endif

