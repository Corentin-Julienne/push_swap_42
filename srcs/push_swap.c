/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/14 17:09:55 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_and_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}	

int	main(int argc, char **argv)
{
	t_stack		*pile_a;
	int			*nums;
	
	if (argc == 1)
		exit(0);
	nums = check_args_are_valid(argc, argv);
	pile_a = create_pile(nums, argc - 1);
	if (!pile_a)
		return (-1);
	display_pile(pile_a);
	sab(&pile_a);
	display_pile(pile_a);
	return (0);
}
