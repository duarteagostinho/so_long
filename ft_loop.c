#include "so_long.h"

void	draw_walls(void)
{
	t_list	*curr;
	t_wall	*wall;

	curr = ft_data()->wall_list;
	while (curr)
	{
		wall = (t_wall *)curr->content;
		draw_img(ft_data()->wall_img, wall->x * SPRITE_SIZE, wall->y * SPRITE_SIZE);
		curr = curr->next;
	}
}

void	draw_player(void)
{
	draw_img(ft_data()->img, ft_data()->player.x, ft_data()->player.y);
}

int ft_loop()
{
	clear_canvas();
	draw_walls();
	draw_player();
	mlx_put_image_to_window(ft_data()->mlx, ft_data()->window, ft_data()->canvas->img, 0, 0);
	return 0;
}
