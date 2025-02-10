/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 01:26:28 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 01:26:28 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	*ft_load_image(char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(game()->mlx, path,
			&img->width, &img->height);
	if (!img->img)
		return (NULL);
	img->adress = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

t_img	*ft_new_image(int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(game()->mlx, width, height);
	if (!img->img)
		return (NULL);
	img->adress = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

bool	load_images(void)
{
	game()->wall_img = ft_load_image("images/wall.xpm");
	game()->player_img = ft_load_image("images/player.xpm");
	game()->collectible_img = ft_load_image("images/collectible.xpm");
	game()->exit_img = ft_load_image("images/exit.xpm");
	if (!game()->wall_img || !game()->player_img || !game()->collectible_img
		|| !game()->exit_img)
	{
		fputstr("Error\nImage load\n", 1);
		return (false);
	}
	game()->canvas = ft_new_image(game()->width, game()->height);
	return (true);
}
