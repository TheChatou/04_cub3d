/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:17:12 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/11 18:25:42 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_set_walls_info(char *src, t_game *game)
{	
	if (!ft_strncmp(src, "NO ", 3))
	{
		ft_change_walls_text(game->map->path_wall_n, game);
		return (ft_stock_north_texture(src, game));
	}
	else if (!ft_strncmp(src, "SO ", 3))
	{
		ft_change_walls_text(game->map->path_wall_s, game);
		return (ft_stock_south_texture(src, game));
	}
	else if (!ft_strncmp(src, "WE ", 3))
	{
		ft_change_walls_text(game->map->path_wall_w, game);
		return (ft_stock_west_texture(src, game));
	}
	else if (!ft_strncmp(src, "EA ", 3))
	{
		ft_change_walls_text(game->map->path_wall_e, game);
		return (ft_stock_east_texture(src, game));
	}
	return (1);
}

int	ft_set_colors(char *src, t_game *game)
{
	if (!ft_strncmp(src, "F ", 2))
	{
		ft_change_colors_text(game->map->floor, game);
		return (ft_stock_floor_color(src, game));
	}
	else if (!ft_strncmp(src, "C ", 2))
	{
		ft_change_colors_text(game->map->ceiling, game);
		return (ft_stock_ceiling_color(src, game));
	}
	else if (!ft_strncmp(src, "\n", 2) && game->cub_info != 6)
		return (0);
	return (1);
}

int	ft_pass_map_info(char *src)
{	
	if (!ft_strncmp(src, "NO ", 3))
		return (0);
	if (!ft_strncmp(src, "SO ", 3))
		return (0);
	if (!ft_strncmp(src, "WE ", 3))
		return (0);
	if (!ft_strncmp(src, "EA ", 3))
		return (0);
	if (!ft_strncmp(src, "F ", 2))
		return (0);
	if (!ft_strncmp(src, "C ", 2))
		return (0);
	if (!ft_strncmp(src, "\n", 2))
		return (0);
	return (1);
}
