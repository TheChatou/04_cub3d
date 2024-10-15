/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_01_UserInterface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:26:57 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/14 12:18:16 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	draw_user_interface(t_game *game)
{
	minimap(game);
	load_hands(game, &game->i_hands);
	draw_hands(game, &game->raycasted);
	check_if_skrinked(game);
	lifes(game, game->player.lifes);
	return (true);
}

void	check_if_skrinked(t_game *game)
{
	if (!game->has_token && game->level == 2)
		game->player.shrink = SHRINK;
}

void	lifes(t_game *game, int lifes)
{
	t_point	pos;
	t_point	tex;
	int		color;

	pos.x = 20;
	while (lifes-- > 0)
	{
		tex.y = 0;
		pos.y = WIN_SIZE - 20 - game->i_heart.height;
		while (tex.y < game->i_heart.height)
		{
			tex.x = 0;
			pos.x = 20 + lifes * game->i_heart.width;
			while (tex.x < game->i_heart.width)
			{
				color = get_pixel_color(game->i_heart, tex.x, tex.y);
				if ((int)color != ALPHA_ZERO)
					set_pixel(&game->raycasted, pos.x, pos.y, color);
				pos.x++;
				tex.x++;
			}
			pos.y++;
			tex.y++;
		}
	}
}

bool	load_hands(t_game *game, t_img *img)
{
	if (!game->has_token && game->level == 1)
	{
		free_img(game, img);
		if (!load_img_n_addr(game, img, HANDS_PATH_1_W, "the wrist watch"))
			return (false);
	}
	else if (game->level == 2)
	{
		free_img(game, img);
		if (!load_img_n_addr(game, img, HANDS_PATH_2_W, "the wrist watch"))
			return (false);
	}
	return (true);
}

void	draw_hands(t_game *game, t_img *img)
{
	t_point		pos;
	t_point		tex;
	int			color;
	t_dpoint	ratio;

	ratio = (t_dpoint){(double)game->i_hands.width / WIN_SIZE,
		(double)game->i_hands.height / WIN_SIZE};
	pos.y = 0;
	while (pos.y < WIN_SIZE)
	{
		pos.x = 0;
		while (pos.x < WIN_SIZE)
		{
			tex = (t_point){pos.x * ratio.x, pos.y * ratio.y};
			color = get_pixel_color(game->i_hands, tex.x, tex.y);
			if ((int)color != ALPHA_ZERO)
				set_pixel(img, pos.x, pos.y, color);
			pos.x++;
		}
		pos.y++;
	}
}
