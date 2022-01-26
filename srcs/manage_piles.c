/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:36:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 15:46:21 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_stack	*create_pile_a(int *nums, int arnb)
{
	t_stack		*pile;
	t_stack		*new;
	int			i;

	pile = stack_new(nums[0]);
	if (!pile)
		return (NULL);
	i = 1;
	while (i < arnb)
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
