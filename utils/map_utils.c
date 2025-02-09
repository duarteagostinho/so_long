/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:55:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/09 03:10:48 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	array_length(char **av)
{
	size_t i;

	i = 0;
	while (av && av[i])
		i++;
	return (i);
}

char **array_join(char **array, char *newstr)
{
	char **new_array;
	size_t len;
	size_t	i;
	
	if (!newstr)
		return (array);
	len = array_length(array);
	new_array = malloc((len + 2) * sizeof(char *));
	if (!new_array)
		return (free_array(array), free(newstr), NULL);
	i = 0;
	while (array && array[i])
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = newstr;
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}
bool	check_borders(char **map)
{
	ssize_t	x;
	ssize_t	y;
	size_t	map_height;
	size_t	map_width;

	y = -1;
	map_width = ft_strlen_t(map[0], '\n');
	map_height = array_length(map);
	while (++y < map_height)
	{
		x = -1;
		while (++x < map_width)
		{
			if ((y == 0 || y == map_height - 1) && (map[y][x] != '1') ||
				((x == 0 || x == map_width) && map[y][x] != '1'))
			{
				fputstr("Error\nInvalid map borders\n", 1);
				return (false);
			}
		}
	}
	return (true);
}

bool	check_counters(char **map)
{
	ssize_t	x;
	ssize_t	y;
	size_t	end_line;
	size_t	line_len;

	y = -1;
	line_len = ft_strlen_t(map[0], '\n');
	end_line = array_length(map);
	while (++y < end_line)
	{
		x = -1;
		while (++x < line_len)
		{
			if (map[y][x] == 'P')
				game()->player_count++;
			if (map[y][x] == 'E')
				game()->exit_count++;
			if (map[y][x] == 'C')
				game()->coll_count++;
		}
	}
	if (game()->player_count != 1 || game()->exit_count != 1 || game()->coll_count < 1)
	{
		fputstr("Error\nInvalid number of game counters\n", 1);
		return (false);
	}
	return (true);
}