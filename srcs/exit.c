/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:56:45 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/06 15:36:42 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	ft_lstclear(&game()->wall_list, free);
	ft_lstclear(&game()->collectible_list, free);
	mlx_destroy_image(game()->mlx, game()->player_img->img);
	mlx_destroy_image(game()->mlx, game()->wall_img->img);
	mlx_destroy_image(game()->mlx, game()->collectible_img->img);
	mlx_destroy_image(game()->mlx, game()->exit_img->img);
	mlx_destroy_image(game()->mlx, game()->canvas->img);
	mlx_destroy_window(game()->mlx,game()->window);
	mlx_destroy_display(game()->mlx);
	free(game()->player_img);
	free(game()->wall_img);
	free(game()->collectible_img);
	free(game()->exit_img);
	free(game()->mlx);
	free(game()->canvas);
	exit(code);
}

int	_exit_game(void)
{
	return(exit_game(0), 0);
}
