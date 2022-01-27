/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:17:03 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/27 11:58:19 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lab.h"

static void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *nums, int begin, int end)
{
    int		pivot;
    int		i;
	int		j;

	pivot = nums[end];
	i = begin - 1;
	j = begin;
	while (j <= (end - 1))
	{
		if (nums[j] < pivot)
        {
            i++;
            ft_swap(&nums[i], &nums[j]);
        }
		j++;
	}
    ft_swap(&nums[i + 1], &nums[end]);
    return (i + 1);
}

void quicksort(int *nums, int begin, int end)
{
    int		index;

	if (begin < end)
	{
		index = partition(nums, begin, end);
		quicksort(nums, begin, index - 1);
		quicksort(nums, index + 1, end);
	}
}
