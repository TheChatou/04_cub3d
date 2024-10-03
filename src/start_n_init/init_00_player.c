/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_00_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:16:00 by chatou            #+#    #+#             */
/*   Updated: 2024/10/03 12:39:20 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	set_player(t_game *game, t_player *player)
{
	ft_memset(player, 0, sizeof(t_player));
	*player = set_dir_n_plane(game->map);
	player->pos = find_player_float(game->map);
	player->height = 1.0;
	player->shrink = 0.0;
	player->lifes = 3;
	return (true);
}

t_player	set_dir_n_plane(t_map *map)
{
	t_player	player;
	char		c;

	ft_memset(&player, 0, sizeof(t_player));
	c = map->map[(int)find_player_float(map).y]
	[(int)find_player_float(map).x];
	if (c == 'N')
	{
		player.dir = DIR_N;
		player.plane = PLANE_N;
	}
	else if (c == 'S')
	{
		player.dir = DIR_S;
		player.plane = PLANE_S;
	}
	else if (c == 'E')
	{
		player.dir = DIR_E;
		player.plane = PLANE_E;
	}
	else if (c == 'W')
	{
		player.dir = DIR_W;
		player.plane = PLANE_W;
	}
	return (player);
}
