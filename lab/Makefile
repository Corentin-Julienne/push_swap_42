# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 10:09:05 by cjulienn          #+#    #+#              #
#    Updated: 2022/01/25 10:15:03 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap_lab

SRCS= ./srcs/actions_1.c \
	  ./srcs/actions_2.c \
	  ./srcs/algo_utils.c \
	  ./srcs/check_args_validity.c \
	  ./srcs/decision_tree.c \
	  ./srcs/manage_piles.c \
	  ./srcs/outliers.c \
	  ./srcs/push_swap.c \
	  ./srcs/stack_utils_1.c \
	  ./srcs/stack_utils_2.c

OBJS = $(SRCS:.c=.o)

LIBFT_LIB = libft.a
LIBFT_PATH = ../libft/

CC= gcc
CFLAGS= -Wall -Wextra -Werror -I.

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
