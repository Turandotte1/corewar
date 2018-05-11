# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 12:08:53 by mipham            #+#    #+#              #
#    Updated: 2018/04/23 12:35:02 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	asm


#SRC := $(shell cd src ; find . -type f -name '*.c' | sed 's/^..//'  |  tr '\n' ' ')
#
SRC 		=	src/main.c	\
				src/get_instruct.c \
				src/convert.c	\
				src/get_label.c\
				src/get_param_value.c	\
				src/error.c	\
				src/method.c \
				src/method2.c \
				src/op.c \
				src/parse1.c \
				src/parse2.c \

OBJ			=	$(SRC:.c=.o)

INC			=	-I ./includes -I ./libft
LINK		=	-L./libft -lft_all

FLAGS		=	$(CFLAGS)
CFLAGS		=	-Wall -Wextra -Werror -g3
#P			=	-pedantic
#EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes	\
#				-Qunused-arguments

CC			=	$(CLANG)
GCC			=	/usr/local/bin/gcc
CLANG		=	/usr/bin/clang
RM			=	/bin/rm -fv

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				make -C ./libft
				$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
clean		:
				make -C ./libft clean
				$(RM) $(OBJ)

fclean		:	clean
				make -C ./libft fclean
				$(RM) $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o			:	%.c
				$(CC) $(FLAGS) $(INC) -c $< -o $@
