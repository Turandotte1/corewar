# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/27 18:28:29 by mipham            #+#    #+#              #
#    Updated: 2018/04/27 19:22:44 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft_all.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

PRINTF_DIR=ft_printf/
PRINTF_LIB=ft_printf/libftprintf.a
LIBFT_DIR=libft/

PREFIX = @printf "["$(GREEN)"$(NAME)"$(NC)"]"$(LBLUE)" - "$(NC)

NC='\033[0m'
RED='\033[0;31m'
LRED='\033[1;31m'
LBLUE='\033[1;34m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'

all: $(NAME)

$(NAME): $(PRINTF_LIB)
	$(PREFIX)
	cp $(PRINTF_LIB) $(NAME)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR) all

clean:
	@make -C $(PRINTF_DIR) clean
	$(PREFIX)
	rm -f $(OBJS)

fclean:
	@make -C $(PRINTF_DIR) fclean
	$(PREFIX)
	rm -f $(OBJS)
	$(PREFIX)
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
