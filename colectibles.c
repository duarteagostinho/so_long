/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colectibles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:17:38 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/03 18:32:12 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_collectible(int x, int y)
{
	t_collectible *collectible;

	collectible = malloc(sizeof(t_collectible));
	collectible->x = x;
	collectible->y = y;
	ft_lstadd_back(&ft_data()->collectible_list, ft_lstnew(collectible));
}