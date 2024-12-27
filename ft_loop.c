#include "header.h"



int ft_loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->canvas.img, 0, 0);
	return 0;
}
