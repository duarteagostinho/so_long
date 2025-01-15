#include "header.h"

int ft_move(int key, t_game *game)
{
	if (key == 119)
	{
		game->player.y -= 10;
		printf("andei p cima\n");
	}
	else if (key == 115)
	{
		game->player.y += 10;
		printf("andei p baixo\n");
	}
	else if (key == 97)
	{
		game->player.x -= 10;
		printf("andei p esquerda\n");
	}
	else if (key == 100)
	{
		game->player.x += 10;
		printf("andei p direita\n");
	}
	return 0;
}