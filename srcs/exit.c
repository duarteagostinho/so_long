/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:56:45 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/05 16:56:45 by duandrad         ###   ########.fr       */
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

int	_exit_game(void)
{
	return(exit_game(0), 0);
}
