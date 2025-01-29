#include "so_long.h"

t_game *ft_data()
{
	static t_game g;

	return (&g);
}

int main()
{
	t_wall **wall_list;
	t_wall *wall;
	
	ft_data()->width = 800;
	ft_data()->height = 800;
	ft_data()->mlx = mlx_init();
	ft_data()->window = mlx_new_window(ft_data()->mlx, ft_data()->width, ft_data()->height, "so_long");
	ft_data()->player.x = 400;
	ft_data()->player.y = 400;

	ft_data()->canvas = ft_init_canvas();
	ft_data()->wall_img = ft_load_image("images/ROUNDBRICKS.xpm");
	ft_data()->img = ft_load_image("images/Idle-Sheet.xpm");
	wall_list = malloc(sizeof(t_wall));
	if (wall_list == NULL)
		write(1, "error no wall_list", 14);
	wall = malloc(sizeof(t_wall));
	if (wall == NULL)
		write(1, "error no wall", 14);
	wall->x = 0;
	wall->y = 0;
	ft_data()->wall_list = ft_lstnew(wall);
	mlx_hook(ft_data()->window, 2, 1L<<0, ft_move, NULL);
	// mlx_hook(ft_data()->window, 17, 1L<<0, exit_game, NULL);
	mlx_loop_hook(ft_data()->mlx, ft_loop, NULL);
	mlx_loop(ft_data()->mlx);
	return 0;
}
