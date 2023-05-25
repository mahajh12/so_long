/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:20:33 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/18 15:10:49 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_invalid_objects(char *object, t_data *game)
{
	if (object != '1' && object != 'P'
		&& object != '0' && object != 'E' && object != 'C')
		error("Error: Invalid character", game);
}

void	check_objects(char *object, int *p, int *e, int *c)
{
	if (object == 'P')
		(*p)++;
	else if (object == 'E')
		(*e)++;
	else if (object == 'C')
		(*c)++;
}

void	objects_count(t_data *game, int *p, int *e, int *c)
{
	if ((*p) != 1)
		error("Error: There should only be one player position", game);
	else if ((*e) != 1)
		error("Error: There should only be one exit", game);
	else if ((*c) == 0)
		error("Error: There is no collectable", game);
}

void	parse_map(t_data *game)
{
	int	x;
	int	y;
	int	p;
	int	e;
	int	c;

	y = 0;
	p = 0;
	e = 0;
	c = 0;
	while (y < game->num_lines)
	{
		x = 0;
		while (x < game->num_cols)
		{
			check_invalid_objects(game->map[y][x], game);
			check_objects(game->map[y][x], &p, &e, &c);
			x++;
		}
		y++;
	}
	objects_count(game, &p, &e, &c);
}

void	collect_count(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->num_lines)
	{
		x = 0;
		while (x < game->num_cols)
		{
			if (game->map[y][x] == 'C')
				game->count_collect++;
			x++;
		}
		y++;
	}
}
