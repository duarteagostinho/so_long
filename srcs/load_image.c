#include "../so_long.h"

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

t_img *ft_new_image(int width, int height)
{
	t_img *img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(ft_data()->mlx, width, height);
	if (!img->img)
		return(NULL);
	img->adress = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

bool	load_images(void)
{
	ft_data()->wall_img = ft_load_image("images/wall.xpm");
	ft_data()->player_img = ft_load_image("images/player.xpm");
	ft_data()->collectible_img = ft_load_image("images/collectible.xpm");
	ft_data()->exit_img = ft_load_image("images/exit.xpm");
	if (!ft_data()->wall_img || !ft_data()->player_img || !ft_data()->collectible_img || !ft_data()->exit_img)
	{
		write(2, "image load error\n", 18);
		return (false);
	}
	ft_data()->canvas = ft_new_image(ft_data()->width, ft_data()->height);
	return (true);
}