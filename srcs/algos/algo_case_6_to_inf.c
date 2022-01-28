/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_6_to_inf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/28 12:39:23 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	calc_num_reps(int pile_size)
{
	if (pile_size == 100)
		return (4);
	if (pile_size == 500)
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
	while (reps > 1)
	{
		move_chunk_to_b(data, chunk);
		sort_pile_bravo(data);
		sort_pile_alpha(data, chunk);
		reps--;
	}
	if (pile_size % 2 != 0)
		chunk++;
	move_chunk_to_b(data, chunk);
	sort_pile_bravo(data);
	sort_pile_alpha(data, chunk);
}
