/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:55:35 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 01:01:51 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	array_length(char **av)
{
	size_t	i;

	i = 0;
	while (av && av[i])
		i++;
	return (i);
}

char	**array_join(char **array, char *newstr)
{
	char	**new_array;
	size_t	len;
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

bool	line_is_walls(char *line)
{
	ssize_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return(false);
		i++;
	}
	return (true);
}

bool	check_borders(char **map)
{
	ssize_t	x;
	ssize_t	y;
	size_t	map_height;
	size_t	map_width;
	bool	has_walls;
	bool	is_walls;

	y = -1;
	map_width = ft_strlen_t(map[0], '\n');
	map_height = array_length(map);
	while (++y < map_height)
	{
		has_walls = map[y][0] == '1' && map[y][ft_strlen_t(map[y], '\n') - 1] == '1';
		is_walls = line_is_walls(map[y]);
		if (!has_walls || ((y == 0 || y == map_height - 1) && !is_walls))
		{
			ft_lstclear(&game()->wall_list, free);
			ft_lstclear(&game()->collectible_list, free);
			free_array(map);
			fputstr("Error\nInvalid map borders\n", 1);
			return (false);
		}
	}
	return (true);
}

void	count_elements(char **map, size_t map_height, size_t map_width)
{
	ssize_t	x;
	ssize_t	y;

	y = -1;
	while (++y < map_height)
	{
		x = -1;
		while (++x < map_width)
		{
			if (map[y][x] == 'P')
				game()->player_count++;
			if (map[y][x] == 'E')
				game()->exit_count++;
			if (map[y][x] == 'C')
				game()->coll_count++;
		}
	}
}

bool	check_counters(char **map)
{
	size_t	map_height;
	size_t	map_width;

	map_height = array_length(map);
	map_width = ft_strlen_t(map[0], '\n');
	count_elements(map, map_height, map_width);
	if (game()->player_count != 1 || game()->exit_count != 1
		|| game()->coll_count < 1)
	{
		ft_lstclear(&game()->wall_list, free);
		ft_lstclear(&game()->collectible_list, free);
		free_array(map);
		fputstr("Error\nInvalid number of components\n", 1);
		return (false);
	}
	return (true);
}
