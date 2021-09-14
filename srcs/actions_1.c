/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:01:15 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/14 16:54:27 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sab(t_stack **pile)
{	
	int		tmp;
	
	if (!*pile || !(*pile)->next)
		return (-1);
	tmp = (*pile)->num;
	(*pile)->num  = (*pile)->next->num;
	(*pile)->next->num = tmp;
	return (0);
}

int	ss(t_stack **pile_a, t_stack **pile_b)
{
	int		res_a;
	int		res_b;

	res_a = sab(pile_a);
	res_b = sab(pile_b);
	if (res_a == -1 || res_b == -1)
		return (-1);
	return (0);
}

int	pa(t_stack **pile_a, t_stack **pile_b)
{
	t_stack		*tmp;
	t_stack		*tmp_2;
	
	if (!*pile_b)
		return (-1);
	tmp = stack_new((*pile_b)->num);
	stack_add_front(pile_a, tmp);
	if (!(*pile_b)->next)
		stack_delone(pile_b);
	else
	{
		tmp_2 = (*pile_b)->next;
		stack_delone(pile_b);
		*pile_b = tmp_2;
	}
	return (0);
}

int	pb(t_stack **pile_a, t_stack **pile_b)
{
	t_stack		*tmp;
	t_stack		*tmp_2;

	
	if (!*pile_a)
		return (-1);
		
	tmp = stack_new((*pile_a)->num);
	stack_add_front(pile_b, tmp);
	if (!(*pile_a)->next)
		stack_delone(pile_a);
	else
	{
		tmp_2 = (*pile_a)->next;
		stack_delone(pile_a);
		*pile_a = tmp_2;
	}
	return (0);
}
