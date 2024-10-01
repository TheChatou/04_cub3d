/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_actions_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:39:29 by chatou            #+#    #+#             */
/*   Updated: 2024/09/25 15:03:32 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_hooks(t_game *game)
{
	mlx_hook(game->win.win, KEY_PRESS_EVENT, KEY_PRESS_MASK, &keys_esc, game);
	mlx_hook(game->win.win, WIN_CLOSE_EVENT, NO_EVENT_MASK,
		&destroy_game, game);
}

int	keys_esc(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_game(game);
	return (0);
}

int	keys_moves(int keycode, t_game *game)
{
	update_player(game, '0');
	if (keycode == KEY_W)
		game->player = move_forward(game, game->player);
	if (keycode == KEY_S)
		game->player = move_backward(game, game->player);
	if (keycode == KEY_A)
		game->player = move_left(game, game->player);
	if (keycode == KEY_D)
		game->player = move_right(game, game->player);
	if (keycode == KEY_LEFT)
		handle_cam_motion(game, KEY_LEFT);
	if (keycode == KEY_RIGHT)
		handle_cam_motion(game, KEY_RIGHT);
	update_player(game, 'N');
	if (game->has_token)
		ft_check_if_token(game);
	return (0);
}

void	update_player(t_game *game, char c)
{
	int	x;
	int	y;

	x = ft_truncate(game->player.pos.x);
	y = ft_truncate(game->player.pos.y);
	game->map->map[y][x] = c;
}
