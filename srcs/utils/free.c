/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:29:30 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/31 15:06:57 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* free data struct if allocated, then print Error\n and exit with EXIT_FAILURE */

void	error_and_exit(t_data *data)
{
	char	*err_msg;

	if (data != NULL)
		free(data);
	err_msg = "Error\n";
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}

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
