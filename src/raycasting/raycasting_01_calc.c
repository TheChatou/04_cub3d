/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_01_calc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:49:51 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/03 18:12:35 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//	Calcule la distance perpendiculaire au mur rencontré et dessine le mur
// en fonction de la distance.
//	Si le side frappe le mur au nord ou au sud, on calcule la distance en x
// sinon en y.
//	Premierement, calcul de la différence entre la position du joueur et
// la position du mur. Ajustement de la distance en fonction de la direction
// du pas (+ 0 ou + 1). Le tout, divisé par la direction du rayon. qui est
// compris entre -1 et 1.
//	Puis on garde la valeur absolue du calcul de cette distance. (fabs)
//	line_height : hauteur de la ligne a dessiner
//	draw_start : debut de la ligne a dessiner
//	draw_end : fin de la ligne a dessiner
void	calc_rays(t_ray *ray, t_player *player, t_game *game)
{
	(void)game;
	if (ray->side == N_SIDE || ray->side == S_SIDE)
		ray->perp_wall_dist = (ray->map_pos.x - player->pos.x
				+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map_pos.y - player->pos.y
				+ (1 - ray->step.y) / 2) / ray->dir.y;
	ray->perp_wall_dist = fabs(ray->perp_wall_dist);
	ray->line_height = (int)(WIN_SIZE / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height / 2) + (WIN_CENTER) - ((WIN_CENTER * player->shrink / (ray->perp_wall_dist)));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2) + (WIN_CENTER) - (WIN_CENTER * player->shrink / (ray->perp_wall_dist));
	if (ray->draw_end >= WIN_SIZE)
		ray->draw_end = WIN_SIZE - 1;
}

void	calc_wall_tex_pos(t_game *game, t_ray *ray, t_img *wall)
{
	double	wall_x;

	wall_x = 0;
	if (ray->side == N_SIDE || ray->side == S_SIDE)
		wall_x = game->player.pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		wall_x = game->player.pos.x + ray->perp_wall_dist * ray->dir.x;
	wall_x -= ft_floor(wall_x);
	ray->texture.x = (int)(wall_x * (double)wall->width);
	if (((ray->side == 0 || ray->side == 1) && ray->dir.x > 0)
		|| ((ray->side == 2 || ray->side == 3) && ray->dir.y < 0))
		ray->texture.x = wall->width - ray->texture.x - 1;
}
