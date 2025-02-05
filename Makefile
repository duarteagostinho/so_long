NAME = so_long
SRCS = colectibles.c collisions.c ft_init_canvas.c ft_loop.c\
get_next_line.c load_image.c main.c map.c movement.c render.c\
utils.c utils2.c utils3.c utils4.c walls.c
OBJS = $(SRCS:.c=.o)
CC = cc
CC_FLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
INCLUDES = -I/usr/include -Imlx

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re