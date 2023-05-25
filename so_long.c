/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:27:41 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/25 12:21:17 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_playerposition(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->num_lines)
	{
		x = 0;
		while (x < game->num_cols)
		{
			if (game->map[y][x] == 'P')
			{
				game->p_y = y;
				game->p_x = x;
			}
			x++;
		}
		y++;
	}
}

void	check_walls(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->num_lines)
	{
		if (game->map[y][0] != '1' || game->map[y][game->num_cols - 1] != '1')
			error_msg("Error: left or right column is not a wall", game);
		y++;
	}
	while (x < game->num_cols)
	{
		if (game->map[0][x] != '1' || game->map[game->num_lines - 1][x] != '1')
			error_msg("Error: up or down row is not a wall", game);
		x++;
	}
}

void	init_data(t_data *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->map = NULL;
	game->img = malloc(sizeof(t_img));
	game->pixel_size = 64;
	game->width = game->num_cols * game->pixel_size;
	game->length = game->num_lines * game->pixel_size;
	game->count_collect = 0;
	game->move_count = 0;
	game->num_lines = 0;
	game->num_cols = 0;
}

void	init_func(t_data *game)
{
	length_cols(game);
	check_walls(game);
	parse_map(game);
	get_playerposition(game);
	collect_count(game);
}

int	main(int ac, char *av[])
{
	t_data	game;

	if (ac == 2)
	{
		invalid_map(av[1], &game);
		init_data(&game);
		game.mlx = mlx_init();
		num_of_lines(av[1], &game);
		read_map(av[1], &game);
		init_func(&game);
		has_validpath(&game);
		game.width = game.num_cols * game.pixel_size;
		game.length = game.num_lines * game.pixel_size;
		game.window = mlx_new_window(game.mlx,
				game.width, game.length, "SO_LONG");
		put_img(&game);
		render_imgs(&game);
		mlx_hook(game.window, 17, 1L << 17, close_window, &game);
		mlx_hook(game.window, 2, 0, key_handle, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_putstr("Usage: ./so_long [map]\n");
}
