/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_03_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:06:12 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/15 11:01:48 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

unsigned int	get_pixel_color(t_img img, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = NULL;
	color = 0;
	dst = img.addr + (int)(y * img.line_length) + x * (img.bits_per_pixel / 8);
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

//	Verfifie la distance entre les differents elements qui peuvent se superposer
//	la fonction retourne un int de 1 a 6 qui correspond a l'ordre d'affichage :
//	1 : token, lifes, btrap
//	2 : token, btrap, lifes
//	3 : btrap, token, lifes
//	4 : btrap, lifes, token
//	5 : lifes, token, btrap
//	6 : lifes, btrap, token
int	check_dist_elements(t_ray *ray)
{
	if (ray->token.dist <= ray->btrap.dist
		&& ray->token.dist <= ray->lifes.dist)
	{
		if (ray->lifes.dist <= ray->btrap.dist)
			return (1);
		else
			return (2);
	}
	else if (ray->btrap.dist <= ray->token.dist
		&& ray->btrap.dist <= ray->lifes.dist)
	{
		if (ray->token.dist <= ray->lifes.dist)
			return (3);
		else
			return (4);
	}
	else if (ray->lifes.dist <= ray->token.dist
		&& ray->lifes.dist <= ray->btrap.dist)
	{
		if (ray->token.dist <= ray->btrap.dist)
			return (5);
		else
			return (6);
	}
	return (0);
}

bool	is_to_draw(int y, t_line *line)
{
	return (line->hit && y >= line->draw_start.y && y < line->draw_end.y);
}
