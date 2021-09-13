/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:55:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/13 15:14:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void error_and_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}	

int	main(int argc, char **argv)
{
	printf("compilation successful !!!\n");
	if (argc == 1)
		exit(0);
	check_args_are_valid(argc, argv);
	
	return (0);
}
