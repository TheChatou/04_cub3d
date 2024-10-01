/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02_load_imgs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:55:40 by fcoullou          #+#    #+#             */
/*   Updated: 2024/09/12 17:38:36 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	load_imgs(t_game *game, t_map *map)
{
	load_i_btrap(game);
	load_img_n_addr(game, &game->i_wall_n, map->path_wall_n, "the north wall");
	load_img_n_addr(game, &game->i_wall_s, map->path_wall_s, "the south wall");
	load_img_n_addr(game, &game->i_wall_e, map->path_wall_e, "the east wall");
	load_img_n_addr(game, &game->i_wall_w, map->path_wall_w, "the west wall");
	load_img_n_addr(game, &game->i_heart, HEART_PATH, "the heart");
	pthread_mutex_lock(&game->mutex);
	load_img_n_addr(game, &game->i_loading, LOADING_PATH, "the load");
	pthread_mutex_unlock(&game->mutex);
	if (game->level == 1)
	{
		if (!game->has_token)
			load_img_n_addr(game, &game->i_hands, HANDS_PATH_1_W, "the hands");
		else
			load_img_n_addr(game, &game->i_hands, HANDS_PATH_1, "the hands");
		load_img_n_addr(game, &game->i_floor, FLOOR_PATH_1, "the floor");
		load_img_n_addr(game, &game->i_ceiling, CEILING_PATH_1, "the ceiling");
		load_img_n_addr(game, &game->i_token, WATCH_PATH, "the token");
		load_img_n_addr(game, &game->i_door, DOOR_PATH_1, "the door");
	}
	else if (game->level == 2)
	{
		load_img_n_addr(game, &game->i_floor, FLOOR_PATH_2, "the floor");
		load_img_n_addr(game, &game->i_ceiling, CEILING_PATH_2, "the ceiling");
		load_img_n_addr(game, &game->i_hands, HANDS_PATH_2_W, "the hands");
		load_img_n_addr(game, &game->i_token, POTION_PATH, "the token");
		load_img_n_addr(game, &game->i_door, DOOR_PATH_2, "the door");
	}
}

bool	load_img_n_addr(t_game *game, t_img *img, char *path, char *error)
{
	if (!img->ptr)
	{
		img->ptr = mlx_xpm_file_to_image(game->mlx,
				path, &img->width, &img->height);
		if (!img->ptr)
		{
			ft_putstr_fd("Error\nCouldn't load ", STDERR_FILENO);
			ft_putstr_fd(error, STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
			return (false);
		}
		else
			img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
					&img->line_length, &img->endian);
	}
	return (true);
}

t_img error_img(void)
{
	t_img	img;

	img.ptr = NULL;
	img.width = 0;
	img.height = 0;
	return	(img);
}
