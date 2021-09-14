/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:07:27 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/13 18:00:41 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h> // remove every useless headers before pushing
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/* push swap */

void 		error_and_exit(void);

/* check args validity */

void		check_args_are_valid(int argc, char **argv);

/* manage piles */

t_stack		*new_pile_item(int nb);
void		del_pile(t_stack *pile_item);
void		display_pile(t_stack *pile);
t_stack		*create_pile(int *nums, int arnb);

#endif

