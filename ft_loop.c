#include "header.h"

int ft_loop(t_game *ft_data())
{
	mlx_clear_window(ft_data()->mlx, ft_data()->window);
	mlx_put_image_to_window(ft_data()->mlx, ft_data()->window, ft_data()->canvas->img, 0, 0);
	return 0;
}
