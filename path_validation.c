/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:02:54 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/23 12:08:58 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_visited(t_data *game, int num_lines, int num_cols)
{
	int	y;
	int	x;

	game->visited = (int **)malloc(num_lines * sizeof(int *));
	y = 0;
	while (y < num_lines)
	{
		game->visited[y] = (int *)malloc(num_cols * sizeof(int));
		x = 0;
		while (x < num_cols)
		{
			game->visited[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	free_visited(t_data *game, int num_lines)
{
	int	y;

	y = 0;
	while (y < num_lines)
	{
		free(game->visited[y]);
		y++;
	}
}

void	dfs(t_data *game, int y, int x)
{
	if (y < 0 || y >= game->num_lines || x < 0 || x >= game->num_cols
		|| game->visited[y][x] || game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		game->c_reachable++;
	if (game->map[y][x] == 'E')
		game->e_reachable = 1;
	game->visited[y][x] = 1;
	dfs(game, y + 1, x);
	dfs(game, y - 1, x);
	dfs(game, y, x + 1);
	dfs(game, y, x - 1);
}

int	has_validpath(t_data *game)
{
	int	total_c_count;
	int	c_reachable;
	int	e_reachable;

	total_c_count = game->count_collect;
	c_reachable = 0;
	e_reachable = 0;
	initialize_visited(game, game->num_lines, game->num_cols);
	dfs(game, game->p_y, game->p_x);
	c_reachable = game->c_reachable;
	e_reachable = game->e_reachable;
	if (c_reachable != total_c_count || !e_reachable)
	{
		free_visited(game, game->num_lines);
		error("Error: Invalid Path.\n", game);
	}
	free_visited(game, game->num_lines);
	return (1);
}
