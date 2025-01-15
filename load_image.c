#include "header.h"

t_img ft_load_image(void *mlx, char * path)
{
	t_img image;

	image.img = mlx_xpm_file_to_image(mlx, path, &image.width, &image.height);
	image.adress = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_lenght, &image.endian);

	return (image);
}