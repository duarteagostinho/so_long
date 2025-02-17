NAME = so_long
SRCS = srcs/collisions.c srcs/exit.c srcs/init.c srcs/load_image.c \
srcs/main.c srcs/map.c srcs/movement.c srcs/new_obj.c srcs/render.c \
utils/get_next_line.c utils/helper_utils.c utils/list_utils.c \
utils/map_utils.c utils/flood_fill.c utils/other_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CC_FLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
INCLUDES = -I/usr/include -Imlx

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

lib:
	cd minilibx-linux && make && cd ..

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re