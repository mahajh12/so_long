/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:42:30 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/25 12:20:53 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_steps(t_data *game)
{
	game->move_count++;
	ft_putnbr(game->move_count);
	ft_putchar('\n');
}
void	check_win(t_data *game, int y, int x)
{
	if (game->map[y][x] == 'C')
	{
		game->count_collect--;
	}
	else if (game->map[y][x] == 'E' && game->count_collect == 0)
	{
		count_steps(game);
		ft_putstr("You Won!");
		close_window(game);
	}
}

void	move_player(t_data *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'C')
	{
		check_win(game, y, x);
		game->map[y][x] = 'P';
		game->map[game->p_y][game->p_x] = '0';
		game->p_x = x;
		game->p_y = y;
		get_playerposition(game);
	}
	else if (game->map[y][x] == 'E' && game->count_collect == 0)
	{
		check_win(game, y, x);
		game->map[y][x] = 'P';
		game->map[game->p_y][game->p_x] = 'E';
		game->p_x = x;
		game->p_y = y;
		get_playerposition(game);
	}
}

void	move_player_direction(t_data *game, int direction)
{
	if (direction == 0 && game->map[game->p_y][game->p_x - 1] != '1')
		move_player(game, game->p_x - 1, game->p_y);
	else if (direction == 1 && game->map[game->p_y + 1][game->p_x] != '1')
		move_player(game, game->p_x, game->p_y + 1);
	else if (direction == 2 && game->map[game->p_y][game->p_x + 1] != '1')
		move_player(game, game->p_x + 1, game->p_y);
	else if (direction == 3 && game->map[game->p_y - 1][game->p_x] != '1')
		move_player(game, game->p_x, game->p_y - 1);
}


int	key_handle(int keycode, t_data *game)
{
	if (keycode == ESC)
		error_msg("Gameover!", game);
	else if (keycode == W)
		move_player_direction(game, 3);
	else if (keycode == S)
		move_player_direction(game, 1);
	else if (keycode == D)
		move_player_direction(game, 2);
	else if (keycode == A)
		move_player_direction(game, 0);
	else
		return (0);
	count_steps(game);
	render_imgs(game);
	return (0);
}
