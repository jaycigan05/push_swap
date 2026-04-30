# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagan <jagan@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/03/22 10:10:10 by jagan            #+#    #+#              #
#    Updated: 2026/04/30 14:00:00 by jagan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS_NAME	=	checker

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I includes
RM			=	rm -f

SRCS		=	srcs/main.c \
				srcs/parse.c \
				srcs/utils.c \
				srcs/utils2.c \
				srcs/stack_ops.c \
				srcs/push_ops.c \
				srcs/rotate_ops.c \
				srcs/rotate_wrap.c \
				srcs/rrotate_wrap.c \
				srcs/sort_utils.c \
				srcs/sort_lis_utils.c \
				srcs/sort_cost_utils.c \
				srcs/sort_large_utils.c \
				srcs/sort_large_move.c \
				srcs/sort_large.c \
				srcs/sort_small.c \
				srcs/sort.c

BONUS_SRCS	=	srcs/checker_bonus.c \
				srcs/checker_utils_bonus.c \
				srcs/parse.c \
				srcs/utils.c \
				srcs/utils2.c \
				srcs/stack_ops.c \
				srcs/rotate_ops.c

OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re