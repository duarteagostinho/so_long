#include "so_long.h"

int ft_loop()
{
	clear_canvas();
	draw_walls();
	draw_player();
	draw_collectibles();
	draw_exit();
	mlx_put_image_to_window(ft_data()->mlx, ft_data()->window, ft_data()->canvas->img, 0, 0);
	return 0;
}
