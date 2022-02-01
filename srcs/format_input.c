/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:28:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/01 15:01:56 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	calc_stack_size(t_data *data, char **input_arr)
{
	int		i;

	i = 0;
	while(input_arr && input_arr[i])
	{
		data->stack_size++;
		i++;
	}
}

char	**format_input(int argc, char **argv, t_data *data)
{
	char	*input;
	char	**input_arr;
	int		i;

	data->stack_size = 0;
	input = ft_strdup(argv[1]);
	if (!input)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		input = ft_strjoin_and_free(input, " ");
		input = ft_strjoin_and_free(input, argv[i]);
		i++;
	}
	if (!input)
		return (NULL);
	input_arr = ft_split(input, ' ');
	if (!input_arr)
	{
		free(input);
		return (NULL);
	}
	calc_stack_size(data, input_arr);
	return (input_arr);
}
