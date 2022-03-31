/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/31 17:33:14 by cjulienn         ###   ########.fr       */
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

void	msg_writer(int fildes, char *msg, t_data *data)
{
	if (write(fildes, msg, ft_strlen(msg)) == -1)
		free_stacks_and_exit(data);
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
	handle_verifs(data); // debug function only, suppress after
	ft_printf("moves : %i\n", data->counter); // BONUS
	// free and then exit (delete pile B ?)
	stack_clear(&data->pile_a);
	free(data->nums);
	free(data);
	return (0);
}
