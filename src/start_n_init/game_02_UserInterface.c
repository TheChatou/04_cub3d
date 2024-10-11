/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_02_UserInterface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:55:19 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/11 17:29:21 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//  Affiche l'écran d'accueil.
bool	display_home_screen(t_game *game, t_img *home)
{
	if (!set_img(game, home))
		return (ft_putstr_fd("Error\nCouldn't initialize the home screen\n",
				STDERR_FILENO), false);
	if (game->level == 1
		&& !load_img_n_addr(game, &game->i_home, HOMESCREEN_PATH_1,
			"the home screen"))
		return (false);
	else if (game->level == 2 && game->player.shrink != SHRINK
		&& !load_img_n_addr(game, &game->i_home, HOMESCREEN_PATH_2,
			"the home screen"))
		return (false);
	else if (game->level == 2 && game->player.shrink == SHRINK
		&& !load_img_n_addr(game, &game->i_home, ENDING_PATH,
			"the ending screen"))
		return (false);
	draw_homescreen(&game->i_home, home);
	mlx_put_image_to_window(game->mlx, game->win.win, home->ptr, 0, 0);
	return (true);
}

void	draw_homescreen(t_img *i_home, t_img *homescreen)
{
	t_point		pos;
	t_point		tex;
	int			color;
	t_dpoint	ratio;

	if (!homescreen || !homescreen->addr)
		return (perror("Error: homescreen is not initialized properly.\n"));
	ratio = (t_dpoint){(double)i_home->width / WIN_SIZE,
		(double)i_home->height / WIN_SIZE};
	pos.y = 0;
	while (pos.y < WIN_SIZE)
	{
		pos.x = 0;
		while (pos.x < WIN_SIZE)
		{
			tex = (t_point){pos.x * ratio.x, pos.y * ratio.y};
			color = get_pixel_color(*i_home, tex.x, tex.y);
			if ((int)color != ALPHA_ZERO)
				set_pixel(homescreen, pos.x, pos.y, color);
			pos.x++;
		}
		pos.y++;
	}
}
