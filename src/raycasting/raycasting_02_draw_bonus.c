/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_02_draw_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:56:42 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/10 13:40:41 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_img	draw_line(t_game *game, t_ray *ray, t_img img, int x)
{
	t_img		wall;
	int			y;
	int			real_start;

	y = 0;
	wall = select_wall(game, ray);
	calc_wall_tex_pos(game, ray, &wall);
	calc_booby_trap(game, &game->player, &game->ray->btrap);
	ray->pxl_step = 1.0 * wall.height / ray->line_height;
	real_start = -(ray->line_height / 2) + (WIN_CENTER)
		- ((WIN_CENTER * game->player.shrink / (ray->perp_wall_dist)));
	ray->texture_pos_y = (ray->draw_start - real_start) * ray->pxl_step;
	while (y < WIN_SIZE)
	{
		if (y < ray->draw_start)
			draw_ceiling_tex(game, ray, game->i_ceiling, (t_point){x, y});
		else if (y >= ray->draw_start && y < ray->draw_end)
			draw_wall_tex(game, &wall, &img, (t_point){x, y});
		else
			draw_floor_tex(game, ray, game->i_floor, (t_point){x, y});
		y++;
	}
	draw_tokens(game, ray, (t_dpoint){x, y}, &img);
	return (img);
}

void	draw_tokens(t_game *game, t_ray *ray, t_dpoint win_pos, t_img *img)
{
	t_img		*trap;

	trap = render_booby_trap(game);
	if (ray->token.hit || ray->btrap.hit || ray->lifes.hit)
	{
		win_pos.y = 0;
		while (win_pos.y < WIN_SIZE)
		{
			if (win_pos.y >= ray->token.draw_start.y
				&& win_pos.y < ray->token.draw_end.y)
				draw_token_tex(game, &game->i_token, img,
					(t_point){win_pos.x, win_pos.y});
			if (win_pos.y >= ray->lifes.draw_start.y
				&& win_pos.y < ray->lifes.draw_end.y)
				draw_lifes_tex(game, &game->i_lifes, img,
					(t_point){win_pos.x, win_pos.y});
			if (win_pos.y >= ray->btrap.draw_start.y
				&& win_pos.y < ray->btrap.draw_end.y)
				draw_booby_trap(game, trap, *img,
					(t_point){win_pos.x, win_pos.y});
			win_pos.y++;
		}
	}
}

void	draw_wall_tex(t_game *game, t_img *wall, t_img *img, t_point pxl_pos)
{
	unsigned int	color;

	game->ray->texture.y = (int)game->ray->texture_pos_y % wall->height;
	game->ray->texture_pos_y += game->ray->pxl_step;
	color = get_pixel_color(*wall, game->ray->texture.x, game->ray->texture.y);
	if ((int)color == ALPHA_ZERO)
		draw_ceiling_tex(game, game->ray, game->i_ceiling, pxl_pos);
	else
		set_pixel(img, pxl_pos.x, pxl_pos.y, color);
}

void	draw_floor_tex(t_game *game, t_ray *ray, t_img img, t_point pxl_pos)
{
	t_dpoint		floor;
	t_point			floor_tex;
	t_dpoint		floor_step;
	unsigned int	color;

	floor_step = calc_floor_tex_pos(game, ray, pxl_pos.y, &floor);
	floor_tex.x = (int)(floor.x * img.width) % img.width;
	floor_tex.y = (int)(floor.y * img.height) % img.height;
	color = get_pixel_color(img, floor_tex.x, floor_tex.y);
	if ((int)color == ALPHA_ZERO)
		color = t_color_to_uint((*game->map->floor));
	set_pixel(&game->raycasted, pxl_pos.x, pxl_pos.y, color);
}

void	draw_ceiling_tex(t_game *game, t_ray *ray, t_img img, t_point pxl_pos)
{
	t_dpoint		ceiling;
	t_point			ceiling_tex;
	unsigned int	color;

	calc_ceiling_tex_pos(game, ray, pxl_pos.y, &ceiling);
	ceiling_tex.x = (int)(ceiling.x * img.width) % img.width;
	ceiling_tex.y = (int)(ceiling.y * img.height) % img.height;
	color = get_pixel_color(img, ceiling_tex.x, ceiling_tex.y);
	if ((int)color == ALPHA_ZERO)
		color = t_color_to_uint((*game->map->ceiling));
	set_pixel(&game->raycasted, pxl_pos.x, pxl_pos.y, color);
}
