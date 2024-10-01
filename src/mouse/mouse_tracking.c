/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_tracking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:39:41 by fcoullou          #+#    #+#             */
/*   Updated: 2024/08/20 17:27:21 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	handle_mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->player.weapons.shoot = 1;
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->player.weapons.shoot = 0;
	return (0);
}

void	rotate_cam(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir.x;
	old_plane_x = player->plane.x;
	player->dir.x = player->dir.x * cos(angle) - player->dir.y
		* sin(angle);
	player->dir.y = old_dir_x * sin(angle) + player->dir.y
		* cos(angle);
	player->plane.x = player->plane.x * cos(angle) - player->plane.y
		* sin(angle);
	player->plane.y = old_plane_x * sin(angle) + player->plane.y
		* cos(angle);
}

int	handle_mouse_motion(int x, int y, t_game *game)
{
	double	angle;
	double	delta_x;

	delta_x = x - game->win.width / 2;
	game->player.mouse.pos = (t_point){x, y};
	mlx_mouse_move(game->mlx, game->win.win, game->win.width / 2,
		game->win.height / 2);
	angle = delta_x * game->cam.sensitivity;
	rotate_cam(&game->player, angle);
	return (0);
}
