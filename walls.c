/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:47:25 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/30 16:09:21 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_wall(int x, int y)
{
	t_wall *wall;

	wall = malloc(sizeof(t_wall));
	wall->x = x;
	wall->y = y;
	ft_lstadd_back(&ft_data()->wall_list, ft_lstnew(wall));
}

