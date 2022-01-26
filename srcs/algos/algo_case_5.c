/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 15:53:40 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_within_interval(t_stack *pile_b, int *nums, int num_size) // this one is good
{
	if (pile_b->num < nums[0] && pile_b->num < nums[num_size - 1])
		return (0);
	if (pile_b->num > nums[0] && pile_b->num > nums[num_size -1])
		return (0);
	return (1);
}

static t_stack	*sort_last_number(t_stack *pile_a, t_stack *pile_b)
{
	int		*nums;

	nums = pile_to_int_arr(pile_a);
	if (!nums)
		return (NULL);
	if (is_within_interval(pile_b, nums, 4) == 0)
	{
		pa(&pile_a, &pile_a);
		if (pile_a->num > nums[0])
			rab(&pile_a, ALPHA);
	}
	else
	{
		while (pile_b->num > pile_a->num)
			rab(&pile_a, ALPHA);
		pa(&pile_a, &pile_b);
		while (42)
		{
			free(nums);
			nums = pile_to_int_arr(pile_a);
			if (!nums)
				return (NULL);
			if (check_if_already_sorted(nums, 5) == 0)
				rab(&pile_a, ALPHA);
			else
				break ;
		}
	}
	free(nums);
	return (pile_a);
}

static t_stack	*handle_pile_bravo(t_stack *pile_a, t_stack *pile_b) // fucked up
{
	int		*nums;

	nums = pile_to_int_arr(pile_a);
	if (!nums)
		return (NULL);
	if (is_within_interval(pile_b, nums, 3) == 0)
	{
		pa(&pile_a, &pile_b);
		if (pile_a->num > nums[0])
			rab(&pile_a, ALPHA);
	}
	else
	{
		while (pile_b->num > pile_a->num)
			rab(&pile_a, ALPHA);
		pa(&pile_a, &pile_b);
		while (42)
		{
			free(nums);
			nums = pile_to_int_arr(pile_a);
			if (!nums)
				return (NULL);
			if (check_if_already_sorted(nums, 4) == 0)
				rab(&pile_a, ALPHA);
			else
				break ;
		}
	}
	free(nums);
	pile_a = sort_last_number(pile_a, pile_b);
	return (pile_a);
}

static t_stack	*within_interval(t_stack *pile_a, t_stack *pile_b, int *nums)
{
	return (pile_a);
}


t_stack	*algo_case_five_nums(t_stack *pile_a, t_stack *pile_b)
{
	int			*three_nums;

	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	three_nums = (int *)malloc(sizeof(int) * 3);
	if (!three_nums)
		return (NULL);
	three_nums[0] = pile_a->num;
	three_nums[1] = pile_a->next->num;
	three_nums[2] = pile_a->next->next->num;
	pile_a = algo_case_three_nums(pile_a, three_nums);
	free(three_nums);
	pile_a = handle_pile_bravo(pile_a, pile_b);
	stack_clear(&pile_b);
	display_pile(pile_a, pile_b);
	return (pile_a);
}
