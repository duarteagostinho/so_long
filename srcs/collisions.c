/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:02:30 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/04 15:58:05 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*list_collision(int x, int y, t_list *list)
{
	t_point *point;

	while (list)
	{
		point = list->content;
		if (collision(x, y, point->x, point->y))
			return (point);
		list = list->next;
	}
	return (NULL);
}

bool	collision(int x, int y, int x1, int y1)
{
	return (x == x1 && y == y1);
}