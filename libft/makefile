# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 17:41:31 by mipham            #+#    #+#              #
#    Updated: 2017/12/07 17:38:15 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

# Colors -Echo

_GREEN = $'\x1b[32m
_CYAN = $'\x1b[36m
_RED = $'\x1b[31m
_YELLOW = $'\x1b[33m
_PURPLE = $'\x1b[35m
_BLUE = $'\x1b[34m

SRCC = ft_putchar.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr.c ft_strlen.c \
	  ft_putnbr_fd.c ft_putnbr.c ft_putendl_fd.c ft_putendl.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_tolower.c ft_toupper.c ft_strrev.c\
	  ft_atoi.c ft_itoa.c ft_utoa.c ft_atoi_base.c\
	  ft_memset.c ft_bzero.c ft_memalloc.c ft_strnew.c ft_memdel.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strdup.c \
	  ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strdel.c ft_strstr.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strlcat.c\
	  ft_lstadd.c ft_lstnew.c ft_lstdel.c ft_lstmap.c ft_lstdelone.c\
	  ft_lstiter.c ft_strlen_skip_white.c ft_power.c ft_sqrt.c\
	  ft_is_prime.c ft_create_elem.c ft_strndup.c get_next_line.c\
		ft_putnbrbase_fd.c ft_putnbrbase.c ft_putnstr_fd.c ft_putnstr.c\
		ft_putwchar_fd.c ft_putwchar.c ft_nstrlen.c ft_max.c ft_min.c\
		ft_split_whitespace.c ft_sort_integer_table.c ft_is_sorted.c\
		ft_haschar.c ft_atoll.c ft_atou.c ft_isspace.c ft_tabnew.c\


CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRCC:.c=.o)

all: $(NAME)

.SILENT:

$(NAME): $(OBJ)
	@echo "${_YELLOW}libft generate${_END} ${_BLUE}[!${_END}]"
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	@echo "${_CYAN}cleaning objects files${_END} ${_PURPLE}[!${_END}]"

fclean: clean
	rm -f $(NAME)
	@echo "${_RED}delete $(NAME)${_END} ${_GREEN}[!${_END}]"

re: fclean all

.PHONY:
	all clean fclean re
