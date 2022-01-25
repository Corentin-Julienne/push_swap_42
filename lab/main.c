/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:08:28 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 10:14:24 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lab.h"



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
	display_pile(data->pile_a);
	test_actions(data);
	display_pile(data->pile_a);
	return (0);
}
