NC = \033[0m
CYAN = \033[38;5;50m
GREEN = \033[38;5;119m
RED = \033[38;5;124m
GREY =\033[38;5;253m

NAME1 = corewar
NAME2 = asm

CC = clang
CFLAGS = -Wall -Wextra -Werror -g3

SRC_NAME1 = 
SRC_NAME2 = 

SRC_PATH1 = ./vm
SRC_PATH2= ./asm

SRC1 = $(addprefix $(SRC_PATH1)/,$(SRC_NAME1))
SRC2 = $(addprefix $(SRC_PATH2)/,$(SRC_NAME2))

OBJ_PATH = ./Objs

OBJ1 = $(addprefix $(OBJ_PATH)/,$(SRC_NAME1:.c=.o))
OBJ2 = $(addprefix $(OBJ_PATH)/,$(SRC_NAME2:.c=.o))

#INC1 = ./dep
#INC2 = ./dep

NCURSES	= -lpanel -lcurses -lcdk
#MY_LIB = ./dep/libft.a

all: makelibs $(NAME1) $(NAME2)

makelibs:
	@make all -C Libft

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
	@make -C Libft clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C Libft fclean
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)
	@echo "$(CYAN)Cleaning $(NAME1): $(GREEN)Done $(NC)"
	@echo "$(CYAN)Cleaning $(NAME2): $(GREEN)Done $(NC)"

re : fclean all

.PHONY: all clean fclean re