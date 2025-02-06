/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:15 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/06 19:10:17 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_n_replace(char **map, ssize_t x, ssize_t y)
{
	bool	changed;

	changed = false;
	if (map[y][x + 1] != '1')
	{
		map[y][x + 1] = 'P';
		changed = true;
	}
	if (map[y][x - 1] != '1')
	{
		map[y][x + 1] = 'P';
		changed = true;
	}
	if (map[y + 1][x] != 'P')
	{
		map[y + 1][x] = 'P';
		changed = true;
	}
	if (map[y - 1][x] != 'P')
	{
		map[y - 1][x] = 'P';
		changed = true;
	}
	return (false);
}

static void	flood_fill_map(char **map)
{
	ssize_t	x;
	ssize_t	y;
	bool	changed;
	
	changed = true;
	while (changed)
	{
		changed = false;
		y = -1;
		while (map[++y])
		{
			x = -1;
			while (map[y][++x])
				changed = changed || check_n_replace(map, x, y);
		}
	}
}

static bool	check_chars(char **map)
{
	ssize_t	x;
	ssize_t	y;
	

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] != '1' && map[y][x] != 'P')
				return(false);
	}
	return (true);
}

bool	can_finish(char **map)
{
	flood_fill_map(map);
	return(check_chars(map));
}