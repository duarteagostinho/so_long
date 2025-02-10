/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:57:18 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/09 23:16:23 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	movements(void)
{
	static int	moves = 0;

	moves++;
	return (moves);
}

static bool	move_player(int x, int y)
{
	if (!list_collision(x, y, game()->wall_list))
	{
		game()->player.x = x;
		game()->player.y = y;
		return (true);
	}
	return (false);
}

static void	check_exit_and_collectibles(void)
{
	t_collectible	*coll;

	if (collision(game()->player.x, game()->player.y, game()->exit.x,
			game()->exit.y) && ate_everything())
	{
		fputstr("CONGRATULATIONS!MAP PASSED!\n", 1);
		exit_game(0);
	}
	coll = list_collision(game()->player.x, game()->player.y,
			game()->collectible_list);
	if (coll)
		coll->active = false;
}

int	ft_move(int key)
{
	bool	moved;

	if (key == 65307)
		exit_game(0);
	else if (key == 119 || key == 65362)
		moved = move_player(game()->player.x, game()->player.y - 1);
	else if (key == 115 || key == 65364)
		moved = move_player(game()->player.x, game()->player.y + 1);
	else if (key == 97 || key == 65361)
		moved = move_player(game()->player.x - 1, game()->player.y);
	else if (key == 100 || key == 65363)
		moved = move_player(game()->player.x + 1, game()->player.y);
	else
		return (0);
	if (moved)
	{
		check_exit_and_collectibles();
		fputstr("Moves: ", 1);
		ft_putnbr_fd(movements(), 1);
		fputstr("\n", 1);
	}
	return (0);
}
