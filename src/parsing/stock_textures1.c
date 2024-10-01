/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_textures1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:12:41 by mamoulin          #+#    #+#             */
/*   Updated: 2024/09/11 14:58:19 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*ft_remove_nl(char *src, t_game *game, char **tab)
{
	char	*src_tmp;

	src_tmp = ft_substr(src, 0, ft_strlen(src) - 1);
	if (!src_tmp)
	{
		free(src);
		ft_free_tab(tab);
		ft_error_map(game, "Error: map info remove nl\n");
	}
	free(src);
	return (src_tmp);
}

void	ft_control_colors(t_color *color, char **tab, t_game *game, char *src)
{
	color->r = ft_atoi(tab[0]);
	color->g = ft_atoi(tab[1]);
	color->b = ft_atoi(tab[2]);
	if (color->r > 255 || color->g > 255 || color->b > 255)
	{
		free(src);
		ft_free_tab(tab);
		ft_error_map(game, "Error: floor color to high\n");
	}
	if (color->r < 0 || color->g < 0 || color->b < 0)
	{
		free(src);
		ft_free_tab(tab);
		ft_error_map(game, "Error: floor color to high\n");
	}
}

int	ft_stock_floor_color(char *src, t_game *game)
{
	char	**tab;

	game->map->floor = malloc(sizeof(t_color));
	tab = ft_split(src, ',');
	if (!tab || !game->map->floor)
		ft_error_map(game, "Malloc\n");
	if (tab[3])
		ft_quit_textures_colors(src, tab, game, "Error: floor color\n");
	ft_control_colors(game->map->floor, tab, game, src);
	ft_free_tab(tab);
	return (0);
}

int	ft_stock_ceiling_color(char *src, t_game *game)
{
	char	**tab;

	game->map->ceiling = malloc(sizeof(t_color));
	tab = ft_split(src, ',');
	if (!tab || !game->map->floor)
		ft_error_map(game, "Malloc\n");
	if (tab[3])
		ft_quit_textures_colors(src, tab, game, "Error: ceiling color\n");
	ft_control_colors(game->map->ceiling, tab, game, src);
	ft_free_tab(tab);
	return (0);
}
