#include "so_long.h"

t_game *ft_data()
{
	static t_game g;

	return (&g);
}

int main()
{
	ft_data()->mlx = mlx_init();
	load_map();
	ft_data()->window = mlx_new_window(ft_data()->mlx, ft_data()->width, ft_data()->height, "so_long");
	ft_data()->canvas = ft_init_canvas();
	ft_data()->img = ft_load_image("images/Idle-Sheet.xpm");
	ft_data()->wall_list = NULL;
	walls_init();
	load_player();
	mlx_put_image_to_window(ft_data()->mlx, ft_data()->window, ft_data()->canvas->img, 0, 0);
	mlx_put_image_to_window(ft_data()->mlx, ft_data()->window, ft_data()->img->img, ft_data()->player.x, ft_data()->player.y);
	mlx_hook(ft_data()->window, 2, 1L<<0, ft_move, NULL);
	//mlx_hook(ft_data()->window, 17, 1L<<0, exit_game, NULL);
	mlx_loop_hook(ft_data()->mlx, ft_loop, NULL);
	mlx_loop(ft_data()->mlx);
	return 0;
}
