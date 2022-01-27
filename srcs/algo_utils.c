/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 19:25:28 by cjulienn         ###   ########.fr       */
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

int	move_chunk_to_b(t_data *data, int chunk)
{
	while (chunk > 0)
	{
		pb(&(data->pile_a), &(data->pile_b));
		chunk--;
	}
	return (0);
}

void	sort_outlier(t_data *data, int outlier)
{
	if (distance_to_top_pile(outlier, data->pile_b) == UP)
	{
		while (data->pile_b->num != outlier)
			rab(&(data->pile_b), BRAVO);
	}
	else
	{
		while (data->pile_b->num != outlier)
			rrab(&(data->pile_b), BRAVO);
	}
	pa(&(data->pile_a), &(data->pile_b));
}

void	sort_pile_bravo(t_data *data)
{
	int		*outliers;

	while (data->pile_b)
	{
		outliers = find_outliers(data->pile_b);
		if (!outliers)
			return (-1);
		sort_outlier(data, outliers[1]);
		sort_outlier(data, outliers[0]);
		rab(&(data->pile_a), ALPHA);
		free(outliers);
	}
}

void	sort_pile_alpha(t_data *data, int chunk)
{
	int		num_to_sort;

	if (chunk % 2 == 0)
		num_to_sort = chunk / 2;
	else
		num_to_sort = ((chunk - 1) / 2) + 1;
	while (num_to_sort < 0)
	{
		rab(&(data->pile_a), ALPHA);
		num_to_sort--;
	}
	return (0);
}
