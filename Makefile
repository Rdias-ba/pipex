# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 00:14:33 by rdias-ba          #+#    #+#              #
#    Updated: 2023/08/25 19:54:38 by rdias-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= pipex
LIB_NAME			= libft
CC					= gcc
CFLAGS				= -Wextra -Werror -Wall

SRCS_DIR	= srcs/
OBJS_DIR	= objs/
LIB_DIR		= libft/
HEADERS_DIR	= headers/

HEADERS		= pipex.h

SRCS		= main.c pipex_utils.c\

OBJS		= $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(OBJS_DIR):
			mkdir -p $@

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS_DIR)$(HEADERS)
			$(CC) $(CFLAGS) -I$(LIB_NAME) -O3 -g -c $< -o $@

$(NAME): $(OBJS_DIR) $(LIB_DIR)$(LIB_NAME).a $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)$(LIB_NAME).a -o $@

$(LIB_DIR)$(LIB_NAME).a:
			$(MAKE) -C $(LIB_DIR)

clean: 
			rm -rf $(OBJS_DIR)
			$(MAKE) -C $(LIB_DIR) clean

fclean: clean
			rm -rf $(NAME)
			$(MAKE) -C $(LIB_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re
