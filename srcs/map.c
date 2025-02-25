/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:19:47 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/25 23:31:40 by duandrad         ###   ########.fr       */
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

	if (((size_t)ft_strlen_t(line, '\n')) != first_line_len)
		return (false);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '1')
			new_wall((int)(i), (int)(line_pos));
		if (line[i] == 'X')
			new_enemy((int)(i), (int)(line_pos));
		if (line[i] == 'C')
			new_collectible((int)(i), (int)(line_pos));
		if (line[i] == 'P')
			set_player_pos((int)(i), (int)(line_pos));
		if (line[i] == 'E')
			set_exit_point((int)(i), (int)(line_pos));
		if (line[i] != '1' && line[i] != 'X' && line[i] != 'C'
			&& line[i] != 'P' && line[i] != 'E' && line[i] != '0'
			&& line[i] != '\n')
		{
			fputstr("Invalid character\n", 1);
			return (false);
		}
	}
	return (true);
}

bool	process_lines(char **lines)
{
	size_t	i;
	size_t	first_line_length;
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
			ft_lstclear(&game()->wall_list, free);
			ft_lstclear(&game()->collectible_list, free);
			free_array(lines);
			return (false);
		}
	}
	game()->width = first_line_length * SPRITE_SIZE;
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
