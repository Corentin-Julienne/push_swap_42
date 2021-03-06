/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:28:54 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/08 14:33:11 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* set of functions used to perform basic operations in order to
modify the piles a and b */

t_stack	*stack_last(t_stack *stack)
{
	size_t	size;

	if (!stack)
		return (NULL);
	size = stack_size(stack);
	while (size - 1 > 0)
	{
		stack = stack->next;
		size--;
	}
	return (stack);
}

t_stack	*stack_penultimate(t_stack *stack)
{
	size_t	size;

	if (!stack)
		return (NULL);
	size = stack_size(stack) - 1;
	while (size - 1 > 0)
	{
		stack = stack->next;
		size--;
	}
	return (stack);
}

int	stack_size(t_stack *stack)
{
	size_t		size;
	t_stack		*stack_2;

	if (!stack)
		return (0);
	stack_2 = stack;
	size = 0;
	while (stack_2 != NULL)
	{
		size++;
		stack_2 = stack_2->next;
	}
	return (size);
}

t_stack	*stack_new(int nb)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = nb;
	new->sorted_pos = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
