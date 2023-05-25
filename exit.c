/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:10:47 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/22 12:17:19 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_solong(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->num_lines)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->img);
}

void	close_window(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img->bg);
	mlx_destroy_image(game->mlx, game->img->exit);
	mlx_destroy_image(game->mlx, game->img->player);
	mlx_destroy_image(game->mlx, game->img->collectable);
	mlx_destroy_image(game->mlx, game->img->wall);
	free_solong(game);
	mlx_destroy_window(game->mlx, game->window);
	exit(1);
}

void	error_msg(char *error_message, t_data *game)
{
	ft_putstr(error_message);
	close_window(game);
}

void	error(char *error_message, t_data *game)
{
	free_solong(game);
	ft_putstr(error_message);
	exit(1);
}
