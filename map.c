/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:50 by malhamel          #+#    #+#             */
/*   Updated: 2023/05/18 15:28:06 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(char *map_name, t_data *game)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(map_name, '.');
	if (!(extension && ft_strcmp(extension + 1, "ber") == 0))
	{
		ft_putstr("Error: Invalid file extension is not .ber.\n");
		exit(1);
	}
	fd = open(map_name, O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr("Failed to open, this is a directory\n");
		exit(1);
	}
	close (fd);
}

int	num_of_lines(char *map_name, t_data *game)
{
	char	*line;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Failed to open \n");
		exit (0);
	}
	game->num_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->num_lines++;
		free(line);
	}
	if (game->num_lines == 0)
		error("file is empty", game);
	close(fd);
	return (game->num_lines);
}

void	read_map(char *map_name, t_data *game)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error("Error: Failed to open file", game);
	game->map = malloc(game->num_lines * sizeof(char *));
	if (game->map == NULL)
	{
		close(fd);
		return ;
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line != '\0')
			game->map[i++] = line;
		else
			free(line);
	}
	close(fd);
}

size_t	get_length(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
	{
		len++;
	}
	return (len);
}

int	length_cols(t_data *game)
{
	int	rows;
	int	cols;
	int	i;

	rows = game->num_lines;
	cols = get_length(game->map[0]);
	i = 0;
	while (i < rows)
	{
		if (get_length(game->map[i]) != cols)
		{
			error("Error: Map is not rectangular.", game);
		}
		i++;
	}
	game->num_cols = cols;
	return (cols);
}
