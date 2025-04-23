NAME = so_long
BONUS=0
SRC = srcs/collisions.c srcs/exit.c srcs/init.c srcs/load_image.c \
srcs/main.c srcs/map.c srcs/movement.c srcs/new_obj.c srcs/render.c \
utils/get_next_line.c utils/helper_utils.c utils/list_utils.c \
utils/map_utils.c utils/flood_fill.c utils/other_utils.c

OBJDIR = objs/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
CC = cc
CFLAGS = -Wall -Wextra -Werror
VPATH = utils:libft
MAPS = 4.ber 1.ber 2.ber 3.ber


ifeq ($(shell uname -s),Darwin)
	MLX_COMPILE = echo "\033[1;32mNot compiling mlx...\033[0m"
    MLX_FLAGS = -Lmlx -lmlx_Darwin -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit
else
	MLX_COMPILE = echo "\033[1;33mCompiling mlx...\033[0m"; tar -xf minilibx-linux.tgz; make -C minilibx-linux; cp minilibx-linux/libmlx.a mlx/; rm -rf minilibx-linux
    MLX_FLAGS = -Lmlx -lmlx -lXext -lX11
endif

all: $(NAME)

$(NAME): mlx/libmlx.a $(OBJDIR) $(OBJS)
	@echo "\nCompiling $(NAME)...\033[0m"
	@cc $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

mlx/libmlx.a:
	@$(MLX_COMPILE)

$(OBJDIR)%.o: %.c
	@printf "\033[1;33m.\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@printf "\033[1;33mCompiling\033[0m"
	@mkdir -p $(OBJDIR)

clean:
	@echo "\033[1;31mCleaning objects...\033[0m"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[1;31mCleaning binaries...\033[0m"
	@rm -rf $(NAME) mlx/libmlx.a minilibx-linux

re: fclean all

%.ber:
	-@./$(NAME) maps/$@

run: re $(MAPS)
	@echo "\033[1;32mRunning $(NAME)...\033[0m"
	make fclean

norm:
	@mv includes/mlx.h includes/mlx.h.bak
	-@norminette
	@mv includes/mlx.h.bak includes/mlx.h

.PHONY: all clean fclean re mlx