/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 21:33:07 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*pile_to_int_arr(t_stack *pile)
{
	int		*nums;
	int		pile_size;
	int 	i;
	
	pile_size = calc_pile_size(pile);
	nums = (int *)malloc(sizeof(int) * pile_size);
	if (!nums)
		return (NULL);
	i = 0;
	while (pile)
	{
		nums[i] = pile->num;
		pile = pile->next;
		i++;
	}
	return (nums);
}

int	move_chunk_to_b(t_stack *pile_a, t_stack *pile_b, int chunk)
{
	while (chunk > 0)
	{
		pb(&pile_a, &pile_b);
		chunk--;
	}
	return (0);
}

int	sort_outlier(t_stack *pile_a, t_stack *pile_b, int outlier)
{
	if (distance_to_top_pile(outlier, pile_b) == UP)
	{
		while (pile_b->num != outlier)
			rab(&pile_b, BRAVO);
	}
	else
	{
		while (pile_b->num != outlier)
			rrab(&pile_b, BRAVO);
	}
	pa(&pile_a, &pile_b);
	return (0);
}

int	sort_pile_bravo(t_stack *pile_b, t_stack *pile_a)
{
	int		*outliers;

	while (pile_b)
	{
		outliers = find_outliers(pile_b);
		if (!outliers)
			return (-1);
		sort_outlier(pile_a, pile_b, outliers[1]);
		sort_outlier(pile_a, pile_b, outliers[0]);
		rab(&pile_a, ALPHA);
		free(outliers);
	}
	return (0);
}

int	sort_pile_alpha(t_stack *pile_a, int chunk)
{
	int		num_to_sort;

	if (chunk % 2 == 0)
		num_to_sort = chunk / 2;
	else
		num_to_sort = ((chunk - 1) / 2) + 1;
	while (num_to_sort < 0)
	{
		rab(&pile_a, ALPHA);
		num_to_sort--;
	}
	return (0);
}
