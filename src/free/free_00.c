/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:34:13 by chatou            #+#    #+#             */
/*   Updated: 2024/09/12 16:18:35 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	destroy_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_game(t_game *game)
{
	ft_free_all(game);
	if (game->win.win)
		mlx_destroy_window(game->mlx, game->win.win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	pthread_mutex_destroy(&game->mutex);
	ft_memset(game, 1, sizeof(t_game));
}

void	free_img(t_game *game, t_img *img)
{
	if (img->ptr && game->mlx)
	{
		mlx_destroy_image(game->mlx, img->ptr);
		img->ptr = NULL;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_intro(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		free_img(game, &game->i_intro[i]);
		i++;
	}
}

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
