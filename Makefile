# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 12:16:27 by dclark            #+#    #+#              #
#    Updated: 2021/06/15 13:32:25 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C		=	client.c

SRCS_C_B	=	client_bonus.c

SRCS_S		=	server.c

SRCS_S_B	=	server_bonus.c

HEADER		=	./

NAME_S		=	server

NAME_C		=	client

NAME_S_B	=	server_bonus

NAME_C_B	=	client_bonus

OBJS_C		= $(SRCS_C:.c=.o)

OBJS_S		= $(SRCS_S:.c=.o)

OBJS_C_B	= $(SRCS_C_B:.c=.o)

OBJS_S_B	= $(SRCS_S_B:.c=.o)

CFLAGS		+=	-Wall -Werror -Wextra -I $(HEADER)

CC			=	gcc

all:	$(NAME_C) $(NAME_S)

bonus:	$(NAME_S_B) $(NAME_C_B)

clean:
	rm -f $(OBJS_S)
	rm -f $(OBJS_C)
	rm -f $(OBJS_S_B)
	rm -f $(OBJS_C_B)

fclean:	clean
	rm -f server
	rm -f client
	rm -f server_bonus
	rm -f client_bonus

re:		fclean
	make

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C)

$(NAME_S_B): $(OBJS_S_B)
	$(CC) $(CFLAGS) $(OBJS_S_B) -o $(NAME_S_B)

$(NAME_C_B): $(OBJS_C_B)
	$(CC) $(CFLAGS) $(OBJS_C_B) -o $(NAME_C_B)

.PHONY: all bonus clean fclean re
