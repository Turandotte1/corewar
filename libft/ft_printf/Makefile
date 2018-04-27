# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 11:00:27 by mipham            #+#    #+#              #
#    Updated: 2017/12/19 17:30:02 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
LDFLAGS = -I./include/
SRC = \
		ft_check.c ft_display.c ft_handle1.c\
	  ft_handle2.c ft_handle3.c ft_handle4.c ft_isutils.c ft_handle_all.c\
	  ft_bzero.c ft_isdigit.c ft_max.c ft_memalloc.c\
	  ft_memset.c ft_nstrlen.c ft_putchar.c ft_putchar_fd.c\
	  ft_putnbrbase_fd.c ft_putnbrbase.c ft_putnstr.c ft_putstr.c\
	  ft_putnwstr.c ft_putwchar_fd.c ft_putwchar.c ft_strchr.c\
	  ft_strlen.c ft_tolower.c ft_putnstr_fd.c \

OBJ = $(SRC:.c=.o)
		SRCDIR	= ./src/
		OBJDIR	= ./obj/
		INCDIR	= ./include/
		SRCS	= $(addprefix $(SRCDIR), $(SRC))
		OBJS	= $(addprefix $(OBJDIR), $(OBJ))
		INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS)
		@echo "\n\t \033[32mIndexing lib ..\033[0m\n"
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "libftprintf.a create."
		@echo "\n\t \033[32m[All Fine's]\033[0m\n"

$(OBJS): $(SRCS)
		@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
		@mkdir -p $(OBJDIR)
		mv $(OBJ) $(OBJDIR)

clean:
		@echo "\nRM *.o.. \t      \033[32mDONE!\033[0m"
		@$(RM) $(OBJS)
		$(RM) $(OBJDIR)

fclean: clean
		@echo "RM libftprintf.a..    \033[32mDONE!\033[0m"
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
