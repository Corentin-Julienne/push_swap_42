# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 11:19:24 by cjulienn          #+#    #+#              #
#    Updated: 2022/01/27 11:23:39 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= lab

SRCS= ./quicksort.c \
	  ./main.c

OBJS = $(SRCS:.c=.o)

CC= gcc
CFLAGS= -Wall -Wextra -Werror -I.

RM= rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
