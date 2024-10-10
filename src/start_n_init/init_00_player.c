/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_00_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:16:00 by chatou            #+#    #+#             */
/*   Updated: 2024/10/09 13:49:46 by fcoullou         ###   ########.fr       */
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
	player->speed = 0.1;
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
		player = (t_player){.dir = (t_dpoint){DIR_N_X, DIR_N_Y},
			.plane = (t_dpoint){PLANE_N_X, PLANE_N_Y}};
	else if (c == 'S')
		player = (t_player){.dir = (t_dpoint){DIR_S_X, DIR_S_Y},
			.plane = (t_dpoint){PLANE_S_X, PLANE_S_Y}};
	else if (c == 'E')
		player = (t_player){.dir = (t_dpoint){DIR_E_X, DIR_E_Y},
			.plane = (t_dpoint){PLANE_E_X, PLANE_E_Y}};
	else if (c == 'W')
		player = (t_player){.dir = (t_dpoint){DIR_W_X, DIR_W_Y},
			.plane = (t_dpoint){PLANE_W_X, PLANE_W_Y}};
	return (player);
}
