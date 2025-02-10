/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:52:14 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 14:52:52 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_player_pos(int i, int line_pos)
{
	game()->player.x = i;
	game()->player.y = line_pos;
}

void	set_exit_point(int i, int line_pos)
{
	game()->exit.x = i;
	game()->exit.y = line_pos;
}
