NC = \033[0m
CYAN = \033[38;5;50m
GREEN = \033[38;5;119m
RED = \033[38;5;124m
GREY =\033[38;5;253m

NAME1 = corewar
NAME2 = asm

CC = clang
CFLAGS = -Wall -Wextra -Werror -g3

SRC_NAME1 = vm.c parse_args.c parse_champion.c give1.c give2.c into_vm.c \
	parsing_f.c parsing_f1.c parsing_f2.c init.c error_helpers.c \
	run.c op.c ops1.c ops2.c ops3.c ops4.c params_analyser.c \
	memory_helpers.c print_memory.c process_management.c ops_handler.c \

SRC_NAME2 = convert.c error.c get_instruct.c get_label.c get_param_value.c main.c method.c method2.c op.c parse1.c parse2.c \

SRC_PATH1 = ./vm
SRC_PATH2 = ./assembly

SRC1 = $(addprefix $(SRC_PATH1)/,$(SRC_NAME1))
SRC2 = $(addprefix $(SRC_PATH2)/,$(SRC_NAME2))

OBJ_PATH1 = ./objs1
OBJ_PATH2 = ./objs2

OBJ1 = $(addprefix $(OBJ_PATH1)/,$(SRC_NAME1:.c=.o))
OBJ2 = $(addprefix $(OBJ_PATH2)/,$(SRC_NAME2:.c=.o))

DIR_INC = ./dep/includes/
INC_NAME = vm.h asm.h op.h asm_struct.h
INC = $(addprefix $(DIR_INC)/,$(INC_NAME))

MY_LIB = ./dep/libft/libft.a ./dep/libvec/libvec.a ./dep/libmem/libmem.a ./dep/libft_minh/libft_all.a
MY_LIB_ASM = ./dep/libft/libft.a ./dep/libft_minh/libft_all.a
NCURSES	= -lpanel -lcurses -lcdk

all: makelibs $(NAME1) $(NAME2)

makelibs:
	@make all -C ./dep/libft_minh
	@make all -C ./dep/libft
	@make all -C ./dep/libvec
	@make all -C ./dep/libmem

$(NAME1): $(OBJ1)
	@printf "$(RED)[$(NAME1)]: $(CYAN)Compiling .o...$(GREEN)[done] $(GREY)\n"
	@printf "$(RED)[$(NAME1)]: $(CYAN)Object files compilation: $(GREEN)[OK]$(NC)\n"
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1) -I $(DIR_INC) -L $(MY_LIB) 
	@printf "$(RED)[$(NAME1)]: $(CYAN)Executable compilation: $(GREEN)[OK] $(NC)\n"

$(NAME2): $(OBJ2)
	@printf "$(RED)[$(NAME2)]: $(CYAN)Compiling .o...$(GREEN)[done] $(GREY)\n"
	@printf "$(RED)[$(NAME2)]: $(CYAN)Object files compilation: $(GREEN)[OK]$(NC)\n"
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2) -I $(DIR_INC) -L $(MY_LIB_ASM) 
	@printf "$(RED)[$(NAME2)]: $(CYAN)Executable compilation: $(GREEN)[OK] $(NC)\n"
	
$(OBJ_PATH1)/%.o: $(SRC_PATH1)/%.c
	@mkdir -p $(OBJ_PATH1)
	@printf "$(RED)[$(NAME1)]: "
	@printf "$(CYAN)Compiling $<...$(GREY)\n"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH2)/%.o: $(SRC_PATH2)/%.c
	@mkdir -p $(OBJ_PATH2)
	@printf "$(RED)[$(NAME2)]: "
	@printf "$(CYAN)Compiling $<...$(GREY)\n"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./dep/libft_minh
	@make clean -C ./dep/libft
	@make clean -C ./dep/libvec
	@make clean -C ./dep/libmem
	@rm -rf $(OBJ_PATH1)
	@rm -rf $(OBJ_PATH2)

fclean: clean
	@make fclean -C ./dep/libft_minh
	@make fclean -C ./dep/libft
	@make fclean -C ./dep/libvec
	@make fclean -C ./dep/libmem
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)
	@echo "$(CYAN)Cleaning $(NAME1): $(GREEN)Done $(NC)"
	@echo "$(CYAN)Cleaning $(NAME2): $(GREEN)Done $(NC)"

re : fclean all

.PHONY: all clean fclean re
