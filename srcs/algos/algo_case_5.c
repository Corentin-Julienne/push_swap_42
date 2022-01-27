/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 18:17:00 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_within_interval(t_stack *pile_b, int *nums, int num_size)
{
	if (pile_b->num < nums[0] && pile_b->num < nums[num_size - 1])
		return (0);
	if (pile_b->num > nums[0] && pile_b->num > nums[num_size - 1])
		return (0);
	return (1);
}

static void	handle_within_interval(t_data *data, int *nums, int num_len)
{
	while (data->pile_b->num > data->pile_a->num)
		rab(&(data->pile_a), ALPHA);
	pa(&(data->pile_a), &(data->pile_b));
	while (42)
	{
		free(nums);
		nums = pile_to_int_arr(data->pile_a);
		if (!nums)
			return ;
		if (check_if_already_sorted(nums, num_len) == 0)
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

static void	handle_outside_interval(t_data *data, int *nums)
{
	pa(&(data->pile_a), &(data->pile_b));
	if (data->pile_a->num > nums[0])
		rab(&(data->pile_a), ALPHA);
	free(nums);
}

static void	handle_pile_bravo(t_data *data)
{
	int		*nums;

	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		return ;
	if (is_within_interval(data->pile_b, nums, 3) == 0)
		handle_outside_interval(data, nums);
	else
		handle_within_interval(data, nums, 4);
	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		return ;
	if (is_within_interval(data->pile_b, nums, 4) == 0)
		handle_outside_interval(data, nums);
	else
		handle_within_interval(data, nums, 5);
}

void	algo_case_five_nums(t_data *data)
{
	int			*three_nums;

	pb(&(data->pile_a), &(data->pile_b));
	pb(&(data->pile_a), &(data->pile_b));
	three_nums = (int *)malloc(sizeof(int) * 3);
	if (!three_nums)
		return ;
	three_nums[0] = data->pile_a->num;
	three_nums[1] = data->pile_a->next->num;
	three_nums[2] = data->pile_a->next->next->num;
	algo_case_three_nums(data, three_nums);
	free(three_nums);
	handle_pile_bravo(data);
	stack_clear(&(data->pile_b));
}
