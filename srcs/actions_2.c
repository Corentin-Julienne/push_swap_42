/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:01:17 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/14 16:32:48 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrab(t_stack **stack)
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
	last_elem = stack_last(last_elem);
	last_elem->next = NULL;
	first = stack_new(num_tmp);
	if (!first)
		return (-1);
	stack_add_front(stack, first);
	return (0);
}

int	rrr(t_stack **pile_a, t_stack **pile_b)
{
	int		res_ra;
	int		res_rb;

	res_ra = rrab(pile_a);
	res_rb = rrab(pile_b);
	if (res_ra == -1 || res_rb == -1)
		return (-1);
	return (0);
}

int	rab(t_stack **stack)
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
	return (0);
}

int	rr(t_stack **pile_a, t_stack **pile_b)
{
	int		res_ra;
	int		res_rb;

	res_ra = rab(pile_a);
	res_rb = rab(pile_b);
	if (res_ra == -1 || res_rb == -1)
		return (-1);
	return (0);
}