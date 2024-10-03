/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_02_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:56:42 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/03 18:18:24 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_img	draw_line(t_game *game, t_ray *ray, t_img img, int x)
{
	t_img		wall;
	int			y;

	y = 0;
	wall = select_wall(game, ray);
	calc_wall_tex_pos(game, ray, &wall);
	ray->pxl_step = 1.0 * wall.height / ray->line_height;
	ray->texture_pos_y = ray->draw_start * ray->pxl_step;
	while (y < WIN_SIZE)
	{
		if (y < ray->draw_start)
			set_pixel(&img, x, y, t_color_to_uint(*(game->map->ceiling)));
		else if (y >= ray->draw_start && y < ray->draw_end)
			draw_wall_tex(game, &wall, &img, (t_point){x, y});
		else
			set_pixel(&img, x, y, t_color_to_uint(*(game->map->floor)));
		y++;
	}
	return (img);
}

void	draw_wall_tex(t_game *game, t_img *wall, t_img *img, t_point pxl_pos)
{
	unsigned int	color;

	game->ray->texture.y = (int)game->ray->texture_pos_y % wall->height;
	game->ray->texture_pos_y += game->ray->pxl_step;
	color = get_pixel_color(*wall, game->ray->texture.x, game->ray->texture.y);
	set_pixel(img, pxl_pos.x, pxl_pos.y, color);
}
