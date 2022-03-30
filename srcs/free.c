/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:29:30 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/30 16:34:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* when using algos, use it if malloc errors in code to free everything
and exit with an error message
Won't segfault if pile_a or pile_b == NULL */

void	free_stacks_and_exit(t_data *data)
{
	free(data->nums);
	stack_clear(&data->pile_a);
	stack_clear(&data->pile_b);
	error_and_exit(data);
}
