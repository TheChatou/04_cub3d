/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_01_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:04:10 by mamoulin          #+#    #+#             */
/*   Updated: 2024/09/24 14:16:37 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	set_game(t_game *game, int level)
{
	game->mlx = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_putstr_fd("Error\nCouldn't initialize the mlx\n", 2), false);
	game->win.win = mlx_new_window(game->mlx, WIN_SIZE, WIN_SIZE, "Cub3D");
	if (!game->win.win)
		return (ft_putstr_fd("Error\nCouldn't create the window\n", 2), false);
	game->win.width = WIN_SIZE;
	game->win.height = WIN_SIZE;
	game->level = level;
	init_cam(&game->cam);
	init_img(&game->raycasted, WIN_SIZE);
	init_img(&game->home_screen, WIN_SIZE);
	init_img(&game->i_wall_n, TILE_SIZE);
	init_img(&game->i_wall_s, TILE_SIZE);
	init_img(&game->i_wall_e, TILE_SIZE);
	init_img(&game->i_wall_w, TILE_SIZE);
	init_img(&game->i_floor, TILE_SIZE);
	init_img(&game->i_ceiling, TILE_SIZE);
	init_img(&game->i_hands, TILE_SIZE);
	init_img(&game->i_heart, TILE_SIZE);
	init_img(&game->i_token, TILE_SIZE);
	init_img(&game->i_loaded, WIN_SIZE);
	return (true);
}

bool	init_game(char *av, t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (ft_putstr_fd("Error\nCouldn't allocate map memory\n", 2), false);
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		return (ft_putstr_fd("Error\nCouldn't allocate ray memory\n", 2), false);
	if (game->map)
		ft_memset(game->map, 0, sizeof(t_map));
	game->map_file = ft_strdup(av);
	ft_stock_map_tab(game->map_file, game);
	if (ft_check_map(game->map_file, game))
		return (false);
	game->map->size.y = game->map->map_h;
	game->map->size.x = game->map->map_w;
	game->has_token = 1;
	if (valid_path(game))
		return (false);
	if (pthread_mutex_init(&game->mutex, NULL) != 0)
		return (ft_putstr_fd("Error\nCouldn't initialize the mutex\n", 2), false);
	return (true);
}

void	init_cam(t_cam *cam)
{
	cam->rotation = (t_dpoint){0, 0};
	cam->sensitivity = 0.0005;
	cam->pitch = 0;
}

bool	init_ray(t_ray *ray)
{
	ft_memset(ray, 0, sizeof(t_ray));
	ft_memset(&ray->token, 0, sizeof(t_line));
	ft_memset(&ray->btrap, 0, sizeof(t_line));
	return (true);
}
