/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:59:14 by cjulienn          #+#    #+#             */
/*   Updated: 2022/02/01 23:18:26 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	calc_len_void_arr(void **storage)
{
	int		i;
	int		len;

	i = 0;
	while (storage[i])
		i++;
	return (i);
}

void	free_void_arr(t_data *data)
{
	int		len;
	int		i;
	
	len = calc_len_void_arr(data->storage);
	i = 0;
	while (i < len)
	{
		free(data->storage[i]);
		i++;
	}
	free(data->storage);
}

void	**store_alloc_elems(t_data *data, void *elem)
{
	void	**storage;
	int		len;
	int		i;
	
	if (!data->storage)
	{
		storage = malloc(sizeof(void *) * 2);
		storage[0] = elem;
		storage[1] = NULL;
		return (storage);
	}
	len = calc_len_void_arr(data->storage);
	storage = malloc(sizeof(void *) * len + 2);
	while (i < len)
	{
		storage[i] = data->storage[i];
		i++;
	}
	storage[i] = elem;
	i++;
	storage[i] = NULL;
	free_void_arr(data);
	return (storage);
}
