/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:53 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 16:54:51 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	algo_case_100_nums(t_stack *pile_a, t_stack *pile_b)
{
	int			pile_size;
	int			chunk;
	int			reps;
	int			errors;

	errors = 0;
	pile_size = calc_pile_size(pile_a);
	chunk = pile_size / 4;
	reps = 4;
	while (reps > 0)
	{
		errors += move_chunk_to_b(pile_a, pile_b, chunk, errors);
		errors += sort_pile_bravo(pile_b, pile_a, errors);
		errors += sort_pile_alpha(pile_a, chunk, errors);
		reps--;
	}
	return (errors);
}
