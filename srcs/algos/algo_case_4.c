/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:30:42 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/28 10:53:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_last_param(t_data *data, int *nums)
{
	while (42)
	{
		free(nums);
		nums = pile_to_int_arr(data->pile_a);
		if (!nums)
			return ;
		if (check_if_already_sorted(nums, 4) == 0)
		{
			if (distance_from_sorted_pos(data->pile_a->num, data->pile_a)
				 == CLOCK)
				rab(&(data->pile_a), ALPHA);
			else
				rrab(&(data->pile_a), ALPHA);
		}	
		else
		{
			free(nums);
			break ;
		}
	}
}

void	algo_case_four_nums(t_data *data)
{
	int		*nums;

	pb(&(data->pile_a), &(data->pile_b));
	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		return ;
	algo_case_three_nums(data, nums);
	pa(&(data->pile_a), &(data->pile_b));
	free(nums);
	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		return ;
	sort_last_param(data, nums);
}
