#include "so_long.h"

int	movements()
{
	static	int moves = 0;
	moves++;
	return (moves);
}

int ft_move(int key)
{
	int i = movements();
	if (key == 119)
	{
		ft_data()->player.y -= 10;
		write(1, "player steps: ", 15);
		printf(" %d\n", i);
	}
	else if (key == 115)
	{
		ft_data()->player.y += 10;
		write(1, "player steps: ", 15);
		printf(" %d\n", i);
	}
	else if (key == 97)
	{
		ft_data()->player.x -= 10;
		write(1, "player steps: ", 15);
		printf(" %d\n", i);
	}
	else if (key == 100)
	{
		ft_data()->player.x += 10;
		write(1, "player steps: ", 15);
		printf(" %d\n", i);
	}
	return 0;
}