/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_actions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:56:41 by mamoulin          #+#    #+#             */
/*   Updated: 2024/09/13 15:00:41 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	rotate_arrows(t_player *player, double angle)
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

int	handle_cam_motion(t_game *game, int keycode)
{
	double	angle;
	double	delta_x;
	int		x;

	x = 1;
	delta_x = x - game->win.width / 2;
	angle = delta_x * game->cam.sensitivity;
	if (keycode == KEY_RIGHT)
		angle *= -1;
	rotate_arrows(&game->player, angle);
	return (0);
}
