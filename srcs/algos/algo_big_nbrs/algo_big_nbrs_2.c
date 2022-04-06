/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_nbrs_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:56:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/06 16:56:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/* check if the num in top of pile A is within the interval
composed of the smallest and highest numbers in pile B
if outside of interval (easiest case),
push the smallest number to the top of pile B 
return 0 if inside interval, 1 if not */

static int	handle_case_interval(t_data *data, int num)
{
	int			*interval;
	t_stack		*pile;

	pile = data->pile_b;
	interval = find_interval(pile);
	if (!interval)
		free_stacks_and_exit(data);
	if (num < interval[0] || num > interval[1])
	{
		while (pile)
		{
			if (pile->num == interval[0])
			{
				push_to_top_pile(data, interval[0], BRAVO);
				break ;
			}
			pile = pile->next;
		}
		free(interval);
		return (1);
	}
	free(interval);
	return (0);
}

/* return -1 if no change are to made in pile B order
return the position to put in  the top of pile B if changes are needed */

static int	find_good_pos(t_data *data)
{
	int			target_pos;
	int			gd_num;
	int			diff;
	t_stack		*pile;

	if (handle_case_interval(data, data->pile_a->num) == 1)
		return (-1);
	target_pos = data->pile_a->sorted_pos;
	pile = data->pile_b;
	diff = 0;
	while (pile)
	{
		if (pile->sorted_pos > target_pos
			&& ((pile->sorted_pos - target_pos) < diff || (diff == 0)))
		{
			diff = pile->sorted_pos - target_pos;
			gd_num = pile->num;
		}
		pile = pile->next;
	}
	if (diff == 0 || data->pile_b->num == gd_num)
		return (-1);
	return (gd_num);
}

/* add sorted positions to data struct
(the place in the pile if they are sorted) */

void	add_sorted_positions(t_data *data, t_stack *pile_a)
{
	int		*nums;
	int		i;

	nums = pile_to_int_arr(data->pile_a);
	if (!nums)
		free_stacks_and_exit(data);
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
}

/* this function handle what number is needed in top of pile B
to insert the num in top of pile A in a sorted way,
then push this num in top of pile B */

int	organize_pile_bravo(t_data *data)
{	
	int			gd_num;

	if (!data->pile_b || !data->pile_b->next)
	{
		pb(&(data->pile_a), &(data->pile_b), data);
		return (0);
	}
	gd_num = find_good_pos(data);
	if (gd_num != -1)
		push_to_top_pile(data, gd_num, BRAVO);
	pb(&(data->pile_a), &(data->pile_b), data);
	return (0);
}

/* once pile A is empty, we have to find the biggest number in Stack B,
move it to the top, and push it over to Stack A.
Repeat this until Stack B is empty.*/

void	empty_pile_bravo(t_data *data)
{
	int		*nums;
	int		stack_size;

	while (data->pile_b)
	{
		stack_size = calc_pile_size(data->pile_b);
		if (stack_size >= 2)
		{
			nums = find_interval(data->pile_b);
			if (!nums)
				free_stacks_and_exit(data);
			if (nums[1] != data->pile_b->num)
				push_to_top_pile(data, nums[1], BRAVO);
			free(nums);
		}
		pa(&(data->pile_a), &(data->pile_b), data);
	}
}
