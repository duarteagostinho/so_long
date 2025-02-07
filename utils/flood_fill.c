/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:15 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/07 15:25:59 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	check_n_replace(char **map, ssize_t x, ssize_t y)
{
	bool	changed;

	changed = false;
	if (x + 1 < 11 && map[y][x + 1] != '1' && map[y][x + 1] != 'P')
	{
		map[y][x + 1] = 'P';
		changed = true;
	}
	if (x - 1 >= 0 && map[y][x - 1] != '1' && map[y][x - 1] != 'P')
	{
		map[y][x - 1] = 'P';
		changed = true;
	}
	if (y + 1 < 10 && map[y + 1][x] != 'P' && map[y + 1][x] != '1')
	{
		map[y + 1][x] = 'P';
		changed = true;
	}
	if (y - 1 >= 0 && map[y - 1][x] != 'P' && map[y - 1][x] != '1')
	{
		map[y - 1][x] = 'P';
		changed = true;
	}
	return (changed);
}

/* static void	flood_fill_map(char **map)
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
				changed = changed && check_n_replace(map, x, y);
		}
	}
} */
static void	flood_fill_map(char **map)
{
    bool	changed;
    ssize_t	x;
    ssize_t	y;

    do {
        changed = false;
        for (y = 0; y < 10; y++)
        {
            for (x = 0; x < 11; x++)
            {
                if (map[y][x] == 'P')
                {
                    if (check_n_replace(map, x, y))
                    {
                        changed = true;
                    }
                }
            }
        }
    } while (changed);
}

static bool	check_chars(char **map)
{
	ssize_t	x;
	ssize_t	y;
	

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
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