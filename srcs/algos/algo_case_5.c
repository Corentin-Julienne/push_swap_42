/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 16:47:15 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	handle_pile_bravo(t_stack **pile_a, t_stack **pile_b, int errors)
{
	while ((*pile_b)->num > (*pile_a)->num)
		errors += rab(pile_a, ALPHA);
	errors += pa(pile_a, pile_b);
	while ((*pile_b)->num > (*pile_a)->num)
		errors += rab(pile_a, ALPHA);
	errors += pa(pile_a, pile_b);
	return (errors);
}

int	algo_case_five_nums(t_stack *pile_a, t_stack *pile_b)
{
	int			*three_nums;
	int			errors;

	errors = 0;
	errors += pb(&pile_a, &pile_b);
	errors += pb(&pile_a, &pile_b);
	three_nums = (int *)malloc(sizeof(int) * 3);
	if (!three_nums)
		return (2);
	three_nums[0] = pile_a->num;
	three_nums[1] = pile_a->next->num;
	three_nums[2] = pile_a->next->next->num;
	errors += algo_case_three_nums(pile_a, three_nums);
	free(three_nums);
	errors += handle_pile_bravo(&pile_a, &pile_b, errors);
	return (errors);
}
