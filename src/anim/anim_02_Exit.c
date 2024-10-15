/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_02_Exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:46:15 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/15 11:35:58 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_img	*render_exit(t_game *game)
{
	long	t_curr;

	t_curr = get_current_time_ms();
	if (t_curr - game->last_frame_time >= 1000)
	{
		if (!game->i_exit[game->current_frame].ptr)
			return (printf("Image pointer is null at index %d\n",
					game->current_frame), NULL);
		game->current_frame = (game->current_frame + 1) % 4;
		game->last_frame_time = t_curr;
	}
	return (&game->i_exit[game->current_frame]);
}

void	load_i_exit(t_game *game)
{
	int			i;

	i = -1;
	set_p_exit(game);
	if (game->level == 2 && !game->has_token)
		free_anims(game, game->i_exit);
	while (++i < 4)
	{
		if (!game->p_exit[i])
			break ;
		if (!load_img_n_addr(game, &game->i_exit[i],
				game->p_exit[i], "the exit"))
			destroy_game(game);
	}
}

void	set_p_exit(t_game *game)
{
	if (game->level == 2 && game->has_token)
	{
		game->p_exit[0] = DOOR_LVL2_PATH_1;
		game->p_exit[1] = DOOR_LVL2_PATH_2;
		game->p_exit[2] = DOOR_LVL2_PATH_1;
		game->p_exit[3] = DOOR_LVL2_PATH_2;
	}
	else if (game->level == 2 && !game->has_token)
	{
		game->p_exit[0] = OPEN_DOOR_PATH_1;
		game->p_exit[1] = OPEN_DOOR_PATH_2;
		game->p_exit[2] = OPEN_DOOR_PATH_1;
		game->p_exit[3] = OPEN_DOOR_PATH_2;
	}
}
