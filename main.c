#include "so_long.h"

t_game *ft_data()
{
	static t_game g;

	return (&g);
}

int main()
{
	ft_data()->width = 800;
	ft_data()->height = 800;
	ft_data()->mlx = mlx_init();
	if (ft_data()->mlx == NULL)
		write(1, "error no init", 14);
	ft_data()->window = mlx_new_window(ft_data()->mlx, ft_data()->width, ft_data()->height, "Magico Drogado");
	if (ft_data()->window == NULL)
		write(1, "error na window", 16);
	ft_data()->player.x = 400;
	ft_data()->player.y = 400;

	ft_data()->canvas = ft_init_canvas();
	if (ft_data()->canvas == NULL)
		write(1, "error no canvas", 16);
	ft_data()->img = ft_load_image("images/Idle-Sheet.xpm");
	mlx_hook(ft_data()->window, 2, 1L<<0, ft_move, NULL);
	mlx_loop_hook(ft_data()->mlx, ft_loop, NULL);
	mlx_loop(ft_data()->mlx);
	return 0;
}
