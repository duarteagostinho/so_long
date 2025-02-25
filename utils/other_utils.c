/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:52:14 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/25 23:51:27 by duandrad         ###   ########.fr       */
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

bool	line_is_walls(char *line)
{
	ssize_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}
