/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:57:18 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/04 18:51:59 by duandrad         ###   ########.fr       */
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
	if (collision(ft_data()->player.x, ft_data()->player.y, ft_data()->exit.x, ft_data()->exit.y) && !ft_data()->collectibles)
		exit_game(0);
	coll = list_collision(ft_data()->player.x, ft_data()->player.y, ft_data()->collectible_list);
	if (coll)
	{
		coll->active = false;
		ft_data()->collectibles--;
	}
	fputstr("player steps: ", 1);
	ft_putnbr_fd(movements(), 1);
	fputstr("\n", 1);
	return 0;
}

void	free_array(char **array)
{
	int i;

	i = -1;
	while(array[++i])
		free(array[i]);
	free(array);
}

void	exit_game(int code)
{
	ft_lstclear(&ft_data()->wall_list, free);
	ft_lstclear(&ft_data()->collectible_list, free);
	mlx_destroy_image(ft_data()->mlx, ft_data()->player_img->img);
	mlx_destroy_image(ft_data()->mlx, ft_data()->wall_img->img);
	mlx_destroy_image(ft_data()->mlx, ft_data()->collectible_img->img);
	mlx_destroy_image(ft_data()->mlx, ft_data()->exit_img->img);
	mlx_destroy_image(ft_data()->mlx, ft_data()->canvas->img);
	mlx_destroy_window(ft_data()->mlx,ft_data()->window);
	mlx_destroy_display(ft_data()->mlx);
	free(ft_data()->player_img);
	free(ft_data()->wall_img);
	free(ft_data()->collectible_img);
	free(ft_data()->exit_img);
	free(ft_data()->mlx);
	free(ft_data()->canvas);
	exit(code);
}