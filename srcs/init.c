/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 01:20:38 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 01:20:38 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static unsigned int	*get_pixel(t_img *data, int x, int y)
{
	return ((unsigned int *)(data->adress
		+ (y * data->line_length + x * (data->bits_per_pixel / 8))));
}

void	draw_img(t_img *img, int x, int y)
{
	int	x1;
	int	y1;

	y1 = -1;
	while (++y1 < img->height)
	{
		x1 = -1;
		while (++x1 < img->width)
		{
			if (x + x1 < 0 || x + x1 >= game()->width || y + y1 < 0
				|| y + y1 >= game()->height)
				continue ;
			if (*get_pixel(img, x1, y1) == 0xFF000000)
				continue ;
			*get_pixel(game()->canvas,
				x1 + x, y1 + y) = *get_pixel(img, x1, y1);
		}
	}
}

void	clear_canvas(void)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game()->height)
	{
		x = -1;
		while (++x < game()->width)
			*get_pixel(game()->canvas, x, y) = 0x00000000;
	}
}

bool	init_mlx(void)
{
	game()->mlx = mlx_init();
	if (!game()->mlx)
	{
		fputstr("Error\nMlx init\n", 1);
		return (false);
	}
	game()->window = mlx_new_window(game()->mlx,
		game()->width, game()->height, "so_long");
	if (!game()->window)
	{
		fputstr("Error\nWindow load\n", 1);
		return (false);
	}
	return (true);
}
