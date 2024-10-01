/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_02_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:56:42 by fcoullou          #+#    #+#             */
/*   Updated: 2024/09/25 18:16:43 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_img	draw_line(t_game *game, t_ray *ray, t_img img, int x)
{
	t_img		wall;
	t_img		*trap;
	int			y;
	double		center;

	y = 0;
	wall = select_wall(game, ray);
	trap = render_booby_trap(game);
	calc_wall_tex_pos(game, ray, &wall);
	calc_booby_trap(game, &game->player, &game->ray->btrap);
	center = (game->win.height / 2) * game->player.view_height;
	ray->pxl_step = 1.0 * wall.height / ray->line_height;
	ray->texture_pos_y = (ray->draw_start - center
			+ ray->line_height / 2) * ray->pxl_step;
	while (y < game->win.height)
	{
		if (y < ray->draw_start)
			draw_ceiling_tex(game, ray, game->i_ceiling, (t_point){x, y});
		else if (y >= ray->draw_start && y < ray->draw_end)
			draw_wall_tex(game, &wall, &img, (t_point){x, y});
		else
			draw_floor_tex(game, ray, game->i_floor, (t_point){x, y});
		y++;
	}
	if (ray->token.hit || ray->is_btrap)
	{
		y = 0;
		while (y < game->win.height)
		{
			if (y >= ray->token.draw_start.y && y < ray->token.draw_end.y)
				draw_token_tex(game, &game->i_token, &img, (t_point){x, y});
			if (y >= ray->btrap.draw_start.y && y < ray->btrap.draw_end.y)
				draw_booby_trap(game, trap, img, (t_point){x, y});
			y++;
		}
	}
	return (img);
}

void	draw_token_tex(t_game *game, t_img *i_token,
							t_img *img, t_point pxl_pos)
{
	unsigned int	color;
	t_dpoint		relative_pos;

	relative_pos.y = (double)(pxl_pos.y - game->ray->token.draw_start.y)
		/ game->ray->token.line_height;
	relative_pos.x = (double)(pxl_pos.x - game->ray->token.draw_start.x)
		/ game->ray->token.line_width;
	if (relative_pos.x < 0)
		relative_pos.x = 0;
	else if (relative_pos.x > 1)
		relative_pos.x = 1;
	game->ray->texture.y = (int)(relative_pos.y
			* i_token->height) % i_token->height;
	game->ray->texture.x = (int)(relative_pos.x
			* i_token->width) % i_token->width;
	color = get_pixel_color(*i_token, game->ray->texture.x,
			game->ray->texture.y);
	if ((int)color != ALPHA_ZERO)
		set_pixel(img, pxl_pos.x, pxl_pos.y, color);
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

void	draw_booby_trap(t_game *game, t_img *trap, t_img img, t_point pxl_pos)
{
	unsigned int	color;
	t_line			*btrap;

	btrap = &game->ray->btrap;
	btrap->relative_pos.y = (double)(pxl_pos.y - btrap->draw_start.y) / btrap->line_height;
	btrap->relative_pos.x = (double)(pxl_pos.x - btrap->draw_start.x) / btrap->line_width;
	if (btrap->relative_pos.x < 0)
		return ;
	else if (btrap->relative_pos.x > 1)
		return ;
	game->ray->texture.y = (int)(btrap->relative_pos.y * trap->height) % trap->height;
	game->ray->texture.x = (int)(btrap->relative_pos.x * trap->width) % trap->width;
	color = get_pixel_color(*trap, game->ray->texture.x, game->ray->texture.y);
	if ((int)color != ALPHA_ZERO)
		set_pixel(&img, pxl_pos.x, pxl_pos.y, color);
}
