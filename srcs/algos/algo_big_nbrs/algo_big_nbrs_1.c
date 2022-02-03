/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_nbrs_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:33:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/03 20:17:32 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/*

This algorithm works in multiple steps : 

*/

static int	rtn_number(int dist_up, int dist_down, t_stack *up, t_stack *down) // seems functionnal
{
	if (dist_up < dist_down)
		return (up->num);
	else
		return (down->num);
}

static int	scan_number(t_data *data, int index, int chunk) // seems functionnal
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

static void	process_chunk(t_data *data, int num_treated, int index, int chunk)
{	
	int		num_to_push_up;
	
	while (num_treated > 0)
	{
		num_to_push_up = scan_number(data, index, chunk);
		push_to_top_pile(data, num_to_push_up, ALPHA);
		organize_pile_b(data);
		num_treated--;
	}
}

static int	calc_chunk_num(t_data *data) // seems ok
{
	if (data->stack_size == 100)
		return (5);
	else if (data->stack_size == 500)
		return (11);
	else
		return (4); // change this
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
