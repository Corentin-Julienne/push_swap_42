/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:36:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/31 15:20:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* simply calculate the size of the stack */

int	calc_pile_size(t_stack *pile)
{
	int		pile_size;

	pile_size = 0;
	while (pile)
	{
		pile_size++;
		pile = pile->next;
	}
	return (pile_size);
}

/* this function calculate if it is quicker to rotate or reverse rotate
to push a givent number to the top of the pile */

int	distance_to_top_pile(int value, t_stack *pile)
{
	int			pile_size;
	int			dst_from_up;

	pile_size = calc_pile_size(pile);
	dst_from_up = 0;
	while (pile && pile->num != value)
	{
		dst_from_up++;
		pile = pile->next;
	}
	if (dst_from_up < (pile_size / 2))
		return (UP);
	else
		return (DOWN);
}

/* this function calculate the quickest path to the top pile
for a given number and put it at the top */

void	push_to_top_pile(t_data *data, int num, int pile_id)
{
	if (pile_id == ALPHA && distance_to_top_pile(num, data->pile_a) == UP)
	{
		while (data->pile_a->num != num)
			rab(&(data->pile_a), ALPHA, data);
	}
	else if (pile_id == ALPHA
		 && distance_to_top_pile(num, data->pile_a) == DOWN)
	{
		while (data->pile_a->num != num)
			rrab(&(data->pile_a), ALPHA, data);
	}
	else if (pile_id == BRAVO
		 && distance_to_top_pile(num, data->pile_b) == UP)
	{
		while (data->pile_b->num != num)
			rab(&(data->pile_b), BRAVO, data);
	}
	else if (pile_id == BRAVO
		 && distance_to_top_pile(num, data->pile_b) == DOWN)
	{
		while (data->pile_b->num != num)
			rrab(&(data->pile_b), BRAVO, data);
	}
}

int	distance_from_sorted_pos(int value, t_stack *pile)
{
	int		pile_size;
	int		dst_from_up;

	pile_size = calc_pile_size(pile);
	dst_from_up = 0;
	pile = pile->next;
	while (pile && pile->num != value)
	{
		dst_from_up++;
		pile = pile->next;
	}
	if (dst_from_up < (pile_size / 2))
		return (CLOCK);
	else
		return (REVERSE);
}

/* create the pile ALPHA using the stack utils functions 
return NULL in case of any malloc failure */

t_stack	*create_pile_a(int *nums, int size_of_stack)
{
	t_stack		*pile;
	t_stack		*new;
	int			i;

	pile = stack_new(nums[0]);
	if (!pile)
		return (NULL);
	i = 1;
	while (i < size_of_stack)
	{
		new = stack_new(nums[i]);
		if (!new)
		{
			stack_clear(&pile);
			return (NULL);
		}
		stack_add_back(&pile, new);
		i++;
	}
	return (pile);
}
