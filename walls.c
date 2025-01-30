/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:47:25 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/29 16:47:25 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walls_init()
{
	int x;
	int y;
	t_wall *wall;

	x = 0;
	ft_data()->wall_list = NULL;
	while (x < ft_data()->width)
	{
		y = 0;
		while (y < ft_data()->height)
		{
			if (x == 0 || x == ft_data()->width - SPRITE_SIZE || y == 0 || y == ft_data()->height - SPRITE_SIZE)
			{
				wall = malloc(sizeof(t_wall));
				wall->x = x;
				wall->y = y;
				ft_lstadd_back(&ft_data()->wall_list, ft_lstnew(wall));
			}
			y += SPRITE_SIZE;
		}
		x += SPRITE_SIZE;
	}
}

void	draw_walls()
{
	t_list *tmp;
	t_wall *wall;

	ft_data()->wall_img = ft_load_image("images/ROUNDBRICKS.xpm");
	tmp = ft_data()->wall_list;
	while (tmp)
	{
		wall = tmp->content;
		draw_img(ft_data()->wall_img, wall->x, wall->y);
		tmp = tmp->next;
	}
}