/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:32:55 by duandrad          #+#    #+#             */
/*   Updated: 2024/12/27 19:29:10 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_img
{
	void *img;
	char *adress;
	int bits_per_pixel;
	int line_lenght;
	int endian;
	int width;
	int height;
}	t_img;

typedef struct s_player
{
	int x;
	int y;
}	t_player;

typedef struct s_game
{
	t_img img;
	t_img *canvas;
	void *mlx;
	void *display;
	void *window;
	t_player player;
	int width;
	int height;
}	t_game;

t_img ft_load_image(void *mlx, char * path);
int ft_move(int key, t_game *game);
int ft_loop(t_game *ft_data());
t_img ft_init_canvas(t_game *game);
t_game *ft_data();

#endif