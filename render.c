/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:11:45 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/23 12:24:48 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data *game)
{
	game->img->bg = mlx_xpm_file_to_image(game->mlx, "./textures/bg.xpm",
			&(game->width), &(game->length));
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&(game->width), &(game->length));
	game->img->player = mlx_xpm_file_to_image(game->mlx,
			"./textures/player.xpm", &(game->width), &(game->length));
	game->img->collectable = mlx_xpm_file_to_image(game->mlx,
			"./textures/collect.xpm", &(game->width), &(game->length));
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&(game->width), &(game->length));
}

void	put_win(t_data *game, char type, int x, int y)
{
	int	x_size;
	int	y_size;

	x_size = x * game->pixel_size;
	y_size = y * game->pixel_size;
	mlx_put_image_to_window(game->mlx, game->window,
		game->img->bg, x_size, y_size);
	if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->exit, x_size, y_size);
	else if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->player, x_size, y_size);
	else if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->collectable, x_size, y_size);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->wall, x_size, y_size);
}

void	render_imgs(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->num_lines)
	{
		x = 0;
		while (x < game->num_cols)
		{
			put_win(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
