/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:24:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/15 18:32:09 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* nums is the array containing numbers, while
n is the length of the array */

void	manage_bubble_swaps(t_stack **pile_a, int *nums, int iter, int j)
{
	if (iter % 2 == 0)
	{
		if (nums[j] > nums[j + 1])
			ss(pile_a, pile_b); // inverse élements stacks a et b
		else
			sab(pile_a);
	}
	else
	{
		if (nums[j] > nums[j + 1])
			ss(pile_a, pile_b); // inverse élements stacks a et b
		else
			sab(pile_b);
	}
}

void	stack_bubble_sort(t_stack **pile_a, int *nums)
{
	int		n;
	int		i;
	int		j;
	int		iter;
	
	i = 0;
	j = 0;
	iter = 0;
	n = stack_size(*pile_a);
	while (i < (n - 1))
	{
		while (j < (n - i - 1))
		{
			manage_bubble_swaps(pile_a, nums, iter, j);
			j++;
		}
		i++;
		iter++;
	}
}

void	bubble_sort(int *nums, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	while (i < (n - 1))
	{
		while (j < (n - i - 1))
		{
			if (nums[j] > nums[j + 1])
				ft_swap(&nums[j], &nums[j + 1]);
			j++;
		}
		i++;
	}
}
