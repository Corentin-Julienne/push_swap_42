/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_validity_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:20:37 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/31 14:57:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* check if args are numbers only, within the int range,
without duplicates, and non sorted yet. 
also return an arr of int with the nums to sort */

static void	check_if_data_is_int(char **input, t_data *data)
{
	int		errors;
	
	data->i = 0;
	errors = 0;
	while (data->i < data->stack_size)
		errors += is_int_compatible(input[data->i++]);
	if (errors > 0)
	{
		free(input);
		error_and_exit(data);
	}
}

int	*check_args_are_valid(char **input, t_data *data)
{
	int		*nums;
	int		errors;

	check_if_data_is_int(input, data);
	errors = 0;
	nums = (int *)malloc(sizeof(int) * (data->stack_size));
	if (!nums)
	{
		free(input);
		error_and_exit(data);
	}
	data->i = 0;
	while (data->i < data->stack_size)
	{
		nums[data->i] = ft_atoi(input[data->i]);
		data->i++;
	}
	free(input);
	errors = check_if_duplicates(nums, data->stack_size);
	if (errors > 0 || errors == -1)
	{
		free(nums);
		error_and_exit(data);
	}
	return (nums);
}
