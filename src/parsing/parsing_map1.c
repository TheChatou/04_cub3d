/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:29:18 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/15 12:16:13 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_check_empty_line2(char *src)
{
	int	i;

	i = 0;
	if (!src || !src[i])
		return (0);
	while (src[i])
	{
		if (ft_is_space(src[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	get_map_size(t_game *game, char *map_file)
{
	char	*line;

	game->map_fd = open(map_file, O_RDONLY);
	if (game->map_fd == -1)
		return (ft_error_map(game, "Error: can't open the map!"), 1);
	line = get_next_line(game->map_fd);
	while (line != NULL)
	{
		if (ft_pass_map_info(line))
		{
			game->map->map_h++;
			if (ft_strlen(line) > game->map->map_w)
				game->map->map_w = ft_strlen(line);
		}
		free(line);
		line = get_next_line(game->map_fd);
	}
	game->map->map_h++;
	game->map->map_w--;
	close(game->map_fd);
	return (0);
}

int	ft_check_empty_line(char *src, t_game *game)
{
	int	i;

	i = 0;
	if (game->nl == 1)
		return (0);
	if (game->nl == 0 && game->cub_info == 6)
		game->nl++;
	while (src[i])
	{
		if (ft_is_space(src[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_stock_map(char *line, t_game *game)
{
	int		i;

	i = 0;
	while (line != NULL)
	{
		if (ft_set_walls_info(line, game) && ft_set_colors(line, game))
		{
			if (game->cub_info != 6 || ft_check_empty_line(line, game))
				return (ft_error_map1(game, "Error: config\n", line), 1);
			if (ft_check_empty_line2(line))
			{
				game->map->map[i] = ft_strdup(line);
				if (!game->map->map[i])
					return (ft_error_map(game, "Error map\n"), 1);
				i++;
			}
			if (!ft_check_empty_line2(line) && game->map->map[0])
				return (ft_error_map1(game, "Error map\n", line), 1);
		}
		free(line);
		line = get_next_line(game->map_fd);
	}
	game->map->map[i] = NULL;
	return (0);
}

int	ft_stock_map_tab(char *map_file, t_game *game)
{
	char	*line;

	get_map_size(game, map_file);
	game->map_fd = open(map_file, O_RDONLY);
	if (game->map_fd == -1)
		return (ft_error_map(game, "Error: can't open the map!"), 1);
	game->map->map = (char **)ft_calloc(game->map->map_h + 1, sizeof(char *));
	if (!game->map->map)
		return (ft_error_map(game, "Malloc"), 1);
	line = get_next_line(game->map_fd);
	if (ft_stock_map(line, game))
		return (1);
	return (0);
}
