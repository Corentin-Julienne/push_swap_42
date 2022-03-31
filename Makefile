# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 16:06:37 by cjulienn          #+#    #+#              #
#    Updated: 2022/03/31 18:14:17 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

SRCS= ./srcs/actions/actions_1.c \
	  ./srcs/actions/actions_2.c \
	  ./srcs/algos/algo_big_nbrs/algo_big_nbrs_1.c \
	  ./srcs/algos/algo_big_nbrs/algo_big_nbrs_2.c \
	  ./srcs/algos/algo_case_2.c \
	  ./srcs/algos/algo_case_3.c \
	  ./srcs/algos/algo_case_4.c \
	  ./srcs/algos/algo_case_5.c \
	  ./srcs/args_processing/check_args_validity_1.c \
	  ./srcs/args_processing/check_args_validity_2.c \
	  ./srcs/args_processing/format_input.c \
	  ./srcs/stacks/manage_piles.c \
	  ./srcs/stacks/stack_utils_1.c \
	  ./srcs/stacks/stack_utils_2.c \
	  ./srcs/utils/algo_utils.c \
	  ./srcs/utils/free.c \
	  ./srcs/utils/outliers.c \
	  ./srcs/utils/quick_sort.c \
	  ./srcs/push_swap.c \
	  ## debug utils to suppress before correction
	  ./srcs/debug_utils.c
	  
OBJS = $(SRCS:.c=.o)

INCLUDE_PATH = ./includes/

LIBFT_LIB = libft.a
LIBFT_PATH = ./libft/

CC= gcc
CFLAGS= -Wall -Wextra -Werror -I$(INCLUDE_PATH)

RM= rm -f

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)
	
fclean:	clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
