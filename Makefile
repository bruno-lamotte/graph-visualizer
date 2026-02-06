# **************************************************************************** #
#                                 CONFIG                                       #
# **************************************************************************** #

NAME        = solong
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -O3 -MMD -MP

# **************************************************************************** #
#                                 CHEMINS                                      #
# **************************************************************************** #

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = inc
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

# **************************************************************************** #
#                                 SOURCES                                      #
# **************************************************************************** #

SRC_FILES   = display.c \
			  action.c \
			  bfs.c \
			  bst.c \
			  graph_process.c \
			  handle_state.c \
			  move.c \
			  parsing.c \
			  solve_map.c \
			  utils.c  

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS        = $(OBJS:.o=.d)

# **************************************************************************** #
#                                 LIBRARIES                                    #
# **************************************************************************** #

LIBFT       = $(LIBFT_DIR)/libft.a

MLX         = $(MLX_DIR)/libmlx.a

INCLUDES    = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBS_FLAGS  = $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# **************************************************************************** #
#                                 RÈGLES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "Compiling Libft..."
	@make -sC $(LIBFT_DIR)

$(MLX):
	@echo "Compiling MiniLibX..."
	@make -sC $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(MLX_DIR) clean
	@echo "🧹 Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean
	@echo "🗑️  Executable removed."

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

