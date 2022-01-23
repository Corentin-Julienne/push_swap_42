/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:51:25 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/15 17:17:18 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*a = tmp;
}

int	partition(int *nums, int begin, int end) // to test
{
	int		i;
	int		j;
	int		pivot;

	pivot = nums[end];
	i = begin;
	j = end - 1;
	while (i <= j)
	{
		while (i < end && nums[i])
			i++;
		while (j >= begin && nums[j])
			j--;
		if (i < j)
			ft_swap(&nums[i], &nums[j]);
	}
	pivot = nums[i];
	return (pivot);
}

void	quicksort(int *nums, int begin, int end)
{
	int		i;

	if (begin < end)
	{
		i = partition(nums, begin, end);
		quicksort(nums, begin, i - 1);
		quicksort(nums, i + 1, end);
	}	
}
