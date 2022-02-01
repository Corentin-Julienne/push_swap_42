/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/01 15:18:07 by cjulienn         ###   ########.fr       */
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

static void	display_input(char **input) // debug function
{
	int		i;

	i = 0;
	while (input[i])
	{
		printf("%s\n", input[i]);
		i++;
	}
	sleep(2);
}

static void	display_nums(t_data *data, int *nums) // debug function
{
	int		i;

	i = 0;
	while (i < data->stack_size)
	{
		printf("%i\n", nums[i]);
		i++;
	}
	sleep(2);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	char		**input;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error_and_exit(NULL);
	input = format_input(argc, argv, data);
	display_input(input); // debug func
	data->nums = check_args_are_valid(input, data);
	free(input);
	if (!data->nums)
		error_and_exit(data);
	display_nums(data, data->nums); // debug func
	data->pile_a = create_pile_a(data->nums, data->stack_size);
	if (!data->pile_a)
		error_and_exit(data);
	data->pile_b = NULL;
	decision_tree(data, data->stack_size);
	stack_clear(&data->pile_a);
	printf("moves : %i\n", data->counter);
	free(data);
	return (0);
}
