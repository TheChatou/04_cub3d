/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_00_Start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:37:38 by chatou            #+#    #+#             */
/*   Updated: 2024/09/24 14:15:47 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//  If parsing and initialization are successful, the game is launched.
// First, the home screen is displayed, then the intro is loaded. And if
// the user presses the space bar, the raycasting thread is launched.
bool	launch(t_game *game, char *av, int level)
{
	(void)level;
	if (init_game(av, game) && set_game(game, level))
	{
		set_hooks(game);
		if (!display_home_screen(game, &game->home_screen))
			return (false);
		load_i_intro(game);
		mlx_key_hook(game->win.win, start, game);
		return (true);
	}
	return (false);
}

//  This function is called when the user presses the space bar.
// It launches the raycasting thread and the loading screen thread.
int	start(int keycode, t_game *game)
{
	if (keycode == KEY_SPACE)
	{
		load_imgs(game, game->map);
		if (!set_player(game, &game->player))
			return (ft_putstr_fd("Error\nCouldn't initialize the player\n",
					STDERR_FILENO), 1);
		if (!set_img(game, &game->raycasted))
			return (ft_putstr_fd("Raycasting failed !", STDERR_FILENO), 1);
		mlx_loop_hook(game->mlx, game_loop, game);
		return (0);
	}
	return (0);
}

//  La Game Loop est exécutée à chaque itération de la boucle principale.
// Cette fonction doit mettre à jour l'état du jeu, gérer
// les entrées utilisateur, effectuer le rendu de la scène,
// et rafraîchir la fenêtre.
int	game_loop(t_game *game)
{
	if (!raycasting(game))
		return (ft_putstr_fd("Error\nRaycasting failed\n", STDERR_FILENO), 1);
	mlx_key_hook(game->win.win, keys_moves, game);
	if (!draw_user_interface(game))
		return (ft_putstr_fd("Error\nUser interface\n", STDERR_FILENO), 1);
	mlx_put_image_to_window(game->mlx, game->win.win, game->raycasted.ptr,
		0, 0);
	if (check_if_end(game))
	{
		if (game->level == 2)
			you_win();
		free_game(game);
	}
	return (0);
}

bool	display_home_screen(t_game *game, t_img *home)
{
	init_img(home, TILE_SIZE);
	if (game->level == 1
		&& !load_img_n_addr(game, home, HOMESCREEN_PATH_1, "the home screen"))
		return (false);
	else if (game->level == 2
		&& !load_img_n_addr(game, home, HOMESCREEN_PATH_2, "the home screen"))
		return (false);
	mlx_put_image_to_window(game->mlx, game->win.win, home->ptr, 0, 0);
	return (true);
}
