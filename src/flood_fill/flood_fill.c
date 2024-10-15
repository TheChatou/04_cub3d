/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:37:53 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/15 12:14:10 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	**ft_copy_map(char **map, t_game *game)
{
	size_t	i;
	char	**copy;
	size_t	tab_size;

	tab_size = game->map->map_h;
	i = 0;
	copy = ft_calloc((tab_size + 1), sizeof(char *));
	if (!copy)
		ft_free_all(game);
	while (i < tab_size && map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

char	**ft_flood_fill(int x, int y, char **copy)
{
	if (check_if_not_walls(copy[y][x]))
		copy[y][x] = 'F';
	if (check_if_not_walls(copy[y][x + 1]))
		ft_flood_fill(x + 1, y, copy);
	if (check_if_not_walls(copy[y][x - 1]))
		ft_flood_fill(x - 1, y, copy);
	if (check_if_not_walls(copy[y + 1][x]))
		ft_flood_fill(x, y + 1, copy);
	if (check_if_not_walls(copy[y - 1][x]))
		ft_flood_fill(x, y - 1, copy);
	return (copy);
}

int	ft_find_exit(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y] && map[y][x] != '\0')
		{
			if ((map[y][x]) == DOOR)
			{
				game->map->exit.x = x;
				game->map->exit.y = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	control_fill_final(char **map, t_game *game)
{
	int	x;
	int	y;
	int	t;

	t = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == TOKEN)
				t++;
			x++;
		}
		y++;
	}
	ft_find_exit(map, game);
	x = game->map->exit.x;
	y = game->map->exit.y;
	if (t == 0 && (map[y][x - 1] == 'F' || map[y][x + 1] == 'F'
			|| map[y - 1][x] == 'F' || map[y + 1][x] == 'F'))
		return (0);
	return (ft_printf("Error: there is no path to victory!\n"), 1);
}

int	valid_path(t_game *game)
{
	char	**copy;
	int		x;
	int		y;

	game->player.pos = find_player_float(game->map);
	copy = ft_copy_map(game->map->map, game);
	if (!copy)
		ft_free_all(game);
	x = (int)game->player.pos.x;
	y = (int)game->player.pos.y;
	copy = ft_flood_fill(x, y, copy);
	if (control_fill_final(copy, game))
	{
		ft_free_tab(copy);
		return (1);
	}
	ft_free_tab(copy);
	return (0);
}
