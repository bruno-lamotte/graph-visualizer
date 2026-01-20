NAME		=	graph

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -g3

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	inc
LIBFT_DIR	=	libft

SRCS		=	$(SRC_DIR)/action.c \
				$(SRC_DIR)/bfs.c \
				$(SRC_DIR)/bst.c \
				$(SRC_DIR)/graph_process.c \
				$(SRC_DIR)/main.c \
				$(SRC_DIR)/move.c

OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS		=	$(OBJS:.o=.d)

INCLUDES	=	-I$(INC_DIR) -I$(LIBFT_DIR)

LIBFT		=	$(LIBFT_DIR)/libft.a

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
			@make -C $(LIBFT_DIR)

clean:
			@make -C $(LIBFT_DIR) clean
			rm -rf $(OBJ_DIR)

fclean:		clean
			@make -C $(LIBFT_DIR) fclean
			rm -f $(NAME)

re:			fclean all

-include $(DEPS)

.PHONY:		all clean fclean re
