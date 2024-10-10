/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:55:02 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/10 13:44:27 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_player	slide_right(int y, int x, t_game *game)
{
	if ((block_sb(game, y, x - 1) || block_sb(game, y, x + 1))
		&& (!block_sb(game, y - 1, x) || game->dist_y < -0.2)
		&& (game->player.dir.x < 0))
		game->move_y = (game->player.pos.y += (game->player.dir.x * 0.05));
	else if ((block_sb(game, y, x - 1) || block_sb(game, y, x + 1))
		&& (!block_sb(game, y + 1, x) || game->dist_y > -0.8)
		&& (game->player.dir.x > 0))
		game->move_y = (game->player.pos.y += (game->player.dir.x * 0.05));
	else if ((block_sb(game, y - 1, x) || block_sb(game, y + 1, x))
		&& (!block_sb(game, y, x + 1) || game->dist_x > -0.8)
		&& (game->player.dir.y < 0))
		game->move_x = (game->player.pos.x -= (game->player.dir.y * 0.05));
	else if ((block_sb(game, y - 1, x) || block_sb(game, y + 1, x))
		&& (!block_sb(game, y, x - 1) || game->dist_x < -0.2)
		&& (game->player.dir.y > 0))
		game->move_x = (game->player.pos.x -= (game->player.dir.y * 0.05));
	return (game->player);
}

t_player	move_right(t_game *game, t_player player)
{
	int	x;
	int	y;

	y = ft_truncate(game->player.pos.y);
	x = ft_truncate(game->player.pos.x);
	game->move_x = player.pos.x - player.dir.y * player.speed;
	game->move_y = player.pos.y + player.dir.x * player.speed;
	game->dist_x = x - player.pos.x;
	game->dist_y = y - player.pos.y;
	player = slide_right(y, x, game);
	if (is_walkable(game, game->move_y, game->move_x))
	{
		player.pos.y += player.dir.x * player.speed;
		player.pos.x -= player.dir.y * player.speed;
	}
	else if (!lose_life(game, game->move_y, game->move_x))
	{
		player.lifes -= 1;
		screen_flash(game, RED_PATH, "the red screen");
	}
	return (player);
}
