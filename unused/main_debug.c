/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:45:49 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/10 15:26:42 by cjulienn         ###   ########.fr       */
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
	data->pile_a = create_pile_a(data->nums, data->stack_size);
	if (!data->pile_a)
	{
		free(data->nums);
		error_and_exit(data);
	}
	data->pile_b = NULL;
	display_pile(data->pile_a, data->pile_b); // debug func
	decision_tree(data, data->stack_size);
	display_pile(data->pile_a, data->pile_b); // debug func
	final_verifs(data); // debug func
	printf("total num of moves : %i\n", data->counter);
	stack_clear(&data->pile_a);
	stack_clear(&data->pile_b);
	free(data->nums);
	free(data);
	return (0);
}

int	rab(t_data *data, int a_or_b)
{
	t_stack		*stack;
	t_stack		*last_elem;
	int			storage[2];
	int			tmp[2];
	
	if (a_or_b == ALPHA)
		stack = data->pile_a;
	else
		stack = data->pile_b;
	printf("go till there\n");
	printf("stack first num : %i\n", stack->num);
	if (!stack || !stack->next)
		return (1);
	last_elem = stack_last(stack);
	storage[0] = stack->num;
	storage[1] = stack->sorted_pos;
	while (last_elem)
	{
		tmp[0] = last_elem->num;
		tmp[1] = last_elem->sorted_pos;
		last_elem->num = storage[0];
		last_elem->sorted_pos = storage[1];
		storage[0] = tmp[0];
		storage[1] = tmp[1];
		last_elem = last_elem->prev;
	}
	return (rotate_feedback(CLOCK, a_or_b, data));
}

int	rrab(t_data *data, int a_or_b)
{
	t_stack		*stack;
	t_stack		*last_elem;
	int			storage[2];
	int			tmp[2];

	if (a_or_b == ALPHA)
		stack = data->pile_a;
	else
		stack = data->pile_b;
	if (!stack || !stack->next)
		return (1);
	last_elem = stack_last(stack);
	storage[0] = last_elem->num;
	storage[1] = last_elem->sorted_pos;
	while (stack)
	{
		tmp[0] = stack->num;
		tmp[1] = stack->sorted_pos;
		stack->num = storage[0];
		stack->sorted_pos = storage[1];
		storage[0] = tmp[0];
		storage[1] = tmp[1];
		stack = stack->next;
	}
	return (rotate_feedback(REVERSE, a_or_b, data));
}
