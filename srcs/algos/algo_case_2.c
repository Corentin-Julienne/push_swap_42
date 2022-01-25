/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:42:22 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 16:44:11 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	algo_case_two_nums(t_stack *pile_a)
{
	int			errors;

	errors = 0;
	errors += sab(&pile_a, ALPHA);
	return (errors);
}
