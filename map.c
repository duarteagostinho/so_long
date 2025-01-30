/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:19:47 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/29 17:19:47 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map()
{
	int fd;
	
	fd = open("maps/map1.ber", O_RDONLY);
	ft_data()->width = ft_line_length(fd) * SPRITE_SIZE;
	ft_data()->height = ft_count_lines(open("maps/map1.ber", O_RDONLY)) * SPRITE_SIZE;
}
