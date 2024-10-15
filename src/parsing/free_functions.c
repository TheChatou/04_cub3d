/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:15:00 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/14 16:33:20 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

void	ft_free_map_tab(t_game *game)
{
	size_t	i;

	i = 0;
	if (!game->map->map)
		return ;
	ft_free_tab(game->map->map);
}

void	ft_free_all_textures_colors(t_game *game)
{
	if (game->map->path_wall_n)
		free(game->map->path_wall_n);
	if (game->map->path_wall_s)
		free(game->map->path_wall_s);
	if (game->map->path_wall_e)
		free(game->map->path_wall_e);
	if (game->map->path_wall_w)
		free(game->map->path_wall_w);
	if (game->map->ceiling)
		free(game->map->ceiling);
	if (game->map->floor)
		free(game->map->floor);
}

void	destroy_imgs(t_game *game)
{
	free_img(game, &game->i_wall_n);
	free_img(game, &game->i_wall_s);
	free_img(game, &game->i_wall_e);
	free_img(game, &game->i_wall_w);
	free_img(game, &game->i_floor);
	free_img(game, &game->i_ceiling);
	free_img(game, &game->i_hands);
	free_img(game, &game->i_heart);
	free_img(game, &game->i_token);
	free_img(game, &game->i_door);
	free_img(game, &game->home_screen);
	free_img(game, &game->raycasted);
	free_img(game, &game->i_loading);
}

void	ft_free_all(t_game *game)
{
	free_intro(game);
	free_btrap(game);
	if (game->ray)
		free(game->ray);
	if (game->map_file)
		free(game->map_file);
	if (game->map->map)
		ft_free_map_tab(game);
	ft_free_all_textures_colors(game);
	destroy_imgs(game);
	if (game->map)
		free(game->map);
}
