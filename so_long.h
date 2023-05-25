/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:21:24 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/23 12:06:50 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

typedef struct image
{
	void	*bg;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*wall;
}	t_img;

typedef struct data
{
	void	*mlx;
	void	*window;
	char	**map;
	t_img	*img;
	int		pixel_size;
	int		width;
	int		num_lines;
	int		num_cols;
	int		p_y;
	int		p_x;
	int		count_collect;
	int		move_count;
	int		c_reachable;
	int		e_reachable;
	int		**visited;
	int		length;
}	t_data;

int		num_of_lines(char *map_name, t_data *game);
int		length_cols(t_data *game);
int		key_handle(int keycode, t_data *game);
int		mouse_handle(int button, int x, int y, t_data *game);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
void	read_map(char *map_name, t_data *game);
void	check_walls(t_data *game);
void	parse_map(t_data *game);
void	error_msg(char *error_message, t_data *game);
void	get_playerposition(t_data *game);
void	close_window(t_data *game);
void	put_img(t_data *game);
void	put_win(t_data *game, char type, int x, int y);
void	render_imgs(t_data *game);
void	move_player_direction(t_data *game, int direction);
void	move_player(t_data *game, int x, int y);
void	ft_putstr(char *s);
void	invalid_map(char *map_name, t_data *game);
void	collect_count(t_data *game);
void	check_win(t_data *game, int y, int x);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	error(char *error_message, t_data *game);
void	free_solong(t_data *game);
void	init_func(t_data *game);
int		has_validpath(t_data *game);
void	initialize_visited(t_data *game, int num_lines, int num_cols);
void	free_visited(t_data *game, int num_lines);
void	dfs(t_data *game, int y, int x);
#endif