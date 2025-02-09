/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:06:26 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/09 01:53:14 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check(char *buff)
{
	int		ret;
	char	*ini;

	ret = 0;
	ini = buff;
	while (*buff)
	{
		if (ret == 1)
			*ini++ = *buff;
		else if (*buff == '\n')
			ret = 1;
		*buff++ = '\0';
	}
	return (ret);
}

size_t	len_newline(char *buff)
{
	size_t	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i] != '\n' && buff[i])
		i++;
	return (i + (buff[i] == '\n'));
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = len_newline(s1);
	s2_len = len_newline(s2);
	new = malloc(s1_len + s2_len + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
		new[j++] = s1[i++];
	free (s1);
	i = 0;
	while (i < s2_len)
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE];
	char		*line;
	long long	bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes = 1;
	while (1)
	{
		if (buffer[fd][0] == '\0')
			bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (bytes)
			line = ft_strjoin_gnl(line, buffer[fd]);
		if (check(buffer[fd]) || bytes == 0)
			break ;
	}
	return (line);
}

