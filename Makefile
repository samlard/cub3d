#CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

GFLAGS	=	-g

MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

SRC_DIR	=	src

SRC		=	$(shell find $(SRC_DIR) -type f -name "*.c")

OBJ_DIR	=	obj

OBJ		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

INC_DIR	=	Include

LIB_DIR	=	libft42

MLX_DIR =	minilibx-linux

MLX = $(MLX_DIR)/libmlx.a

LIB		=	$(LIB_DIR)/libft.a

NAME	=	cub3D

.PHONY: all lib mlx clean fclean libclean re

all:	$(NAME)

lib:	$(LIB)

mlx:	$(MLX)

$(NAME):	$(OBJ) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(GFLAGS) $(OBJ) $(MLX_FLAGS) -o $@ -L$(LIB_DIR) -L$(MLX_DIR) -lft

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(GFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_DIR) clean

fclean:	clean
	rm -rf $(NAME) *dSYM
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

libclean:
	rm -rf $(LIB_DIR)/$(OBJ_DIR)
	rm -rf $(LIB)

re: fclean all
