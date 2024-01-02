.SUFFIXES : .c .o

NAME    := so_long
CC      := cc
CFLAGS  := -Wall -Werror -Wextra
MEMORT  := -fsanitize=address
LLDB    := -g
FRAMEWORKS := -framework OpenGL -framework AppKit

BLACK   := \033[30m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[34m
MAGENTA := \033[35m
CYAN    := \033[36m
WHITE   := \033[37m
RESET   := \033[0m

INCLUDE := -I./mlx -I./inc
SRC_DIR := ./src

SRC     := \
		main.c \
		parse.c \
		hook.c \
		is_valid_map.c \
		dfs.c \
		protect.c \
		get_next_line.c \
		get_next_line_utils.c
OBJ     := $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

LIBMLX  := ./mlx/libmlx.a

all: $(NAME)
	@echo "$(GREEN)$(NAME) created successfully$(RESET)"

$(NAME): $(LIBMLX) $(OBJ)
	@$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJ) -o $(NAME) $(LIBMLX)
	@echo "$(WHITE)Creating $@$(RESET)"

$(LIBMLX):
	@$(MAKE) all -C ./mlx
	@echo "$(GREEN)mlx compiled successfully$(RESET)"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(CYAN)Compiled:$(RESET) $< -> $@"

clean:
	@$(MAKE) clean -C ./mlx
	@rm -f $(OBJ)
	@echo "$(BLUE)Cleaned up object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)Cleaned up executable and library$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

mem:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(MEMORY)"

lldb:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(LLDB)"

.PHONY: all clean fclean re mem lldb
