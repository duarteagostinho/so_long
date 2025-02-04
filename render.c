/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:47:13 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/04 00:24:17 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(void)
{
	draw_img(ft_data()->player_img, ft_data()->player.x, ft_data()->player.y);
}

void	draw_collectible(void)
{
	draw_img(ft_data()->collectible_img, ft_data()->collectible.x, ft_data()->collectible.y);
}

void	draw_walls()
{
	t_list *tmp;
	t_wall *wall;

	tmp = ft_data()->wall_list;
	while (tmp)
	{
		wall = tmp->content;
		draw_img(ft_data()->wall_img, wall->x, wall->y);
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
		draw_img(ft_data()->collectible_img, collectible->x, collectible->y);
		tmp = tmp->next;
	}
}

void	draw_exit(void)
{
	draw_img(ft_data()->exit_img, ft_data()->exit.x, ft_data()->exit.y);
}