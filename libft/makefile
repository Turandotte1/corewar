# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/27 18:28:29 by mipham            #+#    #+#              #
#    Updated: 2018/05/15 13:09:04 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft_all.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
#OBJS = $(SRCS:.c=.o)

PRINTF_DIR=ft_printf/
PRINTF_LIB=ft_printf/libftprintf.a
LIBFT_DIR=libft2/
LIBFT_LIB=libft2/libft.a

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

$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) 
	$(PREFIX)
	#cp $(LIBFT_LIB) $(NAME)
	cp $(PRINTF_LIB) $(NAME)

#%.o: %.c
#	$(PREFIX)
#	$(CC) $(CFLAGS) -I $(PRINTF_DIR) -I $(LIBFT_DIR) -o $@ -c $<

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR) all
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR) all

clean:
	@make -C $(PRINTF_DIR) clean
	$(PREFIX)
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean:
	@make -C $(PRINTF_DIR) fclean
	$(PREFIX)
	rm -f $(OBJS)
	$(PREFIX)
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
