/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:57:18 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/06 15:36:42 by duandrad         ###   ########.fr       */
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
		&& !list_collision(game()->player.x, game()->player.y - 1, game()->wall_list))
		game()->player.y -= 1;
	else if (key == 115
		&& !list_collision(game()->player.x, game()->player.y + 1, game()->wall_list))
		game()->player.y += 1;
	else if (key == 97
		&& !list_collision(game()->player.x - 1, game()->player.y, game()->wall_list))
		game()->player.x -= 1;
	else if (key == 100
		&& !list_collision(game()->player.x + 1, game()->player.y, game()->wall_list))
		game()->player.x += 1;
	else
		return (0);
	if (collision(game()->player.x, game()->player.y, game()->exit.x, game()->exit.y) && ate_everything())
		exit_game(0);
	coll = list_collision(game()->player.x, game()->player.y, game()->collectible_list);
	if (coll)
		coll->active = false;
	fputstr("player steps: ", 1);
	ft_putnbr_fd(movements(), 1);
	fputstr("\n", 1);
	return 0;
}
