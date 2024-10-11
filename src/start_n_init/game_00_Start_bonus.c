/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_00_Start_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:58:19 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/11 16:10:00 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//  If parsing and initialization are successful, the game is launched.
// First, the home screen is displayed, then the intro is loaded. And if
// the user presses the space bar, the raycasting thread is launched.
bool	launch(t_game *game, char *av, int level)
{
	if (!XInitThreads())
		return (ft_putstr_fd("Error\nFailed to initialize X11 threads\n",
				STDERR_FILENO), false);
	if (init_game(game) && set_game(game, av, level))
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
		pthread_mutex_lock(&game->mutex);
		game->is_loading = true;
		pthread_mutex_unlock(&game->mutex);
		if (pthread_create(&game->th.raycast_th, NULL,
				pre_raycasting, (void *)game) != 0)
			return (perror("Failed to create raycasting thread"), 1);
		game->state = LOADING;
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
	if (game->state == LOADING)
		render_loading_screen(game);
	else if (game->state == GAME_LOOP)
	{
		pthread_join(game->th.raycast_th, NULL);
		if (!raycasting(game))
			return (ft_putstr_fd("Error\nRaycasting failed\n", STDERR_FILENO), 1);
		mlx_key_hook(game->win.win, keys_moves, game);
		if (!draw_user_interface(game))
			return (ft_putstr_fd("Error\nUser interface\n", STDERR_FILENO), 1);
		mlx_put_image_to_window(game->mlx, game->win.win, game->raycasted.ptr,
			0, 0);
		end_game(game);
		if (game->state == GAME_OVER)
			return (1);
	}
	return (0);
}

void	*pre_raycasting(void *arg)
{
	t_game	*game;

	game = (t_game *)arg;
	load_imgs_bonus(game, game->map);
	if (!set_player(game, &game->player))
		return (ft_putstr_fd("Error\nCouldn't initialize the player\n",
				STDERR_FILENO), NULL);
	if (!set_img(game, &game->raycasted))
		return (ft_putstr_fd("i_raycasted failed !", STDERR_FILENO), NULL);
	if (!raycasting(game))
		return (ft_putstr_fd("Error\nRaycasting failed\n", STDERR_FILENO), NULL);
	return (NULL);
}

//  Affiche l'écran d'accueil.
bool	display_home_screen(t_game *game, t_img *home)
{
	init_img(home, TILE_SIZE);
	if (game->level == 1
		&& !load_img_n_addr(game, home, HOMESCREEN_PATH_1, "the home screen"))
		return (false);
	else if (game->level == 2 && game->player.shrink != SHRINK
		&& !load_img_n_addr(game, home, HOMESCREEN_PATH_2, "the home screen"))
		return (false);
	else if (game->level == 2 && game->player.shrink == SHRINK
		&& !load_img_n_addr(game, home, ENDING_PATH, "the ending screen"))
		return (false);
	mlx_put_image_to_window(game->mlx, game->win.win, home->ptr, 0, 0);
	return (true);
}
