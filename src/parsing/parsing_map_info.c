/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:17:12 by mamoulin          #+#    #+#             */
/*   Updated: 2024/09/03 15:13:07 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_quit_textures_colors(char *src, char **tab, t_game *game, char *mss)
{
	free(src);
	ft_free_tab(tab);
	ft_error_map(game, mss);
}

int	ft_get_map_info(char *src, t_game *game)
{	
	if (!ft_strncmp(src, "NO ", 3))
		return (ft_stock_north_texture(src, game));
	if (!ft_strncmp(src, "SO ", 3))
		return (ft_stock_south_texture(src, game));
	if (!ft_strncmp(src, "WE ", 3))
		return (ft_stock_west_texture(src, game));
	if (!ft_strncmp(src, "EA ", 3))
		return (ft_stock_east_texture(src, game));
	if (!ft_strncmp(src, "F ", 2))
		return (ft_stock_floor_color(src, game));
	if (!ft_strncmp(src, "C ", 2))
		return (ft_stock_ceiling_color(src, game));
	if (!ft_strncmp(src, "\n", 2))
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
	if (!ft_strncmp(src, "\n", 2))
		return (0);
	if (!ft_strncmp(src, "F ", 2))
		return (0);
	if (!ft_strncmp(src, "C ", 2))
		return (0);
	return (1);
}
