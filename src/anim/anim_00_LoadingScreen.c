/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_00_LoadingScreen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:29:28 by fcoullou          #+#    #+#             */
/*   Updated: 2024/09/12 18:22:30 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	render_loading_screen(t_game *game)
{
	long	t_curr;

	t_curr = get_current_time_ms();
	if (t_curr - game->last_frame_time >= 200)
	{
		if (!is_loading(game))
		{
			game->state = GAME_LOOP;
			return (1);
		}
		mlx_clear_window(game->mlx, game->win.win);
		if (!game->i_intro[game->current_frame].ptr)
			return (printf("Image pointer is null at index %d\n",
					game->current_frame), 0);
		pthread_mutex_lock(&game->mutex);
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->i_loading.ptr, (WIN_SIZE / 2 - 50), (WIN_SIZE / 4));
		pthread_mutex_unlock(&game->mutex);
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->i_intro[game->current_frame].ptr, (WIN_SIZE / 2 - 50),
			(WIN_SIZE / 2 - 50));
		game->current_frame = (game->current_frame + 1) % 4;
		game->last_frame_time = t_curr;
	}
	return (0);
}

void	load_i_intro(t_game *game)
{
	int			i;

	i = -1;
	set_p_intro(game);
	while (++i < 4)
	{
		if (!game->p_intro[i])
			break ;
		if (!load_img_n_addr(game, &game->i_intro[i],
				game->p_intro[i], "the intro"))
			destroy_game(game);
	}
	load_img_n_addr(game, &game->i_loading, LOADING_PATH, "the load");
}

void	set_p_intro(t_game *game)
{
	game->p_intro[0] = INTRO_1;
	game->p_intro[1] = INTRO_2;
	game->p_intro[2] = INTRO_3;
	game->p_intro[3] = INTRO_4;
}

int	is_loading(t_game *game)
{
	int	res;

	pthread_mutex_lock(&game->mutex);
	res = game->is_loading;
	pthread_mutex_unlock(&game->mutex);
	return (res);
}
