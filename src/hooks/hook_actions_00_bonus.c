/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_actions_00_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:03:21 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/14 12:18:01 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	set_hooks(t_game *game)
{
	mlx_hook(game->win.win, KEY_PRESS_EVENT, KEY_PRESS_MASK, &keys_esc, game);
	mlx_hook(game->win.win, WIN_CLOSE_EVENT, NO_EVENT_MASK,
		&destroy_game, game);
	mlx_hook(game->win.win, MotionNotify, PointerMotionMask,
		&handle_mouse_motion, game);
	mlx_mouse_hide(game->mlx, game->win.win);
}

int	keys_esc(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		destroy_game(game);
	else if (keycode == KEY_P)
		game->print = 1;
	else if (keycode == KEY_O)
		game->print = 0;
	return (0);
}

int	keys_moves(int keycode, t_game *game)
{
	update_player(game, VOID);
	if (keycode == KEY_W || keycode == KEY_UP)
		game->player = move_forward(game, game->player);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->player = move_backward(game, game->player);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		game->player = move_left(game, game->player);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->player = move_right(game, game->player);
	if (keycode == KEY_C)
		crouch(&game->player);
	update_player(game, NORTH);
	return (0);
}

void	update_player(t_game *game, char c)
{
	int	x;
	int	y;

	x = ft_truncate(game->player.pos.x);
	y = ft_truncate(game->player.pos.y);
	if (game->map->map[y][x] == LIFE)
		game->player.lifes = game->player.lifes + 1;
	if (game->map->map[y][x] == TOKEN)
		game->has_token--;
	game->map->map[y][x] = c;
}
