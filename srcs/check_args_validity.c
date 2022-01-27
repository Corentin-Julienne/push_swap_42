/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:26:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/01/26 19:00:54 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_if_already_sorted(int *nums_input, int nbr_c)
{
	int	*nums_dupl;

	nums_dupl = int_arr_dup(nums_input, nbr_c);
	if (!nums_dupl)
		return (-1);
	quicksort(nums_dupl, 0, nbr_c - 1);
	if (are_arr_equals(nums_input, nums_dupl, nbr_c) == 1)
	{
		free(nums_dupl);
		return (1);
	}
	free(nums_dupl);
	return (0);
}

static int	check_if_duplicates(int	*nums, int nbr_c)
{
	int		i;
	int		j;
	int		errors;

	i = 0;
	j = 0;
	errors = 0;
	while (j < nbr_c)
	{
		while (i < nbr_c)
		{
			if (nums[j] == nums[i] && j != i)
				errors++;
			i++;
		}
		j++;
		i = 0;
	}
	if (errors)
		return (1);
	errors += check_if_already_sorted(nums, nbr_c);
	return (errors);
}

static int	check_int_limits(const char *ptn, int sign)
{
	char				*str;
	unsigned long long	res;

	str = (char *)ptn;
	res = 0;
	if (ft_strlen(str) > 19)
		return (1);
	while (str[0])
	{
		if (str[0] >= '0' && str[0] <= '9')
			res = (res * 10) + (str[0] - '0');
		else
			break ;
		str++;
	}
	if (res >= 9223372036854775808ULL && sign == 1)
		return (1);
	if (res >= 9223372036854775808ULL && sign == (-1))
		return (1);
	return (0);
}

static int	is_int_compatible(const char *str)
{
	char	*ptn;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	ptn = (char *)str;
	if (ptn[0] == '-')
	{
		sign = -1;
		ptn++;
	}
	while (ptn[i])
	{
		if (ptn[i] < 48 || ptn[i] > 58)
			return (1);
		i++;
	}
	return (check_int_limits(ptn, sign));
}

int	*check_args_are_valid(int argc, char **argv, t_data *data)
{
	int		*nums;
	int		errors;

	data->i = 1;
	errors = 0;
	while (data->i < argc)
		errors += is_int_compatible(argv[data->i++]);
	if (errors)
		return (NULL);
	nums = (int *)malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (NULL);
	data->i = 0;
	while (data->i < (argc - 1))
	{
		nums[data->i] = ft_atoi(argv[data->i + 1]);
		data->i++;
	}	
	errors = check_if_duplicates(nums, (argc - 1));
	if (errors)
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}
