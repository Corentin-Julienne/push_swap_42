/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:01:15 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/08 14:33:45 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	sab(t_stack **pile, int a_or_b, t_data *data)
{	
	int		tmp_num;
	int		tmp_pos;

	if (!*pile || !(*pile)->next)
		return (1);
	tmp_num = (*pile)->num;
	(*pile)->num = (*pile)->next->num;
	(*pile)->next->num = tmp_num;
	tmp_pos = (*pile)->sorted_pos;
	(*pile)->sorted_pos = (*pile)->next->sorted_pos;
	(*pile)->next->sorted_pos = tmp_pos;
	if (a_or_b == ALPHA)
		msg_writer(STDOUT_FILENO, "sa\n", data);
	else if (a_or_b == BRAVO)
		msg_writer(STDOUT_FILENO, "sb\n", data);
	if (a_or_b == ALPHA || a_or_b == BRAVO)
		data->counter++;
	return (0);
}

int	ss(t_stack **pile_a, t_stack **pile_b, t_data *data)
{
	int		res_a;
	int		res_b;

	res_a = sab(pile_a, COMBINED, data);
	res_b = sab(pile_b, COMBINED, data);
	if (!res_a || !res_b)
		msg_writer(STDOUT_FILENO, "ss\n", data);
	data->counter++;
	return (0);
}

int	pa(t_stack **pile_a, t_stack **pile_b, t_data *data)
{
	t_stack		*tmp;
	t_stack		*tmp_2;
	int			tmp_pos;

	if (*pile_b == NULL)
		return (1);
	tmp_pos = (*pile_b)->sorted_pos;
	tmp = stack_new((*pile_b)->num);
	if (!tmp)
		free_stacks_and_exit(data);
	stack_add_front(pile_a, tmp);
	(*pile_a)->sorted_pos = tmp_pos;
	if (!(*pile_b)->next)
		stack_delone(pile_b);
	else
	{
		tmp_2 = (*pile_b)->next;
		stack_delone(pile_b);
		*pile_b = tmp_2;
	}
	msg_writer(STDOUT_FILENO, "pa\n", data);
	data->counter++;
	return (0);
}

int	pb(t_stack **pile_a, t_stack **pile_b, t_data *data)
{
	t_stack		*tmp;
	t_stack		*tmp_2;
	int			tmp_pos;

	if (*pile_a == NULL)
		return (1);
	tmp_pos = (*pile_a)->sorted_pos;
	tmp = stack_new((*pile_a)->num);
	if (!tmp)
		free_stacks_and_exit(data);
	stack_add_front(pile_b, tmp);
	(*pile_b)->sorted_pos = tmp_pos;
	if (!(*pile_a)->next)
		stack_delone(pile_a);
	else
	{
		tmp_2 = (*pile_a)->next;
		stack_delone(pile_a);
		*pile_a = tmp_2;
	}
	msg_writer(STDOUT_FILENO, "pb\n", data);
	data->counter++;
	return (0);
}
