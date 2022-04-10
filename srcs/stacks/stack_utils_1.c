/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:09:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/10 14:00:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* set of functions used to perform basic operations in order to
modify the piles a and b */

void	stack_delone(t_stack **stack)
{
	if (*stack)
	{
		// if ((*stack)->prev)
		// 	(*stack)->prev->next = NULL;
		// if ((*stack)->next)
		// 	(*stack)->next->prev = NULL;
		// (*stack)->prev = NULL;
		// (*stack)->next = NULL;
		*stack = NULL;
		// free(*stack);
	}
}

void	stack_clear(t_stack **stack)
{
	t_stack		*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		stack_delone(stack);
		*stack = tmp;
	}
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (*stack && new)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else if (*stack == NULL)
		*stack = new;
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack		*last_elem;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	if (*stack && new)
	{
		last_elem = stack_last(*stack);
		new->prev = last_elem;
		last_elem->next = new;
	}
}
