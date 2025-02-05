#include "../so_long.h"

unsigned int *get_pixel(t_img *data, int x, int y)
{
	return ((unsigned int *)(data->adress + (y * data->line_length + x * (data->bits_per_pixel / 8))));
}

void draw_img(t_img *img, int x, int y)
{
	int x1;
	int y1;

	y1 = -1;
	while(++y1 < img->height)
	{
		x1 = -1;
		while(++x1 < img->width)
		{
			if (x + x1 < 0 || x + x1 >= ft_data()->width || y + y1 < 0 || y + y1 >= ft_data()->height)
				continue ;
			if (*get_pixel(img, x1, y1) == 0xFF000000)
				continue ;
			*get_pixel(ft_data()->canvas, x1 + x, y1 + y) = *get_pixel(img, x1, y1);
		}
	}
}

void	clear_canvas()
{
	int x;
	int y;

	y = -1;
	while (++y < ft_data()->height)
	{
		x = -1;
		while (++x < ft_data()->width)
			*get_pixel(ft_data()->canvas, x, y) = 0x00000000;
	}
}

void	update_window_size(int width, int height)
{
	if (ft_data()->window)
		mlx_destroy_window(ft_data()->mlx, ft_data()->window);
	ft_data()->window = mlx_new_window(ft_data()->mlx, width, height, "so_long");
}

bool	init_mlx()
{
	ft_data()->mlx = mlx_init();
	if (!ft_data()->mlx)
	{
		write(2, "mlx init error\n", 16);
		return (false);
	}
	update_window_size(500, 500);
	if (!ft_data()->window)
	{
		write(2, "window load error\n", 19);
		return (false);
	}
	return (true);
}
