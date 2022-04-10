/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:29:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/10 15:44:51 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* simple algo for three nums in the stack */

void	algo_case_three_nums(t_data *data, int *nums)
{	
	int		sort_result;

	sort_result = check_if_already_sorted(nums, 3);
	if (sort_result == -1)
		free_stacks_and_exit(data);
	else if (sort_result == 1)
		return ;
	if (nums[0] > nums[1] && nums[0] < nums[2])
		sab(&data->pile_a, ALPHA, data);
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] > nums[2])
	{
		sab(&data->pile_a, ALPHA, data);
		rrab(&data->pile_a, ALPHA, data);
	}
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] < nums[2])
		rab(&data->pile_a, ALPHA, data);
	else if (nums[0] < nums[1] && nums[0] < nums[2])
	{
		sab(&data->pile_a, ALPHA, data);
		rab(&data->pile_a, ALPHA, data);
	}
	else if (nums[0] < nums[1] && nums[0] > nums[2])
		rrab(&data->pile_a, ALPHA, data);
}
