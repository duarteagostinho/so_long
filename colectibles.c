/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colectibles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:17:38 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/29 20:17:38 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	colectibles_init()
{
	int x;
	int y;
	t_colectible *colectible;

	x = 0;
	ft_data()->colectible_list = NULL;
	while (x < ft_data()->width)
	{
		y = 0;
		while (y < ft_data()->height)
		{
			if (ft_data()->map->map[y - SPRITE_SIZE][x - SPRITE_SIZE] == 'C')
			{
				colectible = malloc(sizeof(t_colectible));
				colectible->x = x;
				colectible->y = y;
				ft_lstadd_back(&ft_data()->colectible_list, ft_lstnew(colectible));
			}
			y += SPRITE_SIZE;
		}
		x += SPRITE_SIZE;
	}
} */

void	draw_colectibles()
{
	t_list *tmp;
	t_colectible *colectible;

	ft_data()->colectible_img = ft_load_image("images/mushroom.xpm");
	tmp = ft_data()->colectible_list;
	while (tmp)
	{
		colectible = tmp->content;
		draw_img(ft_data()->colectible_img, colectible->x, colectible->y);
		tmp = tmp->next;
	}
}