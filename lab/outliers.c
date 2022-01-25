/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outliers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:25 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/24 19:49:32 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* find_outliers function returns an array of two ints. 
index 0 refers to smallest num in the stack 
while index 1 refers to the  biggest  */

static void	find_biggest(t_stack *pile, int *int_arr)
{
	int		biggest;

	biggest = -2147483648;
	while (pile)
	{
		if (biggest < pile->num)
			biggest = pile->num;
		pile = pile->next;
	}
	int_arr[1] = biggest;
}

static void	find_smallest(t_stack *pile, int *int_arr)
{
	int		smallest;

	smallest = 2147483647;
	while (pile)
	{
		if (smallest > pile->num)
			smallest = pile->num;
		pile = pile->next;
	}
	int_arr[0] = smallest;
}

int	*find_outliers(t_stack *pile)
{
	int			*int_arr;

	int_arr = (int *)malloc(sizeof(int) * 2);
	if (!int_arr)
		return (NULL);
	find_smallest(pile, int_arr);
	find_biggest(pile, int_arr);
	return (int_arr);
}
