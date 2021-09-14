/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:36:08 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/13 18:01:22 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_pile_item(int nb)
{
	t_stack		*pile_item;

	pile_item = (t_stack *)malloc(sizeof(t_stack));
	if (!pile_item)
		return (NULL);
	pile_item->num = nb;
	pile_item->next = NULL;
	return (pile_item);
}

void	del_pile(t_stack *pile_item)
{
	t_stack		*tmp;

	if (!pile_item)
		return ;
	while (pile_item)
	{
		tmp = pile_item;
		pile_item = pile_item->next;
		free(tmp);
	}
}

void	display_pile(t_stack *pile)
{
	while(pile->next)
	{
		printf("%d\n", pile->num);
		pile = pile->next;
	}
}

t_stack	*create_pile(int *nums, int arnb)
{
	t_stack		*pile;
	t_stack		*tmp;
	t_stack		*begin;
	int			i;

	i = 0;
	if (!nums)
		return (NULL);
	while(i++ < arnb)
	{
		pile = new_pile_item(nums[i]);
		if (!pile)
			return (NULL);
		if (i == 0)
			begin = pile;
		else
			tmp->next = pile;
		tmp = pile;
	}
	return (begin);
}
