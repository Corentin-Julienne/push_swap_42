/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:30:42 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/30 18:01:23 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* This algo push the top number into pile B,
then apply the 3 num algo on pile A,
and finally use sort_last_param (see common_funcs.c) */

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
	sort_param_top_b(data, nums, 4);
}
