/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:33:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/01 20:42:38 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


static int	add_sorted_positions(t_data *data, t_stack *pile_a)
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
		while (nums[i] < data->stack_size)
		{
			if (nums[i] == pile_a->next)
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

static int	calc_chunk_num(t_data *data)
{
	if (data->stack_size == 100)
		return (5);
	else if (data->stack_size == 500)
		return (11);
	else
		return (7); // change that
}

static int	scan_number(t_data *data, int index, int chunk)
{
	t_stack		*up;
	t_stack		*down;
	int			dist_up;
	int			dist_down;

	up = data->pile_a;
	down = stack_last(data->pile_a);
	dist_up = 0;
	dist_down = 0;
	while (up)
	{
		if (up->sorted_pos >= index && up->sorted_pos < chunk)
			break ;
		dist_up++;
		up = up->next;
	}
	while (down)
	{
		if (down->sorted_pos >= index && down->sorted_pos < chunk)
			break ;
		dist_down++;
		down = down->prev;
	}
	return (dist_down - dist_up);
}

static void	push_to_top(t_data *data, int direction, int index, int chunk)
{
	if (direction == UP)
	{
		while (data->pile_a->sorted_pos < index
			 || data->pile_a->sorted_pos >= chunk)
			rab(&(data->pile_a), ALPHA, data);
	}
	else
	{
		while (data->pile_a->sorted_pos < index
			 || data->pile_a->sorted_pos >= chunk)
			rrab(&(data->pile_a), ALPHA, data);
	}
}

static void	organize_pile_b(t_data *data)
{
	if (!data->pile_b || !data->pile_a->next)
	{
		pb(&(data->pile_a), &(data->pile_b), data);
		return ;
	}
	// continue
}

void	algo_big_nums(t_data *data) // continue
{
	int		reps;
	int		chunk;
	int		index;
	
	if (add_sorted_positions(data, data->pile_a) == 1)
		return ;
	reps = calc_chunk_num(data);
	index = 0;
	chunk = data->stack_size / reps;
	while (reps > 0)
	{
		if (scan_number(data, index, chunk) > 0)
			push_to_top(data, UP, index, chunk);
		else
			push_to_top(data, DOWN, index, chunk);
		reps--;
	}
}
