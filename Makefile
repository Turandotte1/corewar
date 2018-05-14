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

NAME	=  asm

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -g -MMD
SRC			= convert.c 		\
			error.c		\
			get_instruct.c		\
 			get_label.c			\
			get_param_value.c		\
			main.c			\
			method.c			\
			method2.c \
			op.c \
			parse1.c	\
			parse2.c	\

DIR_INC 	= includes/
INCS 		= asm.h \
			op.h \
			asm_struct.h

INC = $(addprefix $(DIR_INC), $(INCS))

DIR_LIBFT = ./libft/
DIR_H_LIBFT = ./libft/includes/
LIBFT_A = ./libft/libft_all

OBJDIR		= obj
OBJ	= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
SRD = $(addprefix $(OBJDIR)/,$(SRC:.c=.d))
VPATH:=src/:${VPATH}

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@ -I $(DIR_INC) -L $(DIR_LIBFT) -lft
	@echo "\nAsm compilation : $(_CYAN)done$(_END)"

$(OBJDIR)/%.o: %.c
	@mkdir -p obj
	@printf "%-60b\r" "$(ECHO) $(_CYAN) Compiling $@ $(_END)"
	@$(CC) $(FLAGS) -c $< -o $@ -I $(DIR_INC) -I $(DIR_H_LIBFT)

lib:
	@make -C $(DIR_LIBFT)

clean:
	@$(RM) -rf $(OBJDIR)
	@make clean -C $(DIR_LIBFT)
	@echo "$(_RED)clean asm:$(_END) done"

fclean: clean
	@$(RM) -f $(NAME)
	@make fclean -C $(DIR_LIBFT)
	@echo "$(_RED)fclean asm:$(_END) done"

re:
	@make fclean
	@make


.PHONY: all clean fclean re
-include $(OBJ:.o=.d)
