/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:01:17 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/30 18:43:04 by cjulienn         ###   ########.fr       */
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

static int	rotate_feedback(int	direction, int a_or_b, t_data *data)
{
	if (a_or_b == ALPHA && direction == REVERSE)
		msg_writer(STDOUT_FILENO, "rra\n", data);
	else if (a_or_b == BRAVO && direction == REVERSE)
		msg_writer(STDOUT_FILENO, "rrb\n", data);
	else if (a_or_b == ALPHA && direction == CLOCK)
		msg_writer(STDOUT_FILENO, "ra\n", data);
	else if (a_or_b == BRAVO && direction == CLOCK)
		msg_writer(STDOUT_FILENO, "rb\n", data);
	if (a_or_b == ALPHA || a_or_b == BRAVO)
		data->counter++;
	return (0);
}

int	rrab(t_stack **stack, int a_or_b, t_data *data)
{
	t_stack		*last_elem;
	t_stack		*first;
	int			num_tmp;
	int			pos_tmp;

	if (!*stack || !(*stack)->next)
		return (-1);
	last_elem = *stack;
	last_elem = stack_last(last_elem);
	num_tmp = last_elem->num;
	pos_tmp = last_elem->sorted_pos;
	stack_delone(&last_elem);
	last_elem = *stack;
	last_elem = stack_penultimate(last_elem);
	last_elem->next = NULL;
	first = stack_new(num_tmp);
	if (!first)
		return (-1);
	stack_add_front(stack, first);
	(*stack)->sorted_pos = pos_tmp;
	return (rotate_feedback(REVERSE, a_or_b, data));
}

int	rrr(t_stack **pile_a, t_stack **pile_b, t_data *data)
{
	int		res_ra;
	int		res_rb;

	res_ra = rrab(pile_a, COMBINED, data);
	if (res_ra != 0)
		return (-1);
	res_rb = rrab(pile_b, COMBINED, data);
	if (res_rb != 0)
		return (-1);
	msg_writer(STDOUT_FILENO, "rrr\n", data);
	data->counter++;
	return (0);
}

int	rab(t_stack **stack, int a_or_b, t_data *data)
{
	int			num_tmp;
	int			pos_tmp;
	t_stack		*new;
	t_stack		*tmp;

	if (!*stack || !(*stack)->next)
		return (-1);
	num_tmp = (*stack)->num;
	pos_tmp = (*stack)->sorted_pos;
	new = stack_new(num_tmp);
	if (!new)
		return (-1);
	stack_add_back(stack, new);
	tmp = (*stack)->next;
	stack_delone(stack);
	*stack = tmp;
	tmp = stack_last(*stack);
	tmp->sorted_pos = pos_tmp;
	return (rotate_feedback(CLOCK, a_or_b, data));
}

int	rr(t_stack **pile_a, t_stack **pile_b, t_data *data)
{
	int		res_ra;
	int		res_rb;

	res_ra = rab(pile_a, COMBINED, data);
	if (res_ra != 0)
		return (-1);
	res_rb = rab(pile_b, COMBINED, data);
	if (res_rb != 0)
		return (-1);
	msg_writer(STDOUT_FILENO, "rr\n", data);
	data->counter++;
	return (0);
}
