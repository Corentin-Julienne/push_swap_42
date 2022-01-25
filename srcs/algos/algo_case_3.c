/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:29:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 16:59:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	algo_case_three_nums(t_stack *pile_a, int *nums)
{	
	int 	errors;

	errors = 0;
	if (nums[0] > nums[1] && nums[0] < nums[2])
		errors += sab(&pile_a, ALPHA);
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] > nums[2])
	{
		errors += sab(&pile_a, ALPHA);
		errors += rrab(&pile_a, ALPHA);
	}
	else if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] < nums[2])
		errors += rab(&pile_a, ALPHA);
	else if (nums[0] < nums[1] && nums[0] < nums[2])
	{
		errors += sab(&pile_a, ALPHA);
		errors += rab(&pile_a, ALPHA);
	}
	else if (nums[0] < nums[1] && nums[0] > nums[2])
		errors += rrab(&pile_a, ALPHA);
	display_pile(pile_a, NULL);
	return (errors);
}
