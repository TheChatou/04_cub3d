/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_rights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:01:46 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/07 18:23:24 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

// int not necessary?
void	ft_access_textures(t_game *game)
{
	t_map	*map;

	map = game->map;
	if (open(map->path_wall_n, O_RDONLY) == -1
		|| open(map->path_wall_s, O_RDONLY) == -1
		|| open(map->path_wall_e, O_RDONLY) == -1
		|| open(map->path_wall_w, O_RDONLY) == -1)
		ft_error_map(game, "Error: can't open testures\n");
}
