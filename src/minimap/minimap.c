/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:54:17 by mamoulin          #+#    #+#             */
/*   Updated: 2024/09/11 14:50:46 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_draw_square(int x, int y, int color, t_game *game)
{
	int			i;
	int			j;
	t_dpoint	pixel;

	j = 0;
	while (j < SCALE_FACTOR)
	{
		i = 0;
		while (i < SCALE_FACTOR)
		{
			pixel.x = x + i;
			pixel.y = y + j;
			if (is_in_circle(&pixel))
				set_pixel(&game->raycasted, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	ft_draw_mmp_background(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	while (j < MMAP_HEIGHT)
	{
		i = 0;
		while (i < MMAP_WIDTH)
		{
			ft_draw_square(MMAP_OFFSET_X + i, MMAP_OFFSET_Y + j, WALL_COLOR,
				game);
			i += SCALE_FACTOR;
		}
		j += SCALE_FACTOR;
	}
}

void	ft_draw_mmp(t_game *game, int x, int y)
{
	int	player_minimap_x;
	int	player_minimap_y;

	player_minimap_x = MMAP_WIDTH / 2;
	player_minimap_y = MMAP_HEIGHT / 2;
	game->mmap.mmap_x = player_minimap_x + (x - game->mmap.center.x)
		* SCALE_FACTOR;
	game->mmap.mmap_y = player_minimap_y + (y - game->mmap.center.y)
		* SCALE_FACTOR;
	if (game->mmap.mmap_x >= 0 && game->mmap.mmap_x < MMAP_WIDTH
		&& game->mmap.mmap_y >= 0 && game->mmap.mmap_y < MMAP_HEIGHT)
		ft_draw_square(MMAP_OFFSET_X + game->mmap.mmap_x, MMAP_OFFSET_Y
			+ game->mmap.mmap_y, game->mmap.color_pxl, game);
}

void	minimap(t_game *game)
{
	size_t	y;
	int		x;
	int		player_minimap_x;
	int		player_minimap_y;

	player_minimap_x = MMAP_WIDTH / 2;
	player_minimap_y = MMAP_HEIGHT / 2;
	game->mmap.center.x = ft_truncate(game->player.pos.x);
	game->mmap.center.y = ft_truncate(game->player.pos.y);
	ft_draw_mmp_background(game);
	y = -1;
	while (++y < game->map->map_h)
	{
		x = -1;
		game->mmap.line_length = ft_strlen(game->map->map[y]) - 1;
		while (++x < game->mmap.line_length)
		{
			ft_define_pixel_color(game, x, y);
			ft_draw_mmp(game, x, y);
		}
	}
	ft_draw_square(MMAP_OFFSET_X + player_minimap_x, MMAP_OFFSET_Y
		+ player_minimap_y, PLAYER_COLOR, game);
}
