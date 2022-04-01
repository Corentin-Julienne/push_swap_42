/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outliers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:03:14 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/01 16:03:26 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_outlier(t_data *data, int outlier) // is it useful ?
{
	if (distance_to_top_pile(outlier, data->pile_b) == UP)
	{
		while (data->pile_b->num != outlier)
			rab(&(data->pile_b), BRAVO, data);
	}
	else
	{
		while (data->pile_b->num != outlier)
			rrab(&(data->pile_b), BRAVO, data);
	}
	pa(&(data->pile_a), &(data->pile_b), data);
}