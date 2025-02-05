#include "../so_long.h"

bool	check_args(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		write(1, "args error\n", 12);
		return (false);
	}
	return (true);
}

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

void	loop()
{
	mlx_hook(ft_data()->window, 17, 1L<<17, _exit_game, NULL);
	mlx_hook(ft_data()->window, 2, 1L<<0, ft_move, NULL);
	mlx_loop_hook(ft_data()->mlx, ft_loop, NULL);
	mlx_loop(ft_data()->mlx);
}

int main(int ac, char **av)
{
	if (!check_args(ac, av) || !init_mlx() || !load_map(av[1]) || !load_images())
		return (1);
	loop();
}
