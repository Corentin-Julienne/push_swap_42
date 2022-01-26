/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:41:38 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 15:44:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* debugging function : not to push for correction */

void	display_pile(t_stack *pile_a, t_stack *pile_b)
{
	t_stack		*iter;

	printf("PILE A\n");
	iter = pile_a;
	while (iter->next)
	{
		ft_printf("%d\n", iter->num);
		iter = iter->next;
	}
	ft_printf("%d\n", iter->num);
	if (!pile_b)
		return ;
	printf("PILE B\n");
	iter = pile_b;
	while (iter->next)
	{
		ft_printf("%d\n", iter->num);
		iter = iter->next;
	}
	ft_printf("%d\n", iter->num);
}
