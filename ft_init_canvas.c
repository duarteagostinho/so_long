#include "header.h"

static void set_pixel(t_img *data, int x, int y, int color)
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
	int sx;
	int sy;

	sy = 0;
	while(sy < img.height)
	{
		sx = 0;
		while(sx < img.width)
		{
			set_pixel(img.img, sx, sy, get_pixel(&img, sx, sy));
			sx++;
		}
		sy++;
	}
}

t_img ft_init_canvas(t_game *game)
{
	t_img img;

	img.img = mlx_new_image(game->mlx, game->width, game->height);
	img.adress = mlx_get_img_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	return (img);
}