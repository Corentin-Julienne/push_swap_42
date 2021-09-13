/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:26:27 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/13 15:13:34 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	return (errors);
}

static void	check_int_limits(const char *ptn, int sign)
{
	char				*str;
	unsigned long long	res;

	if (!str)
		error_and_exit();
	str = (char *)ptn;
	res = 0;
	if (ft_strlen(str) > 19)
		error_and_exit();
	while (str[0])
	{
		if (str[0] >= '0' && str[0] <= '9')
			res = (res * 10) + (str[0] - '0');
		else
			break ;
		str++;
	}
	if (res >= 9223372036854775808ULL && sign == 1)
		error_and_exit();
	if (res >= 9223372036854775808ULL && sign == (-1))
		error_and_exit();
}

static void	is_int_compatible(const char *str)
{
	char	*ptn;
	int		i;
	int		sign;

	if (!ptn)
		error_and_exit();
	i = 0;
	sign = 1;
	ptn = (char *)str;
	if (ptn[0] == '-')
	{
		sign = -1;
		ptn++;
	}
	while (ptn[i++])
	{
		if (ptn[i] < 48 || ptn[i] > 58)
			error_and_exit();	
	}
	check_int_limits(ptn, sign);
}

void	check_args_are_valid(int argc, char **argv)
{
	int		j;
	int		*nums;
	int		errors;

	j = 0;
	while (argv[j++])
		is_int_compatible(argv[j]);
	j = 0;
	nums = (int *)malloc(sizeof(int) * (argc - 1));
	if (!nums)
		error_and_exit();
	while (j++ < (argc - 1))
		nums[j] = ft_atoi(argv[j]);
	errors = check_if_duplicates(nums, (argc - 1));
	if (errors != 0)
	{
		free(nums);
		error_and_exit();
	}
}
