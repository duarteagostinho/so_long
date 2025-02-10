/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:19:47 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 00:39:55 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**get_map_lines(char *path)
{
	int		fd;
	char	**array;
	char	*line;

	array = NULL;
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), free(line), array);
		array = array_join(array, line);
		if (!array)
			return (close(fd), free_array(array), NULL);
	}
	return (close(fd), array);
}

bool	process_line(char *line, size_t line_pos, size_t first_line_len)
{
	size_t	i;

	if ((size_t)ft_strlen_t(line, '\n') != first_line_len)
		return (false);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '1')
			new_wall((int)(i), (int)(line_pos));
		if (line[i] == 'C')
			new_collectible((int)(i), (int)(line_pos));
		if (line[i] == 'P')
		{
			game()->player.x = (int)(i);
			game()->player.y = (int)(line_pos);
		}
		if (line[i] == 'E')
		{
			game()->exit.x = (int)(i);
			game()->exit.y = (int)(line_pos);
		}
	}
	return (true);
}

bool	process_lines(char **lines)
{
	size_t	i;
	size_t	first_line_length;
	size_t	map_height;
	char	*line;

	if (!lines)
	{
		free_array(lines);
		return (false);
	}
	i = -1;
	first_line_length = ft_strlen_t(lines[0], '\n');
	while (lines[++i])
	{
		line = lines[i];
		if (!process_line(line, i, first_line_length))
		{
			free_array(lines);
			return (false);
		}
		game()->width = first_line_length * SPRITE_SIZE;
	}
	game()->height = i * SPRITE_SIZE;
	return (true);
}

bool	load_map(char *path)
{
	char	**lines;
	bool	check;

	lines = get_map_lines(path);
	if (!lines)
	{
		free_array(lines);
		fputstr("Error\nLoading map lines\n", 1);
		return (false);
	}
	game()->map = lines;
	check = process_lines(lines);
	if (!check)
	{
		fputstr("Error\nProcessing map lines\n", 1);
		return (false);
	}
	check = check_borders(lines) && check_counters(lines) && can_finish(lines);
	if (!check)
		return (false);
	return (true);
}
