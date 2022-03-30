/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:30:42 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/30 16:44:09 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* while pile A is sorted, push fourth number to top of pile A,
then until not sorted, rotate until sorted. Use an algo
to check what direction use the less moves */

static void	sort_last_param(t_data *data, int *nums)
{
	while (42)
	{
		free(nums);
		nums = pile_to_int_arr(data->pile_a);
		if (!nums)
			free_stacks_and_exit(data);
		if (check_if_already_sorted(nums, 4) == 0)
		{
			if (distance_from_sorted_pos(data->pile_a->num, data->pile_a)
				 == CLOCK)
				rab(&(data->pile_a), ALPHA, data);
			else
				rrab(&(data->pile_a), ALPHA, data);
		}	
		else
		{
			free(nums);
			break ;
		}
	}
}

/* This algo push the top number into pile B,
then apply the 3 num algo on pile A,
and finally use sort_last_param */

void	algo_case_four_nums(t_data *data)
{
	int		*nums;

	pb(&(data->pile_a), &(data->pile_b), data);
	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		free_stacks_and_exit(data);
	algo_case_three_nums(data, nums);
	pa(&(data->pile_a), &(data->pile_b), data);
	free(nums);
	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		free_stacks_and_exit(data);
	sort_last_param(data, nums);
}
