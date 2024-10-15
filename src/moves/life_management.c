/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:46:11 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/11 17:46:39 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	is_trap(t_game *game, int a, int b)
{
	if (game->map->map[a][b] == TRAP)
		return (true);
	return (false);
}

bool	lose_life(t_game *game, float move_y, float move_x)
{
	int		x;
	int		y;
	float	collision_s;
	float	collision_b;

	collision_s = 0.10;
	collision_b = 0.90;
	y = ft_truncate(game->player.pos.y);
	x = ft_truncate(game->player.pos.x);
	if (is_trap(game, y - 1, x) && (((float)move_y - y) < collision_s))
		return (false);
	if (is_trap(game, y + 1, x) && (float)move_y - y > collision_b)
		return (false);
	if (is_trap(game, y, x + 1) && (((float)move_x - x) > (collision_b)))
		return (false);
	if (is_trap(game, y, x - 1) && (((float)move_x - x) < (collision_s)))
		return (false);
	return (true);
}
