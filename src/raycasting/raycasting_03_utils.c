/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_03_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:51:56 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/11 17:04:01 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

unsigned int	get_pixel_color(t_img img, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = NULL;
	color = 0;
	dst = img.addr + (int)(y * img.line_length)
		+ x * (img.bits_per_pixel / 8);
	if (dst < img.addr || dst >= img.addr + img.line_length * img.height)
		return (color);
	color = *(unsigned int *)dst;
	return (color);
}

void	set_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = NULL;
	if (y < 0 || y >= img->height || x < 0 || x >= img->width)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_img	select_wall(t_game *game, t_ray *ray)
{
	t_img	wall;

	wall.ptr = NULL;
	if (ray->side == N_SIDE)
		wall = game->i_wall_n;
	else if (ray->side == S_SIDE)
		wall = game->i_wall_s;
	else if (ray->side == E_SIDE)
		wall = game->i_wall_e;
	else if (ray->side == W_SIDE)
		wall = game->i_wall_w;
	if (ray->is_door && game->level == 1)
		wall = game->i_door;
	else if (ray->is_door && game->level == 2)
		wall = (*render_exit(game));
	return (wall);
}
