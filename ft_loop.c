#include "so_long.h"

int ft_loop()
{
	mlx_clear_window(ft_data()->mlx, ft_data()->window);
	mlx_put_image_to_window(ft_data()->mlx, ft_data()->window, ft_data()->img->img, ft_data()->player.x, ft_data()->player.y);
	return 0;
}
