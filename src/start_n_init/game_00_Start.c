/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_00_Start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:37:38 by chatou            #+#    #+#             */
/*   Updated: 2024/10/10 15:02:24 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//  Si l'initalisation et le parsing (effectue dans set_game) sont réussis,
// le jeu est lancé. On assigne les hooks et on lance le jeu.
bool	launch(t_game *game, char *av, int level)
{
	(void)level;
	if (init_game(game) && set_game(game, av, level))
	{
		load_i_walls(game, game->map);
		set_hooks(game);
		if (!set_player(game, &game->player))
			return (ft_putstr_fd("Error\nCouldn't initialize the player\n",
					STDERR_FILENO), 1);
		if (!set_img(game, &game->raycasted))
			return (ft_putstr_fd("Raycasting failed !", STDERR_FILENO), 1);
		mlx_key_hook(game->win.win, keys_moves, game);
		mlx_loop_hook(game->mlx, game_loop, game);
		return (true);
	}
	return (false);
}

//  La Game Loop est exécutée à chaque itération de la boucle principale.
// Cette fonction doit mettre à jour l'état du jeu, gérer
// les entrées utilisateur, effectuer le rendu de la scène,
// et rafraîchir la fenêtre.
int	game_loop(t_game *game)
{
	if (!raycasting(game))
		return (ft_putstr_fd("Error\nRaycasting failed\n", STDERR_FILENO), 1);
	mlx_put_image_to_window(game->mlx, game->win.win, game->raycasted.ptr,
		0, 0);
	return (0);
}
