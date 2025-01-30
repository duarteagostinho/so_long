#include "so_long.h"

t_game *ft_data()
{
	static t_game g;

	return (&g);
}

bool	load_images(void)
{
	ft_data()->wall_img = ft_load_image("images/ROUNDBRICKS.xpm");
	ft_data()->player_img = ft_load_image("images/Idle-Sheet.xpm");
	if (!ft_data()->wall_img || !ft_data()->player_img)
	{
		write(2, "image load error\n", 19);
		return (false);
	}
	ft_data()->canvas = ft_new_image(ft_data()->width, ft_data()->height);
	return (true);
}
bool	init_mlx()
{
	ft_data()->mlx = mlx_init();
	if (!ft_data()->mlx)
	{
		write(2, "mlx init error\n", 17);
		return (false);
	}
	update_window_size(500, 500);
	if (!ft_data()->window)
	{
		write(2, "window load error\n", 20);
		return (false);
	}
	return (true);
}

bool	check_args(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		write(1, "args error\n", 13);
		return (false);
	}
	return (true);
}

void	loop()
{
	mlx_hook(ft_data()->window, 2, 1L<<0, ft_move, NULL);
	//mlx_hook(ft_data()->window, 17, 1L<<0, exit_game, NULL);
	mlx_loop_hook(ft_data()->mlx, ft_loop, NULL);
	mlx_loop(ft_data()->mlx);
	printf("%p\n", ft_data()->mlx);
}

void	update_window_size(int width, int height)
{
	if (ft_data()->window)
		mlx_destroy_window(ft_data()->mlx, ft_data()->window);
	ft_data()->window = mlx_new_window(ft_data()->mlx, width, height, "so_long");
}

int main(int ac, char **av)
{
	if (!check_args(ac, av) || !init_mlx() || !load_map(av[1]) || !load_images())
		return (1);
	loop();
}
