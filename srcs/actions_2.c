/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:01:17 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 19:51:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 

rrab : doing either rra or rrb
=> rra : reverse rotate a - shift down all elements of stack a by 1. 
The last element becomes the first one.
=> rrb : reverse rotate b - shift down all elements of stack b by 1. 
The last element becomes the first one.

rrr : rra and rrb at the same time.

rab : doing either ra or rb
=> ra : rotate a - shift up all elements of stack a by 1. 
The first element becomes the last one.
=> rb : rotate b - shift up all elements of stack b by 1. 
The first element becomes the last one.

rr : ra and rb at the same time.

*/

int	rrab(t_stack **stack, int a_or_b)
{
	t_stack		*last_elem;
	t_stack		*first;
	int			num_tmp;

	if (!*stack || !(*stack)->next)
		return (-1);
	last_elem = *stack;
	last_elem = stack_last(last_elem);
	num_tmp = last_elem->num;
	stack_delone(&last_elem);
	last_elem = *stack;
	last_elem = stack_penultimate(last_elem);
	last_elem->next = NULL;
	first = stack_new(num_tmp);
	if (!first)
		return (-1);
	stack_add_front(stack, first);
	if (a_or_b == ALPHA)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (a_or_b == BRAVO)
		write(STDOUT_FILENO, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack **pile_a, t_stack **pile_b)
{
	int		res_ra;
	int		res_rb;

	res_ra = rrab(pile_a, COMBINED);
	if (res_ra != 0)
		return (-1);
	res_rb = rrab(pile_b, COMBINED);
	if (res_rb != 0)
		return (-1);
	write(STDOUT_FILENO, "rrr\n", 4);
	return (0);
}

int	rab(t_stack **stack, int a_or_b)
{
	int			num_tmp;
	t_stack		*new;
	t_stack		*tmp;

	if (!*stack || !(*stack)->next)
		return (-1);
	num_tmp = (*stack)->num;
	new = stack_new(num_tmp);
	if (!new)
		return (-1);
	stack_add_back(stack, new);
	tmp = (*stack)->next;
	stack_delone(stack);
	*stack = tmp;
	if (a_or_b == ALPHA)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (a_or_b == BRAVO)
		write(STDOUT_FILENO, "rb\n", 3);
	return (0);
}

int	rr(t_stack **pile_a, t_stack **pile_b)
{
	int		res_ra;
	int		res_rb;

	res_ra = rab(pile_a, COMBINED);
	if (res_ra != 0)
		return (-1);
	res_rb = rab(pile_b, COMBINED);
	if (res_rb != 0)
		return (-1);
	write(STDOUT_FILENO, "rr\n", 3);
	return (0);
}
