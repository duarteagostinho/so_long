/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:43:43 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 00:38:48 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game *game()
{
	static t_game g;

	return (&g);
}

bool	check_args(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		fputstr("Error\nInvalid number of args\n", 1);
		return (false);
	}
	if (ft_strlen(av[1]) >= 3 &&
		!(av[1][ft_strlen(av[1]) - 3] == 'b' && av[1][ft_strlen(av[1]) - 2] == 'e' &&
		av[1][ft_strlen(av[1]) - 1] == 'r'))
	{
		fputstr("Error\nInvalid .ber\n", 1);
		return(false);
	}
	return (true);
}

int ft_loop()
{
	clear_canvas();
	draw_walls();
	draw_player();
	draw_collectibles();
	draw_exit();
	mlx_put_image_to_window(game()->mlx, game()->window, game()->canvas->img, 0, 0);
	return 0;
}

void	loop()
{
	mlx_hook(game()->window, 17, 1L<<17, _exit_game, NULL);
	mlx_hook(game()->window, 2, 1L<<0, ft_move, NULL);
	mlx_loop_hook(game()->mlx, ft_loop, NULL);
	mlx_loop(game()->mlx);
}

int main(int ac, char **av)
{
	if (!check_args(ac, av) || !load_map(av[1]) || !init_mlx() || !load_images())
		return (1);
	loop();
	return (0);
}