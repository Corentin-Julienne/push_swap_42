/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_nbrs_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:56:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/03 20:14:28 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int handle_case_outlier(t_data *data, int num)
{
	int			*nums;
	t_stack		*pile;
	
	pile = data->pile_b;
	nums = find_outliers(pile);
	if (!nums)
		return (-2);
	if (num < nums[0] || num > nums[1])
	{
		while (pile)
		{
			if (pile->num == nums[0])
			{
				push_to_top_pile(data, nums[0], BRAVO);
				break ;
			}
			pile = pile->next;
		}
		free(nums);
		return (-1);
	}
	free(nums);
	return (0);
}

int	find_good_pos(t_data *data) // bugged
{
	int			feedback;
	int			target_pos;
	int			gd_num;
	int			diff;
	t_stack		*pile;

	feedback = handle_case_outlier(data, data->pile_a->num);
	if (feedback < 0)
		return (feedback);
	target_pos = data->pile_a->sorted_pos;
	pile = data->pile_b;
	diff = 0;
	while (pile) // quand aucun nombre sup ne marche pas, traiter exceptions
	{
		if (pile->sorted_pos > target_pos
			 && ((pile->sorted_pos - target_pos) < diff || (diff == 0)))
		{
			diff = pile->sorted_pos - target_pos;
			gd_num = pile->num;
		}
		pile = pile->next;
	}
	if (diff == 0)
		return (-1);
	return (gd_num);
}

int	organize_pile_b(t_data *data)
{	
	int			gd_num;
	t_stack		*pile;
	
	if (!data->pile_b || !data->pile_b->next)
	{
		pb(&(data->pile_a), &(data->pile_b), data);
		return (0);
	}
	pile = data->pile_b;
	gd_num = find_good_pos(data);
	if (gd_num != -1)
		push_to_top_pile(data, gd_num, BRAVO);
	pb(&(data->pile_a), &(data->pile_b), data);
	return (0);
}

void	empty_pile_bravo(t_data *data)
{
	int		*nums;

	while (data->pile_b)
	{
		nums = find_outliers(data->pile_b);
		if (!nums)
			return ;
		if (nums[1] != data->pile_b->num)
			push_to_top_pile(data, nums[1], BRAVO);
		free(nums);
		pa(&(data->pile_a), &(data->pile_b), data);
	}
}
