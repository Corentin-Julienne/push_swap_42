/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/08 16:18:27 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	decision_tree(t_data *data, int arr_len)
{
	data->counter = 0;
	if (arr_len == 2)
		algo_case_two_nums(data);
	else if (arr_len == 3)
		algo_case_three_nums(data, data->nums);
	else if (arr_len == 4)
		algo_case_four_nums(data);
	else if (arr_len == 5)
		algo_case_five_nums(data);
	else if (arr_len >= 6)
		algo_big_nums(data);
}

static void	setup_stack_and_algo(t_data *data)
{
	data->pile_a = create_pile_a(data->nums, data->stack_size);
	if (!data->pile_a)
	{
		free(data->nums);
		error_and_exit(data);
	}
	data->pile_b = NULL;
	decision_tree(data, data->stack_size);
}

void	msg_writer(int fildes, char *msg, t_data *data)
{	
	if (write(fildes, msg, ft_strlen(msg)) == -1)
		free_stacks_and_exit(data);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	char		**input;

	atexit(leaks_tracking); // leak tracker, suppress after use
	if (argc == 1)
	{
		ft_printf("\n");
		exit(EXIT_SUCCESS);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_and_exit(NULL);
	input = format_input(argc, argv, data);
	data->nums = check_args_are_valid(input, data);
	if (data->is_sorted == 1)
	{
		free(data->nums);
		free(data);
		exit(EXIT_SUCCESS);
	}
	// no leaks till this
	setup_stack_and_algo(data);
	display_pile(data->pile_a, NULL); // verif
	final_verifs(data); // verifs
	suppress_leaks_bfr_exit(data);
	return (0);
}
