/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_01_BoobyTrap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:26:23 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/14 15:42:40 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_img	*render_booby_trap(t_game *game)
{
	long	t_curr;

	t_curr = get_current_time_ms();
	if (t_curr - game->last_frame_time >= 200)
	{
		if (!game->i_btrap[game->current_frame].ptr)
			return (printf("Image pointer is null at index %d\n",
					game->current_frame), NULL);
		game->current_frame = (game->current_frame + 1) % 4;
		game->last_frame_time = t_curr;
	}
	return (&game->i_btrap[game->current_frame]);
}

void	load_i_btrap(t_game *game)
{
	int			i;

	i = -1;
	set_p_btrap(game);
	while (++i < 4)
	{
		if (!game->p_btrap[i])
			break ;
		if (!load_img_n_addr(game, &game->i_btrap[i],
				game->p_btrap[i], "the booby trap"))
			destroy_game(game);
	}
}

void	set_p_btrap(t_game *game)
{
	if (game->level == 1)
	{
		game->p_btrap[0] = BTRAP_L1_1;
		game->p_btrap[1] = BTRAP_L1_2;
		game->p_btrap[2] = BTRAP_L1_3;
		game->p_btrap[3] = BTRAP_L1_4;
	}
	else if (game->level == 2)
	{
		game->p_btrap[0] = BTRAP_L2_1;
		game->p_btrap[1] = BTRAP_L2_2;
		game->p_btrap[2] = BTRAP_L2_3;
		game->p_btrap[3] = BTRAP_L2_4;
	}
}
