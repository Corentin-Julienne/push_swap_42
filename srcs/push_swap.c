/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/30 16:11:07 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/* => format input verify if the input is correct */

int	main(int argc, char **argv)
{
	t_data		*data;
	char		**input;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_and_exit(NULL);
	input = format_input(argc, argv, data);
	data->nums = check_args_are_valid(input, data);
	// verify if functional with proper testing at this point
	data->pile_a = create_pile_a(data->nums, data->stack_size);
	if (!data->pile_a)
	{
		free(data->nums);
		error_and_exit(data);
	}
	data->pile_b = NULL;
	// verify if functional with proper testing at this point
	decision_tree(data, data->stack_size);
	display_pile(data->pile_a, data->pile_b); // debug function only, suppress after
	handle_verifs(data);
	ft_printf("moves : %i\n", data->counter);
	stack_clear(&data->pile_a);
	free(data);
	return (0);
}
