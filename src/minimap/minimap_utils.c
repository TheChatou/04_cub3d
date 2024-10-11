/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:49:55 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/11 12:35:02 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	is_in_circle(t_dpoint *pixel)
{
	double	root;
	double	center;

	center = MMAP_OFFSET_X + (MMAP_HEIGHT / 2);
	root = sqrt(pow(pixel->x - center, 2) + pow(pixel->y - center, 2));
	if (root < MMAP_HEIGHT / 2)
		return (true);
	return (false);
}

void	ft_define_pixel_color(t_game *game, int x, int y)
{
	if (!game->map->map[y][x] || game->map->map[y][x] == WALL
	|| ft_is_space(game->map->map[y][x]))
		game->mmap.color_pxl = WALL_COLOR;
	else if (game->map->map[y][x] == DOOR)
		game->mmap.color_pxl = EXIT_COLOR;
	else if (game->map->map[y][x] == TOKEN)
		game->mmap.color_pxl = TOKEN_COLOR;
	else
		game->mmap.color_pxl = EMPTY_COLOR;
}
