/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:08:58 by mamoulin          #+#    #+#             */
/*   Updated: 2024/09/11 14:58:11 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_stock_north_texture(char *src, t_game *game)
{
	char	**tab;

	tab = ft_split(src, ' ');
	if (!tab)
		ft_error_map(game, "Malloc\n");
	game->map->path_wall_n = ft_strdup(tab[1]);
	if (!game->map->path_wall_n)
		ft_error_map(game, "Malloc north textures\n");
	if (tab[2])
		ft_quit_textures_colors(src, tab, game, "Error north texture\n");
	game->map->path_wall_n = ft_remove_nl(game->map->path_wall_n, game, tab);
	if (!game->map->path_wall_n)
	{
		ft_free_tab(tab);
		ft_error_map(game, "Malloc north textures\n");
	}
	ft_free_tab(tab);
	return (0);
}

int	ft_stock_south_texture(char *src, t_game *game)
{
	char	**tab;

	tab = ft_split(src, ' ');
	if (!tab)
		ft_error_map(game, "Malloc\n");
	game->map->path_wall_s = ft_strdup(tab[1]);
	if (!game->map->path_wall_s)
		ft_error_map(game, "Malloc south textures\n");
	if (tab[2])
		ft_quit_textures_colors(src, tab, game, "Error south texture\n");
	game->map->path_wall_s = ft_remove_nl(game->map->path_wall_s, game, tab);
	if (!game->map->path_wall_s)
	{
		ft_free_tab(tab);
		ft_error_map(game, "Malloc north textures\n");
	}
	ft_free_tab(tab);
	return (0);
}

int	ft_stock_west_texture(char *src, t_game *game)
{
	char	**tab;

	tab = ft_split(src, ' ');
	if (!tab)
		ft_error_map(game, "Malloc\n");
	game->map->path_wall_w = ft_strdup(tab[1]);
	if (!game->map->path_wall_w)
		ft_error_map(game, "Malloc west textures\n");
	if (tab[2])
		ft_quit_textures_colors(src, tab, game, "Error west texture\n");
	game->map->path_wall_w = ft_remove_nl(game->map->path_wall_w, game, tab);
	if (!game->map->path_wall_w)
	{
		ft_free_tab(tab);
		ft_error_map(game, "Malloc north textures\n");
	}
	ft_free_tab(tab);
	return (0);
}

int	ft_stock_east_texture(char *src, t_game *game)
{
	char	**tab;

	tab = ft_split(src, ' ');
	if (!tab)
		ft_error_map(game, "Malloc\n");
	game->map->path_wall_e = ft_strdup(tab[1]);
	if (!game->map->path_wall_e)
		ft_error_map(game, "Malloc east textures\n");
	if (tab[2])
		ft_quit_textures_colors(src, tab, game, "Error east texture\n");
	game->map->path_wall_e = ft_remove_nl(game->map->path_wall_e, game, tab);
	if (!game->map->path_wall_e)
	{
		ft_free_tab(tab);
		ft_error_map(game, "Malloc north textures\n");
	}
	ft_free_tab(tab);
	return (0);
}
