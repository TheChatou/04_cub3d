/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:15:25 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/14 12:31:13 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	check_if_end(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == DOOR)
				return (false);
			j++;
		}
		i++;
	}
	return (printf("i : %d j : %d\n", i, j), true);
}

bool	check_if_dead(t_game *game)
{
	if (game->player.lifes <= 0)
		return (true);
	return (false);
}

t_tri_point	find_player_float(t_map *map)
{
	t_tri_point	p;

	p.y = 0;
	p.z = 0.5;
	while (p.y < map->map_h)
	{
		p.x = 0;
		while (p.x < map->map_w)
		{
			if (map->map[(int)p.y][(int)p.x] == 0)
				break ;
			if (map->map[(int)p.y][(int)p.x] == NORTH
				|| map->map[(int)p.y][(int)p.x] == SOUTH
				|| map->map[(int)p.y][(int)p.x] == EAST
				|| map->map[(int)p.y][(int)p.x] == WEST)
				return ((t_tri_point){p.x + 0.5, p.y + 0.5, p.z + 0.5});
			p.x++;
		}
		p.y++;
	}
	return ((t_tri_point){0, 0, 0});
}

void	ft_check_if_token(t_game *game)
{
	int				x;
	int				y;
	unsigned long	z;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == TOKEN)
				return ;
			x++;
		}
		y++;
	}
	z = y;
	if (z == game->map->map_h - 1)
	{
		game->has_token = 0;
		free_img(game, &game->i_hands);
		load_img_n_addr(game, &game->i_hands, HANDS_PATH_1_W, "the hands");
	}
}
