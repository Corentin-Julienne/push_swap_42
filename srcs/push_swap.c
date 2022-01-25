/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 17:00:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	test_stuff(t_data *data)
{
	data->pile_b = NULL;
	
	pb(&(data->pile_a), &(data->pile_b));
}

void	error_and_exit(void)
{
	char	*err_msg;

	err_msg = "Error\n";
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc == 1)
		error_and_exit();
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_and_exit();
	data->stack_size = argc - 1;
	data->i = 0;
	data->nums = check_args_are_valid(argc, argv, data);
	if (!data->nums)
	{
		free(data);
		error_and_exit();
	}
	data->pile_a = create_pile_a(data->nums, argc - 1);
	if (!data->pile_a)
	{
		free(data);
		error_and_exit();
	}
	data->pile_b = NULL;
	display_pile(data->pile_a, data->pile_b);
	decision_tree(data, (argc - 1));
	return (0);
}
