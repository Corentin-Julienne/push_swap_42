/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:29:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 20:07:41 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*algo_case_three_nums(t_stack *pile_a, int *nums)
{	
	if (nums[0] > nums[1] && nums[0] < nums[2])
		sab(&pile_a, ALPHA);
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] > nums[2])
	{
		sab(&pile_a, ALPHA);
		rrab(&pile_a, ALPHA);
	}
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] < nums[2])
		rab(&pile_a, ALPHA);
	else if (nums[0] < nums[1] && nums[0] < nums[2])
	{
		sab(&pile_a, ALPHA);
		rab(&pile_a, ALPHA);
	}
	else if (nums[0] < nums[1] && nums[0] > nums[2])
		rrab(&pile_a, ALPHA);
	return (pile_a);
}
