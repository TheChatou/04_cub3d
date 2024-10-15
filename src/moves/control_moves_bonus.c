/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:55 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/14 12:34:21 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	block_sb(t_game *game, int y, int x)
{
	if (game->has_token && game->map->map[y][x] == DOOR)
		return (print_clue(game), true);
	if (game->level == 2 && game->map->map[y][x] == TOKEN)
	{
		if (fabs(game->player.pos.x - game->potion_pos.x) < 0.7
			&& fabs(game->player.pos.y - game->potion_pos.y) < 0.7)
			drink_me(game);
		return (true);
	}
	if (game->map->map[y][x] == WALL)
		return (true);
	if (game->map->map[y][x] == TRAP)
		return (true);
	return (false);
}

bool	corner_collision(t_game *game, float move_y, float move_x)
{
	int		x;
	int		y;
	float	collision_s;
	float	collision_b;

	collision_s = 0.10;
	collision_b = 0.90;
	y = ft_truncate(game->player.pos.y);
	x = ft_truncate(game->player.pos.x);
	if (block_sb(game, y - 1, x - 1) && (float)move_y - y < collision_s
		&& (float)move_x - x < collision_s)
		return (false);
	if ((block_sb(game, y - 1, x + 1) && (float)move_y - y < collision_s
			&& (float)move_x - x > collision_b))
		return (false);
	if ((block_sb(game, y + 1, x - 1) && (float)move_y - y > collision_b
			&& (float)move_x - x < collision_s))
		return (false);
	if ((block_sb(game, y + 1, x + 1) && (float)move_y - y > collision_b
			&& (float)move_x - x > collision_b))
		return (false);
	return (true);
}

bool	straight_collision(t_game *game, float move_y, float move_x)
{
	int		x;
	int		y;
	float	collision_s;
	float	collision_b;

	collision_s = 0.10;
	collision_b = 0.90;
	y = ft_truncate(game->player.pos.y);
	x = ft_truncate(game->player.pos.x);
	if (block_sb(game, y - 1, x) && (((float)move_y - y) < collision_s))
		return (false);
	if (block_sb(game, y + 1, x) && (float)move_y - y > collision_b)
		return (false);
	if (block_sb(game, y, x + 1) && (((float)move_x - x) > (collision_b)))
		return (false);
	if (block_sb(game, y, x - 1) && (((float)move_x - x) < (collision_s)))
		return (false);
	return (true);
}

bool	is_walkable(t_game *game, float move_y, float move_x)
{
	if (corner_collision(game, move_y, move_x) == false
		|| straight_collision(game, move_y, move_x) == false)
		return (false);
	return (true);
}
