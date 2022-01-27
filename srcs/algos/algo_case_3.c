/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:29:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 16:37:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algo_case_three_nums(t_data *data, int *nums)
{	
	if (nums[0] > nums[1] && nums[0] < nums[2])
		sab(&(data->pile_a), ALPHA);
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] > nums[2])
	{
		sab(&(data->pile_a), ALPHA);
		rrab(&(data->pile_a), ALPHA);
	}
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] < nums[2])
		rab(&(data->pile_a), ALPHA);
	else if (nums[0] < nums[1] && nums[0] < nums[2])
	{
		sab(&(data->pile_a), ALPHA);
		rab(&(data->pile_a), ALPHA);
	}
	else if (nums[0] < nums[1] && nums[0] > nums[2])
		rrab(&(data->pile_a), ALPHA);
}
