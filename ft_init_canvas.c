#include "so_long.h"

/* static void set_pixel(t_img *data, int x, int y, int color)
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
} */

t_img *ft_init_canvas()
{
	t_img *img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(ft_data()->mlx, ft_data()->width, ft_data()->height);
	if (!img->img)
		return(NULL);
	img->adress = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}