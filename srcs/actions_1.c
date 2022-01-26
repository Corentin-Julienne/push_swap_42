/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:01:15 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/25 19:44:19 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 

sab : is doing either swap a or swap b :
=> sa : swap a - swap the first 2 elements at the top of stack a. 
Do nothing if there is only one or no elements).
=> sb : swap b - swap the first 2 elements at the top of stack b. 
Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a 
Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b 
Do nothing if a is empty.

*/

int	sab(t_stack **pile, int	a_or_b) // functionnal
{	
	int		tmp;

	if (!*pile || !(*pile)->next)
		return (-1);
	tmp = (*pile)->num;
	(*pile)->num = (*pile)->next->num;
	(*pile)->next->num = tmp;
	if (a_or_b == ALPHA)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (a_or_b == BRAVO)
		write(STDOUT_FILENO, "sb\n", 3);
	return (0);
}

int	ss(t_stack **pile_a, t_stack **pile_b) // functionnal
{
	int		res_a;
	int		res_b;

	res_a = sab(pile_a, ALPHA);
	if (res_a != 0)
		return (-1);
	res_b = sab(pile_b, BRAVO);
	if (res_b != 0)
		return (-1);
	write(STDOUT_FILENO, "ss\n", 3);
	return (0);
}

int	pa(t_stack **pile_a, t_stack **pile_b) // functionnal
{
	t_stack		*tmp;
	t_stack		*tmp_2;

	if (*pile_b == NULL)
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
	write(STDOUT_FILENO, "pa\n", 3);
	return (0);
}

int	pb(t_stack **pile_a, t_stack **pile_b) // functionnal
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
	write(STDOUT_FILENO, "pb\n", 3);
	return (0);
}
