/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:36:09 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/06 16:55:19 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
	   dest[i] = src[i];
	   i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	ch;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	if (nb > 9)
		ft_putnbr_fd((nb / 10), fd);
	ch = (nb % 10) + '0';
	write(fd, &ch, 1);
}

void	fputstr(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
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
