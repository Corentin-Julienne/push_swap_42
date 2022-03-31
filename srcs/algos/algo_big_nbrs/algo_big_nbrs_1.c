/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_nbrs_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:33:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/31 14:08:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/*

This algorithm works in multiple steps : 

*/

/* simply returns the number which is closest to top of pile A */

static int	rtn_number(int dist_up, int dist_down, t_stack *up, t_stack *down)
{
	if (dist_up < dist_down)
		return (up->num);
	else
		return (down->num);
}

/* scan number returns the first number from the index which pertains
to the chunk and which is the closest from the top of pile a */

static int	scan_number(t_data *data, int index_start, int index_end)
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
		if (up->sorted_pos >= index_start && up->sorted_pos <= index_end)
			break ;
		dist_up++;
		up = up->next;
	}
	while (down)
	{
		if (down->sorted_pos >= index_start && down->sorted_pos <= index_end)
			break ;
		dist_down++;
		down = down->prev;
	}
	return (rtn_number(dist_up, dist_down, up, down));
}

/*  */

static void	process_chunk(t_data *data, int chunk_len,
	 int index_start, int index_end)
{	
	int		num_to_push_up;
	
	while (chunk_len > 0)
	{
		num_to_push_up = scan_number(data, index_start, index_end);
		push_to_top_pile(data, num_to_push_up, ALPHA);
		organize_pile_b(data);
		chunk_len--;
	}
}

/* for big numbers ( > 5), we won't use the same numbers of reps
to sort pile A. So calc:chunk_num return the num of reps,
depending of the size of pile A */

static int	calc_chunk_num(t_data *data)
{
	if (data->stack_size == 100)
		return (5);
	else if (data->stack_size == 500)
		return (11);
	else
		return (4); // change this
}

/* used for big nums ( > 5)
reps is the number of repetitions of the loop
chunk len is the size of every chunk 
index_start and index_end are the indexes of first and last index 
of a given chunk */

void	algo_big_nums(t_data *data)
{
	int		reps;
	int		index_start;
	int		index_end;
	int		chunk_len;

	add_sorted_positions(data, data->pile_a);
	reps = calc_chunk_num(data);
	index_start = 0;
	chunk_len = data->stack_size / reps; // works for even numbers only
	index_end = chunk_len - 1;
	while (reps > 0)
	{
		process_chunk(data, chunk_len, index_start, index_end);
		index_start += chunk_len;
		index_end += chunk_len;
		reps--;
	}
	empty_pile_bravo(data);
}
