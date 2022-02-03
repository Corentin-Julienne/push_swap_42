/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/03 20:25:48 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	error_and_exit(t_data *data)
{
	char	*err_msg;

	if (data != NULL)
		free(data);
	err_msg = "Error\n";
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	char		**input;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_and_exit(NULL);
	input = format_input(argc, argv, data);
	data->nums = check_args_are_valid(input, data);
	free(input);
	if (!data->nums)
		error_and_exit(data);
	data->pile_a = create_pile_a(data->nums, data->stack_size);
	if (!data->pile_a)
		error_and_exit(data);
	data->pile_b = NULL;
	decision_tree(data, data->stack_size);
	display_pile(data->pile_a, data->pile_b);
	handle_verifs(data);
	printf("moves : %i\n", data->counter);
	stack_clear(&data->pile_a);
	free(data);
	return (0);
}
