/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:10:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 10:15:48 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lab.h"

int	decision_tree(int *nums, t_stack *pile_a, int arr_len)
{	
	int		feedback;

	feedback = 0;
	if (arr_len == 2)
		feedback = algo_case_two_nums(pile_a);
	else if (arr_len == 3)
		feedback = algo_case_three_nums(nums, pile_a);
	else if (arr_len == 5)
		feedback = algo_case_five_nums(pile_a);
	else if (arr_len >= 100 && arr_len < 500)
		feedback = algo_case_100_nums(pile_a);
	else if (arr_len >= 500)
		feedback = algo_case_500_nums(pile_a);
	return (feedback);
}
