/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_01_calc_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:49:51 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/11 14:36:58 by fcoullou         ###   ########.fr       */
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
	if (ray->side == W_SIDE || ray->side == E_SIDE)
		ray->perp_wall_dist = (ray->map_pos.x - player->pos.x
				+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map_pos.y - player->pos.y
				+ (1 - ray->step.y) / 2) / ray->dir.y;
	ray->perp_wall_dist = fabs(ray->perp_wall_dist);
	ray->line_height = (int)(WIN_SIZE / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height / 2) + (WIN_CENTER)
		- ((WIN_CENTER * player->shrink / (ray->perp_wall_dist)));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2) + (WIN_CENTER)
		- (WIN_CENTER * player->shrink / (ray->perp_wall_dist));
	if (ray->draw_end >= WIN_SIZE)
		ray->draw_end = WIN_SIZE - 1;
	calc_ray_token(game, &game->player, &game->ray->token);
	calc_ray_token(game, &game->player, &game->ray->lifes);
}

void	calc_wall_tex_pos(t_game *game, t_ray *ray, t_img *wall)
{
	double	wall_x;

	wall_x = 0;
	if (ray->side == W_SIDE || ray->side == E_SIDE)
		wall_x = game->player.pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		wall_x = game->player.pos.x + ray->perp_wall_dist * ray->dir.x;
	wall_x -= ft_floor(wall_x);
	ray->texture.x = (int)(wall_x * (double)wall->width);
	if (((ray->side == 2 || ray->side == 3) && ray->dir.x < 0)
		|| ((ray->side == 0 || ray->side == 1) && ray->dir.y > 0))
		ray->texture.x = wall->width - ray->texture.x - 1;
}

t_dpoint	calc_floor_tex_pos(t_game *game, t_ray *ray, int y, t_dpoint *floor)
{
	double		row_distance;
	t_dpoint	floor_step;
	double		center;

	if (game->player.shrink == SHRINK)
		center = (WIN_SIZE * game->player.shrink) / (SHRINK * 3.5);
	else
		center = WIN_SIZE;
	row_distance = center / (2.0 * y - WIN_SIZE);
	floor_step.x = row_distance * (game->player.dir.x - game->player.plane.x);
	floor_step.y = row_distance * (game->player.dir.y - game->player.plane.y);
	floor->x = game->player.pos.x + row_distance * ray->dir.x;
	floor->y = game->player.pos.y + row_distance * ray->dir.y;
	return (floor_step);
}

//	Calcule la position du plafond en fonction de la direction du joueur
// Definition du plafond qui bouge sir le level est 1 (nuages en exterieur)
void	calc_ceiling_tex_pos(t_game *game, t_ray *ray, int y, t_dpoint *ceiling)
{
	double		row_distance;
	t_dpoint	ceiling_step;
	double		center;

	if (game->player.shrink == SHRINK)
		center = (WIN_SIZE * game->player.shrink) / (SHRINK / 1.5);
	else
		center = WIN_SIZE;
	if (game->level == 1)
		row_distance = center / (0.8 * (y - WIN_SIZE - WIN_SIZE));
	else
		row_distance = center / (2.0 * (WIN_SIZE - y) - WIN_SIZE);
	ceiling_step.x = row_distance * (game->player.dir.x - game->player.plane.x);
	ceiling_step.y = row_distance * (game->player.dir.y - game->player.plane.y);
	ceiling->x = (game->player.pos.x + row_distance * ray->dir.x);
	ceiling->y = (game->player.pos.y + row_distance * ray->dir.y);
	if (game->level == 1)
	{
		ceiling->x *= 0.4;
		ceiling->y *= 0.4;
	}
}

//	Calcule la position du booby trap en fonction de la direction du joueur
//	dist : distance entre le joueur et le booby trap grace a Pythagore
//	line_height : hauteur de la ligne du btrap a dessiner
//	line_width : largeur de la ligne du btrap a dessiner
//	draw_start : debut de la ligne du btrap a dessiner
//	draw_end : fin de la ligne du btrap a dessiner
//	relative_pos : position relative du joueur par rapport au btrap
//	det : determinant de la transformation, calcule grace a la
// direction du joueur et le plan de la camera.
//	transform : transformation du btrap
//	inv_det : inverse de la transformation, 1 divive par le determinant
void	calc_booby_trap(t_game *game, t_player *player, t_line *btrap)
{
	if (game->ray->btrap.hit)
	{
		btrap->dist = sqrt(pow(btrap->pos.x - player->pos.x, 2)
				+ pow(btrap->pos.y - player->pos.y, 2));
		btrap->line_height = (int)(WIN_SIZE / btrap->dist);
		btrap->line_width = (int)(WIN_SIZE / btrap->dist);
		btrap->draw_start.y = -btrap->line_height / 2 + WIN_CENTER
			- (WIN_CENTER * player->shrink / btrap->dist);
		btrap->draw_end.y = btrap->line_height / 2 + WIN_CENTER
			- (WIN_CENTER * player->shrink / btrap->dist);
		btrap->relative_pos.x = btrap->pos.x - player->pos.x;
		btrap->relative_pos.y = btrap->pos.y - player->pos.y;
		btrap->transform.x = (player->dir.y * btrap->relative_pos.x
				- player->dir.x * btrap->relative_pos.y);
		btrap->transform.y = (-player->plane.y * btrap->relative_pos.x
				+ player->plane.x * btrap->relative_pos.y);
		btrap->screen_x = (int)((WIN_CENTER)
				* (1 + btrap->transform.x / btrap->transform.y));
		btrap->draw_start.x = btrap->screen_x - btrap->line_width / 2;
		btrap->draw_end.x = btrap->draw_start.x + btrap->line_width;
	}
}
