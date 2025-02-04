/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:57:18 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/04 14:23:02 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	movements()
{
	static	int moves = 0;
	moves++;
	return (moves);
}

int ft_move(int key)
{
	int i = movements();
	fputstr("player steps: ", 1);
	if (key == 119 )
	{
		ft_data()->player.y -= 40;
		ft_putnbr_fd(i, 1);
	}
	else if (key == 115)
	{
		ft_data()->player.y += 40;
		ft_putnbr_fd(i, 1);
	}
	else if (key == 97)
	{
		ft_data()->player.x -= 40;
		ft_putnbr_fd(i, 1);
	}
	else if (key == 100)
	{
		ft_data()->player.x += 40;
		ft_putnbr_fd(i, 1);
	}
	else if (key == 65307)
		exit_game();
	fputstr("\n", 1);
	return 0;
}

int	exit_game()
{
	mlx_destroy_display(ft_data()->mlx);
	mlx_destroy_image(ft_data()->mlx, ft_data()->player_img);
	mlx_destroy_image(ft_data()->mlx, ft_data()->wall_img);
	mlx_destroy_image(ft_data()->mlx, ft_data()->collectible_img);
	mlx_destroy_image(ft_data()->mlx, ft_data()->exit_img);
	mlx_destroy_window(ft_data()->mlx,ft_data()->window);
	exit(1);
	return (0);
}