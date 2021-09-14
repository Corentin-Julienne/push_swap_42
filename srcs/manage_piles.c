/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:36:08 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/14 16:52:09 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_pile(t_stack *pile) // fonction de debug et de ctrl
{
	t_stack		*iter;
	
	printf("PILE A\n"); // kill after
	iter = pile;
	while(iter->next)
	{
		ft_printf("%d\n", iter->num);
		iter = iter->next;
	}
	ft_printf("%d\n", iter->num);
}

t_stack	*create_pile(int *nums, int arnb) // do not forget to free everything if malloc error
{
	t_stack		*pile;
	t_stack		*new;
	int			i;

	if (!nums)
		return (NULL);
	pile = stack_new(nums[0]);
	if (!pile)
		return (NULL);
	i = 1;
	while(i < arnb)
	{
		new = stack_new(nums[i]);
		if (!new)
			return (NULL);
		stack_add_back(&pile, new);
		i++;
	}
	return (pile);
}
