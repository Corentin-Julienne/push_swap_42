/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_100_to_inf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 19:19:29 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	algo_case_100_inf_nums(t_data *data)
{
	int			pile_size;
	int			chunk;
	int			reps;

	pile_size = calc_pile_size(data->pile_a);
	chunk = pile_size / 4;
	reps = 4;
	while (reps > 0)
	{
		move_chunk_to_b(data, chunk);
		sort_pile_bravo(data);
		sort_pile_alpha(data, chunk);
		reps--;
	}
}
