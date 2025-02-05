/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:47:13 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/04 18:46:52 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_player(void)
{
	draw_img(ft_data()->player_img, ft_data()->player.x * SPRITE_SIZE, ft_data()->player.y * SPRITE_SIZE);
}

void	draw_walls()
{
	t_list *tmp;
	t_wall *wall;

	tmp = ft_data()->wall_list;
	while (tmp)
	{
		wall = tmp->content;
		draw_img(ft_data()->wall_img, wall->x * SPRITE_SIZE, wall->y  * SPRITE_SIZE);
		tmp = tmp->next;
	}
}

void	draw_collectibles(void)
{
	t_list *tmp;
	t_collectible *collectible;

	tmp = ft_data()->collectible_list;
	while (tmp)
	{
		collectible = tmp->content;
		if (collectible->active)
			draw_img(ft_data()->collectible_img, collectible->x * SPRITE_SIZE, collectible->y * SPRITE_SIZE);
		tmp = tmp->next;
	}
}

void	draw_exit(void)
{
	draw_img(ft_data()->exit_img, ft_data()->exit.x * SPRITE_SIZE, ft_data()->exit.y * SPRITE_SIZE);
}