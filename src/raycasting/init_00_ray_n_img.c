/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_n_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:52:20 by fcoullou          #+#    #+#             */
/*   Updated: 2024/09/04 13:45:54 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_img(t_img *img, int size)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->width = size;
	img->height = size;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

bool	set_img(t_game *game, t_img *img)
{
	img->ptr = mlx_new_image(game->mlx, game->win.width, game->win.height);
	if (!img->ptr)
		return ((ft_putstr_fd("Error\nCouldn't create the image\n",
					STDERR_FILENO)), false);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (true);
}
