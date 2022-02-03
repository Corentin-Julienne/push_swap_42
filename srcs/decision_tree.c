/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:10:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/03 20:17:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	add_sorted_positions(t_data *data, t_stack *pile_a)
{
	int		*nums;
	int		i;

	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		return (-1);
	quicksort(nums, 0, data->stack_size - 1);
	i = 0;
	while (pile_a)
	{
		while (i < data->stack_size)
		{
			if (nums[i] == pile_a->num)
			{
				pile_a->sorted_pos = i;
				break ;
			}
			i++;
		}
		i = 0;
		pile_a = pile_a->next;
	}
	return (0);
}

int	decision_tree(t_data *data, int arr_len)
{
	data->counter = 0;
	
	if (add_sorted_positions(data, data->pile_a) == -1)
		return (-1);
	if (arr_len == 2)
		algo_case_two_nums(data);
	else if (arr_len == 3)
		algo_case_three_nums(data, data->nums);
	else if (arr_len == 4)
		algo_case_four_nums(data);
	else if (arr_len == 5)
		algo_case_five_nums(data);
	else if (arr_len >= 6)
		algo_big_nums(data);
	return (0);
}
