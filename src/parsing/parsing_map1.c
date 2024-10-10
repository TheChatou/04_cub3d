/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:29:18 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/10 14:57:52 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	get_map_size(t_game *game, char *map_file)
{
	char	*line;

	game->map_fd = open(map_file, O_RDONLY);
	if (game->map_fd == -1)
		return (ft_error_map1("Error: can't open the map!", game), 1);
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

int	ft_stock_map_tab(char *map_file, t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	get_map_size(game, map_file);
	game->map_fd = open(map_file, O_RDONLY);
	if (game->map_fd == -1)
		return (ft_error_map(game, "Error: can't open the map!"), 1);
	game->map->map = (char **)ft_calloc(game->map->map_h, sizeof(char *));
	if (!game->map->map)
		return (ft_error_map(game, "Malloc"), 1);
	line = get_next_line(game->map_fd);
	while (line != NULL)
	{
		if (ft_get_map_info(line, game))
		{
			game->map->map[i] = ft_strdup(line);
			if (!game->map->map[i])
				return (ft_error_map(game, "Malloc"), 1);
			i++;
		}
		free(line);
		line = get_next_line(game->map_fd);
	}
	return (0);
}
