/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:19:47 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/30 19:20:41 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

ssize_t	ft_strlen_t(char *str, char term)
{
	size_t	size;
	
	if (!str)
		return (-1);
	size = 0;
	while (str[size] && str[size] != term)
		size++;
	return (size);
}

ssize_t	ft_strlen(char *str)
{
	return (ft_strlen_t(str, 0));
}

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
		return (NULL);
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

void	array_print(char **array)
{
	size_t i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		fputstr(array[i], 1);
	fputstr("\n", 1);
}

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
	}
	return (array);
}

bool	process_line(char *line, size_t line_pos, size_t first_line_len)
{
	size_t	i;

	if ((size_t)ft_strlen_t(line, '\n') != first_line_len)
	{
		printf("%ld %ld\n", (size_t)ft_strlen(line), first_line_len);
		return (false);
	}
	i = -1;
	while (line[++i])
	{
		if (line[i] == '1')
			new_wall((int)(i * SPRITE_SIZE), (int)(line_pos * SPRITE_SIZE));
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
	ft_data()->width = first_line_length * SPRITE_SIZE;
	ft_data()->height = i * SPRITE_SIZE;
	update_window_size(ft_data()->width, ft_data()->height);
	if (!ft_data()->window)
		return (false);
	return (true);
}
bool	load_map(char *path)
{
	char **lines;

	lines = get_map_lines(path);
	if (!lines)
	{
		fputstr("error loading map lines\n", 2);
		return (false);
	}
	array_print(lines);
	if (!process_lines(lines))
	{
		fputstr("error processing map lines\n", 2);
		return (false);
	}
	return (true);
}

