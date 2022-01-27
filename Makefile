# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 16:06:37 by cjulienn          #+#    #+#              #
#    Updated: 2022/01/26 19:16:34 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

SRCS= ./srcs/algos/algo_case_2.c \
	  ./srcs/algos/algo_case_3.c \
	  ./srcs/algos/algo_case_4.c \
	  ./srcs/algos/algo_case_5.c \
	  ./srcs/algos/algo_case_6_99.c \
	  ./srcs/algos/algo_case_100_to_inf.c \
	  ./srcs/actions_1.c \
	  ./srcs/actions_2.c \
	  ./srcs/algo_utils.c \
	  ./srcs/check_args_validity.c \
	  ./srcs/debug_utils.c \
	  ./srcs/decision_tree.c \
	  ./srcs/manage_piles.c \
	  ./srcs/outliers.c \
	  ./srcs/push_swap.c \
	  ./srcs/quick_sort.c \
	  ./srcs/stack_utils_1.c \
	  ./srcs/stack_utils_2.c

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
