/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_00_set_n_cast_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:19:32 by chatou            #+#    #+#             */
/*   Updated: 2024/10/11 14:12:41 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//	Ici commence la boucle de raycasting.
//	On initialise le rayon, on le fait avancer, on calcule la distance
// entre le joueur et le mur, on dessine le mur en fonction de la distance.
// Puis on recommence pour chaque rayon, soit chaque colonne "x" de l'écran.
bool	raycasting(t_game *game)
{
	int		x;

	x = 0;
	while (x < game->win.width)
	{
		init_ray(game->ray);
		set_ray(game, x);
		cast_ray(game, game->ray);
		calc_rays(game->ray, &game->player, game);
		draw_line(game, game->ray, game->raycasted, x);
		x++;
	}
	pthread_mutex_lock(&game->mutex);
	game->is_loading = false;
	pthread_mutex_unlock(&game->mutex);
	return (true);
}

//	Initialisation des variables de la structure t_ray
// cam.x : position du rayon sur l'écran (entre -1 et 1)
// ray->dir : direction du rayon (direction du joueur + plan de la cam * cam.x)
// ray->delta_dist : distance que le rayon parcourt d'un mur à l'autre
// ray->map_pos : stockage de la position du player dans la map
void	set_ray(t_game *game, int x)
{
	double	cam;

	cam = 2 * x / (double)game->win.width - 1;
	game->ray->dir.x = game->player.dir.x + game->player.plane.x * cam;
	game->ray->dir.y = game->player.dir.y + game->player.plane.y * cam;
	game->ray->delta_dist.x = fabs(1 / game->ray->dir.x);
	game->ray->delta_dist.y = fabs(1 / game->ray->dir.y);
	game->ray->map_pos = (t_point){(int)game->player.pos.x,
		(int)game->player.pos.y};
	set_ray_step(game->ray, &game->player);
}

//	Initialisation des variables de direction et de step du rayon
// ray->step : pas d'une case a l'autre (1 ou -1) 
// ray->side_dist : distance que le rayon parcourt du joueur au premier mur
void	set_ray_step(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map_pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_pos.x + 1.0 - player->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map_pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_pos.y + 1.0 - player->pos.y)
			* ray->delta_dist.y;
	}
}

//	DDA : Digital Differential Analysis. Algorithme de tracé de ligne
// qui permet de détecter les collisions avec les murs. En gros en fonction
// de ce que touche le rayon, on va determiner le mur.
//	Tant que le rayon n'a pas touché de mur, on continue de le faire avancer
// le rayon.
//	Si la distance du joueur a la prochaine case en x est plus petite que
// la distance du joueur a la prochaine case en y, on fait avancer le rayon
// en x, sinon en y.
//	On modifie egalement la position du joueur en fonction de la direction
// du rayon.
void	cast_ray(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step.x;
			if (ray->dir.x < 0)
				ray->side = W_SIDE;
			else
				ray->side = E_SIDE;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step.y;
			if (ray->dir.y < 0)
				ray->side = N_SIDE;
			else
				ray->side = S_SIDE;
		}
		ray_hit_check(game, ray);
	}
}

//	Verifie si le rayon a touché un mur ou un token
//	Si le rayon touche un mur o une porte, on arrete le rayon
//	Si le rayon touche un token, on stocke la position du token
void	ray_hit_check(t_game *game, t_ray *ray)
{
	if (game->map->map[ray->map_pos.y][ray->map_pos.x] == DOOR)
		ray->is_door = 1;
	if ((game->map->map[ray->map_pos.y][ray->map_pos.x] == WALL)
		|| (game->map->map[ray->map_pos.y][ray->map_pos.x] == DOOR))
		ray->hit = 1;
	if (game->map->map[ray->map_pos.y][ray->map_pos.x] == TOKEN)
	{
		ray->token.hit = 1;
		ray->token.pos = (t_dpoint){ray->map_pos.x + 0.5,
			ray->map_pos.y + 0.5};
		game->potion_pos = ray->token.pos;
	}
	if (game->map->map[ray->map_pos.y][ray->map_pos.x] == LIFE)
	{
		ray->lifes.hit = 1;
		ray->lifes.pos = (t_dpoint){ray->map_pos.x + 0.5,
			ray->map_pos.y + 0.5};
	}
	if (game->map->map[ray->map_pos.y][ray->map_pos.x] == TRAP)
	{
		ray->btrap.hit = 1;
		ray->btrap.pos = (t_dpoint){ray->map_pos.x + 0.5,
			ray->map_pos.y + 0.5};
	}
}
