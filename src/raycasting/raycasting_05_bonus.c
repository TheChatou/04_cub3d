/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_05_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:49:01 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/15 11:02:17 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	order_12(t_game *game, t_img *trap, t_point p, int order)
{
	if (order == 1)
	{
		draw_booby_trap(game, trap, game->raycasted,
			(t_point){p.x, p.y});
		draw_lifes_tex(game, &game->i_lifes, &game->raycasted,
			(t_point){p.x, p.y});
		draw_token_tex(game, &game->i_token, &game->raycasted,
			(t_point){p.x, p.y});
	}
	else if (order == 2)
	{
		draw_lifes_tex(game, &game->i_lifes, &game->raycasted,
			(t_point){p.x, p.y});
		draw_booby_trap(game, trap, game->raycasted,
			(t_point){p.x, p.y});
		draw_token_tex(game, &game->i_token, &game->raycasted,
			(t_point){p.x, p.y});
	}
}

void	order_34(t_game *game, t_img *trap, t_point p, int order)
{
	if (order == 3)
	{
		draw_lifes_tex(game, &game->i_lifes, &game->raycasted,
			(t_point){p.x, p.y});
		draw_token_tex(game, &game->i_token, &game->raycasted,
			(t_point){p.x, p.y});
		draw_booby_trap(game, trap, game->raycasted,
			(t_point){p.x, p.y});
	}
	else if (order == 4)
	{
		draw_token_tex(game, &game->i_token, &game->raycasted,
			(t_point){p.x, p.y});
		draw_lifes_tex(game, &game->i_lifes, &game->raycasted,
			(t_point){p.x, p.y});
		draw_booby_trap(game, trap, game->raycasted,
			(t_point){p.x, p.y});
	}
}

void	order_56(t_game *game, t_img *trap, t_point p, int order)
{
	if (order == 5)
	{
		draw_booby_trap(game, trap, game->raycasted,
			(t_point){p.x, p.y});
		draw_token_tex(game, &game->i_token, &game->raycasted,
			(t_point){p.x, p.y});
		draw_lifes_tex(game, &game->i_lifes, &game->raycasted,
			(t_point){p.x, p.y});
	}
	else if (order == 6)
	{
		draw_token_tex(game, &game->i_token, &game->raycasted,
			(t_point){p.x, p.y});
		draw_booby_trap(game, trap, game->raycasted,
			(t_point){p.x, p.y});
		draw_lifes_tex(game, &game->i_lifes, &game->raycasted,
			(t_point){p.x, p.y});
	}
}
