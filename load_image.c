#include "so_long.h"

t_img *ft_load_image(char *path)
{
	t_img *img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(ft_data()->mlx, path, &img->width, &img->height);
	if (!img->img)
		return(NULL);
	img->adress = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}