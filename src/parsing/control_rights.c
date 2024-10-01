/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_rights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:01:46 by mamoulin          #+#    #+#             */
/*   Updated: 2024/08/02 16:17:31 by mamoulin         ###   ########.fr       */
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

// not necessary, already do it at my first open
// int	ft_access_map(t_data *data, char *map_file)
// {
// 	if (open(map_file, O_RDONLY) == -1)
// 		ft_error_map(data, "Error: can't open the map\n");
// 	return (0);
// }