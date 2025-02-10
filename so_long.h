/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duandrad <duandrad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:32:55 by duandrad          #+#    #+#             */
/*   Updated: 2025/02/10 00:58:42 by duandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef SPRITE_SIZE
#  define SPRITE_SIZE 40
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_wall
{
	int	x;
	int	y;
}	t_wall;

typedef struct s_img
{
	void	*img;
	char	*adress;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_colectible
{
	int		x;
	int		y;
	bool	active;
}	t_collectible;

typedef struct s_game
{
	int				collectibles;
	t_img			*player_img;
	t_img			*canvas;
	void			*mlx;
	void			*display;
	void			*window;
	t_player		player;
	int				width;
	int				height;
	char			**map;
	t_img			*wall_img;
	t_list			*wall_list;
	t_list			*collectible_list;
	t_img			*collectible_img;
	t_point			exit;
	t_img			*exit_img;
	int				player_count;
	int				coll_count;
	int				exit_count;
}	t_game;

/* UTILS */
t_game			*game(void);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
char			*get_next_line(int fd);
void			fputstr(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			free_array(char **array);
ssize_t			ft_strlen(char *str);
ssize_t			ft_strlen_t(char *str, char term);
size_t			array_length(char **av);
char			**array_join(char **array, char *newstr);
bool			check_borders(char **map);
bool			check_counters(char **map);
bool			ate_everything(void);
bool			can_finish(char **map);
void			set_player_pos(int i, int line_pos);
void			set_exit_point(int i, int line_pos);

/* SRCS */
t_img			*ft_load_image(char *path);
int				ft_move(int key);
int				ft_loop(void);
void			clear_canvas(void);
void			draw_img(t_img *img, int x, int y);
void			draw_walls(void);
void			draw_player(void);
void			draw_collectibles(void);
void			new_wall(int x, int y);
void			new_collectible(int x, int y);
bool			load_map(char *path);
t_img			*ft_new_image(int width, int height);
void			update_window_size(int width, int height);
void			draw_exit(void);
void			exit_game(int code);
int				_exit_game(void);
void			*list_collision(int x, int y, t_list *list);
bool			collision(int x, int y, int x1, int y1);
bool			load_images(void);
bool			init_mlx(void);

#endif