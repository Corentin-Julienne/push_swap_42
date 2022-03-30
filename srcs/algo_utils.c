/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/30 17:16:46 by cjulienn         ###   ########.fr       */
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

void	sort_outlier(t_data *data, int outlier)
{
	if (distance_to_top_pile(outlier, data->pile_b) == UP)
	{
		while (data->pile_b->num != outlier)
			rab(&(data->pile_b), BRAVO, data);
	}
	else
	{
		while (data->pile_b->num != outlier)
			rrab(&(data->pile_b), BRAVO, data);
	}
	pa(&(data->pile_a), &(data->pile_b), data);
}

void	sort_pile_bravo(t_data *data) // bugged, probably not useful
{
	int		*outliers;

	data->transfer = 0;
	while (data->pile_b)
	{
		outliers = find_outliers(data->pile_b);
		if (!outliers)
			return ;
		sort_outlier(data, outliers[1]);
		sort_outlier(data, outliers[0]);
		rab(&(data->pile_a), ALPHA, data);
		data->transfer++;
		free(outliers);
	}
}

void	sort_pile_alpha(t_data *data) // bugged, probably not useful
{
	while (data->transfer > 0)
	{
		rab(&(data->pile_a), ALPHA, data);
		data->transfer--;
	}
}
