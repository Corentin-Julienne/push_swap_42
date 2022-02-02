/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:33:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/02 14:13:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*

This algorithm works in multiple steps : 

Step 1: Scan Stack A from the top to confirm if one of the numbers from Chunk 1 exist inside of it. 
Let's call that number hold_first.
________________________________________________________________________________________________________________________
Step 2: Scan Stack A again from the bottom and see if a different number from Chunk 1 exists in that list. 
I’ll call that number hold_second.
________________________________________________________________________________________________________________________
Step 3: Compare how many moves it would take to get hold_first and hold_second to the top.
________________________________________________________________________________________________________________________
Step 4: So the correct number is now on to top of Stack A. 
But there are two things we need to check for before we push the number over to Stack B. 
You have to check if the number you’re pushing is either bigger or smaller than all the other numbers in Stack B. 
Since we’re not just pushing the smallest number one at a time. 
We need to make sure we’re not gonna cause an infinite loop by trying to find the perfect spot to insert that number.
________________________________________________________________________________________________________________________
Step 5: Repeat steps 1–4 until all the numbers in Chunk 1 no longer in Stack A.
________________________________________________________________________________________________________________________
Step 6: Repeat steps 1–4 for the rest of the chunks so they are handled
in the same way and all of Stack A is inside of Stack B.
________________________________________________________________________________________________________________________
Step 7: Now that Stack A is empty, find the biggest number in Stack B,
move it to the top, and push it over to Stack A. 
Repeat this until Stack B is empty. 
You can use the logic from Step 3 to determine if you need to use rb or rrb to quickly get the numbers to the top.

*/

static int	calc_chunk_num(t_data *data)
{
	if (data->stack_size == 100)
		return (5);
	else if (data->stack_size == 500)
		return (11);
	else
		return (7); // change that
}

static int	rtn_number(int dist_up, int dist_down, t_stack *up, t_stack *down)
{
	if (dist_up < dist_down)
		return (up->num);
	else
		return (down->num);
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
	return (rtn_number(dist_up, dist_down, up, down));
}

static int	find_good_pos(t_data *data, int num_to_push_up)
{
	int		gd_pos;

	while (data->pile_b)
	{
		// finish that
		data->pile_b = data->pile_b->next;
	}
	return (gd_pos);
}

static int	organize_pile_b(t_data *data, int num_to_push_up)
{	
	int		*int_arr;
	int		gd_pos;
	
	int_arr = find_outliers(data->pile_b);
	if (!int_arr)
		return (-1);
	if (!data->pile_b || !data->pile_b->next
		 || data->pile_b < int_arr[0] || data->pile_b > int_arr[1])
	{
		pb(&(data->pile_a), &(data->pile_b), data);
		free(int_arr);
		return (0);
	}
	free(int_arr);
	gd_pos = find_good_pos(data, num_to_push_up);
	push_to_top_pile(data, gd_pos, BRAVO);
	pb(&(data->pile_a), &(data->pile_b), data);
	return (0);
}

static void	process_chunk(t_data *data, int num_treated, int index, int chunk)
{	
	int		num_to_push_up;
	
	while (num_treated > 0)
	{
		num_to_push_up = scan_number(data, index, chunk);
		push_to_top_pile(data, num_to_push_up, ALPHA);
		organize_pile_b(data, num_to_push_up);
		num_treated--;
	}
}

static void	empty_pile_bravo(t_data *data)
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

void	algo_big_nums(t_data *data)
{
	int		reps;
	int		chunk_len;
	int		chunk;
	int		index;
	int		num_treated;
	
	reps = calc_chunk_num(data);
	index = 0;
	chunk_len = data->stack_size / reps;
	chunk = chunk_len;
	num_treated =  chunk_len;
	while (reps > 0)
	{
		process_chunk(data, num_treated, index, chunk);
		index += chunk_len;
		chunk += chunk_len;
		reps--;
	}
	empty_pile_bravo(data);
}
