/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:47:13 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/30 16:09:32 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(void)
{
	draw_img(ft_data()->player_img, ft_data()->player.x, ft_data()->player.y);
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
