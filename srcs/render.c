/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:47:13 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/06 15:36:42 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_player(void)
{
	draw_img(game()->player_img, game()->player.x * SPRITE_SIZE,
		game()->player.y * SPRITE_SIZE);
}

void	draw_walls(void)
{
	t_list	*tmp;
	t_point	*wall;

	tmp = game()->wall_list;
	while (tmp)
	{
		wall = tmp->content;
		draw_img(game()->wall_img, wall->x * SPRITE_SIZE,
			wall->y * SPRITE_SIZE);
		tmp = tmp->next;
	}
}

void	draw_collectibles(void)
{
	t_list			*tmp;
	t_collectible	*collectible;

	tmp = game()->collectible_list;
	while (tmp)
	{
		collectible = tmp->content;
		if (collectible->active)
			draw_img(game()->collectible_img, collectible->x * SPRITE_SIZE,
				collectible->y * SPRITE_SIZE);
		tmp = tmp->next;
	}
}

void	draw_enemies(void)
{
	t_list	*tmp;
	t_point	*enemy;

	tmp = game()->enemy_list;
	while (tmp)
	{
		enemy = tmp->content;
		draw_img(game()->enemy_img, enemy->x * SPRITE_SIZE,
			enemy->y * SPRITE_SIZE);
		tmp = tmp->next;
	}
}

void	draw_exit(void)
{
	draw_img(game()->exit_img, game()->exit.x * SPRITE_SIZE,
		game()->exit.y * SPRITE_SIZE);
}
