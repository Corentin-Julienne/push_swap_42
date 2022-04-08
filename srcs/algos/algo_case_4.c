/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:30:42 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/08 14:05:00 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* This algo push the top number into pile B,
then apply the 3 num algo on pile A,
and finally use sort_last_param */

static void	insert_last_param(t_data *data)
{
	int		*nums;

	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		free_stacks_and_exit(data);
	if (is_within_interval(data->pile_b, nums, 3) == 0)
		handle_outside_interval(data, nums);
	else
		handle_within_interval(data, nums, 4);
}

void	algo_case_four_nums(t_data *data)
{
	int		*nums;

	pb(&(data->pile_a), &(data->pile_b), data);
	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		free_stacks_and_exit(data);
	algo_case_three_nums(data, nums);
	free(nums);
	insert_last_param(data);
}
