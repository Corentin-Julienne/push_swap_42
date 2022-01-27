/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:23:15 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/27 11:54:23 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lab.h"

void	display_int_num(int *nums, int num_size)
{
	int		i;

	i = 0;
	while (i < num_size)
	{
		printf("%i\n", nums[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int		i;
	int		*nums;

	nums = (int *)malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (1);
	i = 0;
	while (i < (argc - 1))
	{
		nums[i] = atoi(argv[i + 1]);
		i++;
	}
	printf("without quicksort :\n");
	display_int_num(nums, argc - 1);
	quicksort(nums, 0, argc - 2);
	printf("\n\n\nsorted with quicksort\n");
	display_int_num(nums, argc - 1);	
	return (0);
}
