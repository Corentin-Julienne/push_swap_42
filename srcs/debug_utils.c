/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:41:38 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/04 09:37:24 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* debugging function : not to push for correction */

void	display_pile(t_stack *pile_a, t_stack *pile_b)
{
	t_stack		*iter;

	if (pile_a)
	{
		printf("PILE A\n");
		iter = pile_a;
		while (iter->next)
		{
			ft_printf("%i\n", iter->num);
			iter = iter->next;
		}
		ft_printf("%d\n", iter->num);
	}
	if (pile_b)
	{
		printf("PILE B\n");
		iter = pile_b;
		while (iter->next)
		{
			ft_printf("%d\n", iter->num);
			iter = iter->next;
		}
		ft_printf("%d\n", iter->num);
	}
	ft_printf("\n----------------------------------\n");
}

void	display_input(char **input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		printf("%s\n", input[i]);
		i++;
	}
}

void	display_nums(t_data *data, int *nums)
{
	int		i;

	i = 0;
	while (i < data->stack_size)
	{
		printf("%i\n", nums[i]);
		i++;
	}
}

void	display_sorted_positions(t_stack *pile)
{
	while (pile)
	{
		printf("%i\n", pile->sorted_pos);
		pile = pile->next;
	}
}

void	handle_verifs(t_data *data)
{
	t_stack		*pile_a;

	pile_a = data->pile_a;
	while (pile_a)
	{
		printf("%i\n", pile_a->sorted_pos);
		pile_a = pile_a->next;
	}
}

