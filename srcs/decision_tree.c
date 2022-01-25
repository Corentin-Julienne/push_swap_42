/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:10:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 16:48:02 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	decision_tree(t_data *data, int arr_len)
{	
	int			feedback;

	feedback = 0;
	if (arr_len == 2)
		feedback = algo_case_two_nums(data->pile_a);
	else if (arr_len == 3)
		feedback = algo_case_three_nums(data->pile_a, data->nums);
	else if (arr_len == 5)
		feedback = algo_case_five_nums(data->pile_a, data->pile_b);
	else if (arr_len >= 100 && arr_len < 500)
		feedback = algo_case_100_nums(data->pile_a, data->pile_b);
	else if (arr_len >= 500)
		feedback = algo_case_500_nums(data->pile_a, data->pile_b);
	return (feedback);
}
