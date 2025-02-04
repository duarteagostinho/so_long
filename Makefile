NAME = so_long.a
SRCS = 
OBJS = 
CC = cc
CC_FLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
INCLUDES = -I/usr/include -Imlx


r:
	cc -o so_long $(CC_FLAGS) *.c  $(MLX_FLAGS) && ./so_long "maps/map3.ber"

clean:
	rm -rf ./so_long