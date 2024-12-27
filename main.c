#include "header.h"

t_game *ft_data()
{
	static t_game g;

	return (&g);
}


int main()
{

	ft_data()->width = 400;
	ft_data()->height = 400;
	ft_data()->mlx = mlx_init();
	ft_data()->window = mlx_new_window(ft_data()->mlx, ft_data()->width, ft_data()->height, "Window1");
	ft_data()->player.x = 200;
	ft_data()->player.y = 200;

	//ft_data()->img.img = mlx_new_image(ft_data()->mlx, 400, 400);
	//ft_data()->img.adress = mlx_get_data_addr(ft_data()->img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	ft_data()->img = ft_init_canvas(ft_data());
	ft_data()->img = ft_load_image(ft_data()->mlx, "images/Idle-Sheet.xpm");
	mlx_hook(ft_data()->window, 2, 1L<<0, ft_move, ft_data());
	mlx_loop_hook(ft_data()->mlx, ft_loop, ft_data());
	mlx_loop(ft_data()->mlx);
	return 0;
}
