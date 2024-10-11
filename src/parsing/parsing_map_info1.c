/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_info1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:03:45 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/11 17:09:00 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_quit_textures_colors(char *src, char **tab, t_game *game, char *mss)
{
	free(src);
	ft_free_tab(tab);
	ft_error_map(game, mss);
}

void	ft_change_walls_text(char *src, t_game *game)
{
	game->cub_info++;
	if (src)
	{
		game->cub_info--;
		free(src);
	}
}

void	ft_change_colors_text(t_color *color, t_game *game)
{
	game->cub_info++;
	if (color)
	{
		game->cub_info--;
		free(color);
	}
}
