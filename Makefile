NC = \033[0m
CYAN = \033[38;5;50m
GREEN = \033[38;5;119m
RED = \033[38;5;124m
GREY =\033[38;5;253m

NAME1 = corewar

CC = clang
CFLAGS = -Wall -Wextra -Werror -g3

SRC_NAME1 = vm.c parse_args.c parse_champion.c give1.c give2.c into_vm.c free.c init.c error_helpers.c run.c f.c

SRC_PATH1 = ./vm

SRC1 = $(addprefix $(SRC_PATH1)/,$(SRC_NAME1))
SRC2 = $(addprefix $(SRC_PATH2)/,$(SRC_NAME2))

OBJ_PATH = ./Objs

OBJ1 = $(addprefix $(OBJ_PATH)/,$(SRC_NAME1:.c=.o))
OBJ2 = $(addprefix $(OBJ_PATH)/,$(SRC_NAME2:.c=.o))

INC1 = ./dep/vm.h
INC2 = ./Includes/visu_hex.h

MY_LIB = ./dep/libft/libft.a ./dep/libvec/libvec.a ./dep/libmem/libmem.a 
NCURSES	= -lpanel -lcurses -lcdk

all: makelibs $(NAME1) $(NAME2)

makelibs:
	@make all -C ./dep/libft
	@make all -C ./dep/libvec
	@make all -C ./dep/libmem


$(NAME1): $(OBJ1)
	@tput el
	@printf "$(RED)[$(NAME1)]: $(CYAN)Compiling .o...$(GREEN)[done] $(GREY)\n"
	@tput cud 9
	@sleep 0.5
	@tput el
	@printf "$(RED)[$(NAME1)]: $(CYAN)Object files compilation: $(GREEN)[OK]$(NC)\n"
	@sleep 0.3
	$(CC) $(CFLAGS) $(MY_LIB) -I $(INC1) $(OBJ1) -o $(NAME1)
	@printf "$(RED)[$(NAME1)]: $(CYAN)Executable compilation: $(GREEN)[OK] $(NC)\n"
	@sleep 0.3

$(NAME2): $(OBJ2)
	@tput el
	@printf "$(RED)[$(NAME2)]: $(CYAN)Compiling .o...$(GREEN)[done] $(GREY)\n"
	@tput cud 3
	@tput el
	@printf "$(RED)[$(NAME2)]: $(CYAN)Object files compilation: $(GREEN)[OK]$(NC)\n"
	$(CC) $(CFLAGS) $(MY_LIB) -I $(INC2) $(NCURSES) $(OBJ2) -o $(NAME2)
	@printf "$(RED)[$(NAME2)]: $(CYAN)Executable compilation: $(GREEN)[OK] $(NC)\n"
	@sleep 0.3
	@tput cnorm

$(OBJ_PATH)/%.o: $(SRC_PATH1)/%.c
	@tput sc
	@mkdir -p $(OBJ_PATH)
	@tput civis
	@tput rc
	@printf "$(RED)[$(NAME1)]: "
	@tput el
	@printf "$(CYAN)Compiling $<...$(GREY)\n"
	@tput il 1
	@tput el
	$(CC) $(CFLAGS) -c $< -o $@
	@sleep 0.3
	@tput rc

$(OBJ_PATH)/%.o: $(SRC_PATH2)/%.c
	@tput sc
	@mkdir -p $(OBJ_PATH)
	@tput civis
	@tput rc
	@printf "$(RED)[$(NAME2)]: "
	@tput el
	@printf "$(CYAN)Compiling $<...$(GREY)\n"
	@tput il 1
	@tput el
	$(CC) $(CFLAGS) -c $< -o $@
	@sleep 0.3
	@tput rc

clean:
	@make clean -C ./dep/libft
	@make clean -C ./dep/libvec
	@make clean -C ./dep/libmem
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C ./dep/libft
	@make fclean -C ./dep/libvec
	@make fclean -C ./dep/libmem
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)
	@echo "$(CYAN)Cleaning $(NAME1): $(GREEN)Done $(NC)"

re : fclean all

.PHONY: all clean fclean re