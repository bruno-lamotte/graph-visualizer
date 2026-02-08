# **************************************************************************** #
#                                 CONFIG                                       #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -O3 -MMD -MP

# **************************************************************************** #
#                                 CHEMINS                                      #
# **************************************************************************** #

SRC_DIR     = src
ALGO_DIR    = $(SRC_DIR)/algo
DISP_DIR    = $(SRC_DIR)/display
OBJ_DIR     = obj
INC_DIR     = inc
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

# **************************************************************************** #
#                                 SOURCES                                      #
# **************************************************************************** #

ALGO_FILES  = action.c \
			  bfs.c \
			  bst.c \
			  graph_process.c \
			  handle_state.c \
			  move.c \
			  parsing.c \
			  solve_map.c \
			  utils.c

DISP_FILES  = display.c \
			  animation_loop_utils.c \
			  break_anim.c \
			  coin_anim.c \
			  exit_anim.c \
			  free_textures.c \
			  hole_anim.c \
			  init_textures.c \
			  initialization.c \
			  keypress.c \
			  render_game.c \
			  render_tiles.c \
			  rendering_utils.c \
			  verif_actions_on_path.c

ALGO_SRCS   = $(addprefix $(ALGO_DIR)/, $(ALGO_FILES))
DISP_SRCS   = $(addprefix $(DISP_DIR)/, $(DISP_FILES))
SRCS        = $(ALGO_SRCS) $(DISP_SRCS)

OBJS        = $(patsubst $(ALGO_DIR)/%.c, $(OBJ_DIR)/algo/%.o, $(ALGO_SRCS)) \
			  $(patsubst $(DISP_DIR)/%.c, $(OBJ_DIR)/display/%.o, $(DISP_SRCS))
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

$(OBJ_DIR)/algo/%.o: $(ALGO_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/algo
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/display/%.o: $(DISP_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/display
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

