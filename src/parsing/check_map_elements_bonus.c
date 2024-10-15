/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:58:03 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/15 11:51:51 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_check_extension(char *name)
{
	int		i;
	char	*extension;

	i = ft_strlen(name);
	while (name[i] != '.')
		i--;
	extension = ft_substr(name, i, ft_strlen(name));
	if (ft_strcmp(extension, ".cub"))
	{
		free(extension);
		return (1);
	}
	free(extension);
	return (0);
}

int	ft_check_lines(t_game *game)
{
	size_t	i;
	size_t	j;
	int		count;
	int		token;

	i = -1;
	token = 0;
	count = 0;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j] != '\0')
		{
			if (ft_check_symb(game->map->map[i][j]))
				return (1);
			if (!ft_player_symb(game->map->map[i][j])
				|| game->map->map[i][j] == 'D')
				count++;
			if (game->map->map[i][j] == 'T')
				token++;
		}
	}
	if (count != 2 || token < 1)
		return (1);
	return (0);
}

int	ft_check_surrounding(t_game *game, size_t x, size_t y)
{
	if (ft_check_empty_spot(game->map->map[x - 1][y]))
		return (1);
	if (ft_check_empty_spot(game->map->map[x + 1][y]))
		return (1);
	if (ft_check_empty_spot(game->map->map[x][y - 1]))
		return (1);
	if (ft_check_empty_spot(game->map->map[x][y + 1]))
		return (1);
	return (0);
}

int	ft_check_walls(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j] != '\0')
		{
			if (!ft_check_inner_elements(game->map->map[i][j]))
				if (game->map->map[i][j] != WALL)
					if (ft_check_surrounding(game, i, j))
						return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(char *name, t_game *game)
{
	if (ft_check_extension(name))
		return (ft_error_map(game, "Wrong extension"), 1);
	if (ft_check_lines(game))
		return (ft_error_map(game, "Error symbols"), 1);
	if (ft_check_walls(game))
		return (ft_error_map(game, "Error walls"), 1);
	return (0);
}
