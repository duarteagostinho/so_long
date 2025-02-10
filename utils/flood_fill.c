/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:15 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 00:57:50 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_n_replace(char **map, ssize_t x, ssize_t y)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		game()->exit_count++;
	if (map[y][x] == 'P')
		game()->player_count++;
	if (map[y][x] == 'C')
		game()->coll_count++;
	map[y][x] = '1';
	check_n_replace(map, x + 1, y);
	check_n_replace(map, x - 1, y);
	check_n_replace(map, x, y + 1);
	check_n_replace(map, x, y - 1);
}

static void	flood_fill_map(char **map)
{
	bool	changed;
	ssize_t	x;
	ssize_t	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				check_n_replace(map, x, y);
				changed = true;
				return ;
			}
		}
	}
}

static bool	check_chars(char **map)
{
	ssize_t	x;
	ssize_t	y;
	ssize_t	map_len;

	y = -1;
	map_len = array_length(map);
	while (++y < map_len)
	{
		x = -1;
		while (++x < ft_strlen_t(map[y], '\n'))
		{
			if (map[y][x] != '1')
			{
				ft_lstclear(&game()->wall_list, free);
				ft_lstclear(&game()->collectible_list, free);
				free_array(map);
				fputstr("Error\nFinishing not possible\n", 1);
				exit(1);
			}
		}
	}
	return (true);
}

bool	can_finish(char **map)
{
	flood_fill_map(map);
	return (check_chars(map));
}
