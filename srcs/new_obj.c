/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:17:38 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 00:15:34 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	new_collectible(int x, int y)
{
	t_collectible *collectible;

	collectible = malloc(sizeof(t_collectible));
	if (!collectible)
		return ;
	collectible->x = x;
	collectible->y = y;
	collectible->active= true;
	ft_lstadd_back(&game()->collectible_list, ft_lstnew(collectible));
}

void	new_wall(int x, int y)
{
	t_wall *wall;

	wall = malloc(sizeof(t_wall));
	if (!wall)
		return ;
	wall->x = x;
	wall->y = y;
	ft_lstadd_back(&game()->wall_list, ft_lstnew(wall));
}

bool	ate_everything(void)
{
	t_list	*coll;

	coll = game()->collectible_list;
	while (coll)
	{
		if (((t_collectible *)(coll->content))->active)
			return (false);
		coll = coll->next;
	}
	return (true);
}

