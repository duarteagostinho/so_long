/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:19:47 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/06 16:50:56 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char **get_map_lines(char *path)
{
	int fd;
	char **array;
	char *line;
	bool	start;

	start = true;
	array = NULL;
	line = NULL;
	fd = open(path, O_RDONLY);
	while (start || line)
	{
		start = false;
		line = get_next_line(fd);
		array = array_join(array, line);
		if (!array)
			return (close(fd), NULL);
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
	size_t i;
	size_t first_line_length;
	char *line;

	i = -1;
	first_line_length = ft_strlen_t(lines[0], '\n');
	while (lines[++i])
	{
		line = lines[i];
		if (!process_line(line, i, first_line_length))
			return (false);
	}
	game()->width = first_line_length * SPRITE_SIZE;
	game()->height = i * SPRITE_SIZE;
	update_window_size(game()->width, game()->height);
	if (!game()->window)
		return (false);
	return (true);
}
bool	load_map(char *path)
{
	char **lines;
	bool check;

	lines = get_map_lines(path);
	if (!lines)
	{
		fputstr("error loading map lines\n", 2);
		return (false);
	}
	check = process_lines(lines) && can_finish(lines);
	free_array(lines);
	if (!check)
	{
		fputstr("error processing map lines\n", 2);
		return (false);
	}
	return (true);
}
