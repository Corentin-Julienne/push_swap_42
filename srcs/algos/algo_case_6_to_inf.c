/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_6_to_inf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/31 17:53:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*

Algo description :

Step 1: Find the corresponding borders to split my stack into X parts, equal in size if even number,
if not, the last chunk will add 1 more in size.
Step 2: push the first chunk to stack B
Step 3: search for the biggest and the smallest number in stack B
Step 4: rotate the biggest number to the top of stack B and push it to stack A
Step 5: rotate the smallest number to the top of stack B, push it to stack A and rotate it to the bottom
Step 6: repeat steps 4 and 5 until stack B is empty
Step 7: rotate all my sorted numbers from the top of stack A to the bottom of stack A
Step 8: repeat steps 2 to 7 for the remaining quarters
Step 9: have your numbers sorted by ascending order in stack A, with the smallest number on top of your Stack

*/

static int	is_in_chunk(t_data *data, int *std_nums, int chunk)
{
	int		end_index;
	int		begin_index;
	int		is_present;

	end_index = (chunk * data->chunk_num) - 1;
	begin_index = end_index - chunk + 1;
	is_present = 0;
	while (begin_index <= end_index)
	{
		if (data->pile_a->num == std_nums[begin_index])
			is_present = 1;
		begin_index++;
	}
	return (is_present);
}

int	move_chunk_to_b(t_data *data, int chunk)
{
	int		*nums_sorted;
	int		chunk_total;

	chunk_total = chunk;
	nums_sorted = pile_to_int_arr(data->pile_a);
	if (!nums_sorted)
		return (-1);
	quicksort(nums_sorted, 0, data->stack_size - 1);
	while (chunk > 0)
	{
		if (is_in_chunk(data, nums_sorted, chunk_total) == 1)
		{
			pb(&(data->pile_a), &(data->pile_b));
			chunk--;
		}
		else
		{
			rab(&(data->pile_a), ALPHA);
			data->ajust++;
		}
	}
	return (0);
}

static int	calc_num_reps(int pile_size)
{
	if (pile_size == 100)
		return (4);
	else if (pile_size == 500)
		return (8);
	else
		return (pile_size / 2);
}

void	algo_case_6_inf_nums(t_data *data)
{
	int			pile_size;
	int			chunk;
	int			reps;

	pile_size = calc_pile_size(data->pile_a);
	reps = calc_num_reps(pile_size);
	chunk = pile_size / reps;
	data->chunk_num = 1;
	data->ajust = 0;
	while (reps > 1)
	{
		move_chunk_to_b(data, chunk);
		while (data->ajust > 0)
		{
			rrab(&(data->pile_a), ALPHA);
			data->ajust--;
		}
		sort_pile_bravo(data);
		sort_pile_alpha(data);
		reps--;
		data->chunk_num++;
	}
	if (pile_size % 2 != 0)
		chunk++;
	move_chunk_to_b(data, chunk);
	while (data->ajust > 0)
	{
		rrab(&(data->pile_a), ALPHA);
		data->ajust--;
	}
	sort_pile_bravo(data);
	sort_pile_alpha(data);
}
