/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crouch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:34:34 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/10 13:44:55 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	crouch(t_player *player)
{
	if (player->shrink == SHRINK)
		player->shrink = 0.0;
	else
		player->shrink = SHRINK;
	return ;
}

void	drink_me(t_game *game)
{
	int	i;

	i = 0;
	while (game->has_token && i++ < 2)
	{
		screen_flash(game, WHITE_PATH, "the white screen");
		if (i == 2)
			break ;
		screen_flash(game, BLACK_PATH, "the black screen");
	}
	if (game->player.shrink == 0.0)
		game->player.shrink = SHRINK;
	game->has_token = 0;
	game->player.speed = 0.05;
	free_img(game, &game->i_token);
	load_img_n_addr(game, &game->i_token, TABLE_PATH, "the table");
	free_img(game, &game->i_door);
	load_img_n_addr(game, &game->i_door, OPEN_DOOR_PATH_2, "the open door");
}

void	screen_flash(t_game *game, char *path, char *error)
{
	free_img(game, &game->home_screen);
	load_img_n_addr(game, &game->home_screen, path, error);
	mlx_put_image_to_window(game->mlx, game->win.win,
		game->home_screen.ptr, 0, 0);
	usleep(50);
}
