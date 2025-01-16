/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:29:46 by duandrad          #+#    #+#             */
/*   Updated: 2025/01/15 20:43:58 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(int key)
{
	if (key == 27)
	{
		mlx_destroy_window(ft_data()->mlx, ft_data()->window);
		free(ft_data()->mlx);
	}
	return(0);
}