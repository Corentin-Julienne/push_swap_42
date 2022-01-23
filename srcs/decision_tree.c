/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:10:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/23 19:27:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	initialize_int_arr(int *positions, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->stack_size)
	{
		positions[i] = 0;
		i++;
	}
}

static void	calc_positions(int *positions, long long smallest_val,
	 int smallest_index, t_data *data) // yet to be tested
{
	data->j = 1;
	data->i = 0;
	while (data->j <= data->stack_size)
	{
		smallest_val = 2147483650;
		while (data->i < data->stack_size)
		{
			while (positions[data->i] != 0)
				data->i++;
			if (smallest_val == 2147483650)
			{
				smallest_val = data->nums[data->i];
				smallest_index = data->i;
			}
			else if (smallest_val > data->nums[data->i] && !positions[data->i])
			{
				smallest_val = data->nums[data->i];
				smallest_index = data->i;
			}
			data->i++;
		}
		positions[smallest_index] = data->j;
		data->j++;
		data->i = 0;
	}
}

int		*get_num_pos(int *nums, t_data *data)
{
	int			*positions;
	long long	smallest_val;
	int 		smallest_index;
	
	positions = (int *)malloc(sizeof(int) * data->stack_size);
	if (!positions)
		return (NULL);
	initialize_int_arr(positions, data);
	calc_positions(positions, smallest_val, smallest_index, data);
	return (positions);
}

int	decision_tree(int *nums, t_stack *pile_a, int arr_len)
{	
	int		feedback;
	
	if (arr_len == 2)
		feedback = algo_case_two_nums(nums, pile_a);
	else if (arr_len == 3)
		feedback = algo_case_three_nums(nums, pile_a);
	else if (arr_len == 5)
		feedback = algo_case_five_nums(nums, pile_a);
	else if (arr_len >= 100 && arr_len < 500)
		feedback = algo_case_100_nums(nums, pile_a);
	else if (arr_len >= 500)
		feedback = algo_case_500_nums(nums, pile_a);
	return (feedback);
}
