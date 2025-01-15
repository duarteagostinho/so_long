#include "header.h"

/*static void set_pixel(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->adress + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int get_pixel(t_img *data, int x, int y)
{
	char *dst;

	dst = data->adress + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

static void draw_img(t_img img, int x, int y)
{
	y = 0;
	while(y < img.height)
	{
		x = 0;
		while(x < img.width)
		{
			set_pixel(img.img, x, y, get_pixel(&img, x, y));
			x++;
		}
		y++;
	}
}
 */
t_img ft_init_canvas(t_game *game)
{
	t_img img;

	img.img = mlx_new_image(game->mlx, game->width, game->height);
	img.adress = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	return (img);
}