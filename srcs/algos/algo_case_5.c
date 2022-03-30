/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/30 17:08:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* check whether the num at top of pile B is within or outside
the interval defined by the smallest num of pile A and the largest */

static int	is_within_interval(t_stack *pile_b, int *nums, int num_size)
{
	if (pile_b->num < nums[0] && pile_b->num < nums[num_size - 1])
		return (0);
	if (pile_b->num > nums[0] && pile_b->num > nums[num_size - 1])
		return (0);
	return (1);
}

/*  */

static void	handle_within_interval(t_data *data, int *nums, int num_len)
{
	while (data->pile_b->num > data->pile_a->num)
		rab(&(data->pile_a), ALPHA, data);
	pa(&(data->pile_a), &(data->pile_b), data);
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

/* when outside interval, push num at the top of pile B to top of pile A,
then check if sorted. if not, just rotate the num at the bottom of pile A */

static void	handle_outside_interval(t_data *data, int *nums)
{
	pa(&(data->pile_a), &(data->pile_b), data);
	if (data->pile_a->num > nums[0])
		rab(&(data->pile_a), ALPHA, data);
	free(nums);
}

/* check if number at top of pile B is within or without the pile A interval,
the apply different func to handle both cases. Repeat for second number*/

static void	handle_pile_bravo(t_data *data)
{
	int		*nums;

	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		free_stacks_and_exit(data);
	if (is_within_interval(data->pile_b, nums, 3) == 0)
		handle_outside_interval(data, nums);
	else
		handle_within_interval(data, nums, 4);
	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		free_stacks_and_exit(data);
	if (is_within_interval(data->pile_b, nums, 4) == 0)
		handle_outside_interval(data, nums);
	else
		handle_within_interval(data, nums, 5);
}

/* this algo push the first two nums on pile B, then apply algo for three nums on pile A
(if not sorted already), then handle pile B */

void	algo_case_five_nums(t_data *data)
{
	int			*three_nums;
	int			feedback;

	pb(&(data->pile_a), &(data->pile_b), data);
	pb(&(data->pile_a), &(data->pile_b), data);
	three_nums = (int *)malloc(sizeof(int) * 3);
	if (!three_nums)
		free_stacks_and_exit(data);
	three_nums[0] = data->pile_a->num;
	three_nums[1] = data->pile_a->next->num;
	three_nums[2] = data->pile_a->next->next->num;
	feedback = check_if_already_sorted(three_nums, 3);
	if (feedback == -1)
		free_stacks_and_exit(data);
	else if (feedback == 0)
		algo_case_three_nums(data, three_nums);
	free(three_nums);
	handle_pile_bravo(data);
	stack_clear(&(data->pile_b)); // useful ?
}
