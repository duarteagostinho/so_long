/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:57:18 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/04 18:59:30 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	movements()
{
	static	int moves = 0;
	moves++;
	return (moves);
}

int ft_move(int key)
{
	t_collectible	*coll;
	if (key == 65307)
		exit_game(0);
	else if (key == 119
		&& !list_collision(ft_data()->player.x, ft_data()->player.y - 1, ft_data()->wall_list))
		ft_data()->player.y -= 1;
	else if (key == 115
		&& !list_collision(ft_data()->player.x, ft_data()->player.y + 1, ft_data()->wall_list))
		ft_data()->player.y += 1;
	else if (key == 97
		&& !list_collision(ft_data()->player.x - 1, ft_data()->player.y, ft_data()->wall_list))
		ft_data()->player.x -= 1;
	else if (key == 100
		&& !list_collision(ft_data()->player.x + 1, ft_data()->player.y, ft_data()->wall_list))
		ft_data()->player.x += 1;
	else
		return (0);
	if (collision(ft_data()->player.x, ft_data()->player.y, ft_data()->exit.x, ft_data()->exit.y) && ate_everything())
		exit_game(0);
	coll = list_collision(ft_data()->player.x, ft_data()->player.y, ft_data()->collectible_list);
	if (coll)
		coll->active = false;
	fputstr("player steps: ", 1);
	ft_putnbr_fd(movements(), 1);
	fputstr("\n", 1);
	return 0;
}
