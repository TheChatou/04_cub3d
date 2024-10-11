/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:24:05 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/11 15:47:34 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_btrap(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free_img(game, &game->i_btrap[i]);
		i++;
	}
}

void	free_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free_img(game, &game->i_exit[i]);
		i++;
	}
}
