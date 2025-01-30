/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:04:28 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/29 17:04:28 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player(void)
{
	ft_data()->img = ft_load_image("images/Idle-Sheet.xpm");
}

void	draw_player(void)
{
	draw_img(ft_data()->img, ft_data()->player.x, ft_data()->player.y);
}
