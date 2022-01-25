/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:54:58 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 10:15:41 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lab.h"

int	move_chunk_to_b(t_stack **pile_a, t_stack **pile_b,
			 int chunk, int errors)
{
	while (chunk > 0)
	{
		errors += pb(pile_a, pile_b);
		chunk--;
	}
	return (errors);
}

int	sort_outlier(t_stack **pile_b, t_stack **pile_a,
				 int outlier, int errors)
{
	if (distance_to_top_pile(outlier, *pile_b) == UP)
	{
		while ((*pile_b)->num != outlier)
			errors += rab(pile_b, BRAVO);
	}
	else
	{
		while ((*pile_b)->num != outlier)
			errors += rrab(pile_b, BRAVO);
	}
	errors += pa(pile_a, pile_b);
	return (errors);
}

int	sort_pile_bravo(t_stack **pile_b, t_stack **pile_a, int errors)
{
	int		*outliers;

	while (*pile_b)
	{
		outliers = find_outliers(*pile_b);
		if (!outliers)
			return (-1);
		errors += sort_outlier(pile_b, pile_a, outliers[1], errors);
		errors += sort_outlier(pile_b, pile_a, outliers[0], errors);
		errors += rab(pile_a, ALPHA);
		free(outliers);
	}
	return (errors);
}

int	sort_pile_alpha(t_stack **pile_a, int chunk, int errors)
{
	int		num_to_sort;

	if (chunk % 2 == 0)
		num_to_sort = chunk / 2;
	else
		num_to_sort = ((chunk - 1) / 2) + 1;
	while (num_to_sort < 0)
	{
		errors += rab(pile_a, ALPHA);
		num_to_sort--;
	}
	return (errors);
}
