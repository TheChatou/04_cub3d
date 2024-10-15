/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_01_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:04:10 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/15 12:19:30 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

bool	set_game(t_game *game, char *av, int level)
{
	game->map_file = ft_strdup(av);
	if (!strcmp(game->map_file, LEVEL2_MAP))
		game->level = 2;
	else if (!strcmp(game->map_file, LEVEL1_MAP))
		game->level = 1;
	else
		game->level = level;
	if (ft_stock_map_tab(game->map_file, game)
		|| ft_check_map(game->map_file, game) || valid_path(game))
		return (false);
	if (pthread_mutex_init(&game->mutex, NULL) != 0)
		return (ft_putstr_fd("Error\nCouldn't initialize the mutex\n", 2), false);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_putstr_fd("Error\nCouldn't initialize the mlx\n", 2), false);
	set_win(&game->win, game->mlx);
	init_all_t_imgs(game);
	return (true);
}

bool	set_win(t_window *win, void *mlx_ptr)
{
	win->win = mlx_new_window(mlx_ptr, WIN_SIZE, WIN_SIZE, "Cub3D");
	if (!win->win)
		return (ft_putstr_fd("Error\nCouldn't create the window\n", 2), false);
	win->width = WIN_SIZE;
	win->height = WIN_SIZE;
	return (true);
}

bool	init_game(t_game *game)
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
	return (true);
}

bool	init_ray(t_ray *ray)
{
	ft_memset(ray, 0, sizeof(t_ray));
	ft_memset(&ray->token, 0, sizeof(t_line));
	ft_memset(&ray->btrap, 0, sizeof(t_line));
	return (true);
}

void	init_all_t_imgs(t_game *game)
{
	init_img(&game->raycasted, WIN_SIZE);
	init_img(&game->home_screen, WIN_SIZE);
	init_img(&game->i_loading, WIN_SIZE);
	init_img(&game->i_home, WIN_SIZE);
	init_img(&game->i_flash, TILE_SIZE);
	init_img(&game->i_wall_n, TILE_SIZE);
	init_img(&game->i_wall_s, TILE_SIZE);
	init_img(&game->i_wall_e, TILE_SIZE);
	init_img(&game->i_wall_w, TILE_SIZE);
	init_img(&game->i_floor, TILE_SIZE);
	init_img(&game->i_ceiling, TILE_SIZE);
	init_img(&game->i_hands, TILE_SIZE);
	init_img(&game->i_heart, TILE_SIZE);
	init_img(&game->i_lifes, TILE_SIZE);
	init_img(&game->i_token, TILE_SIZE);
	init_img(&game->i_door, TILE_SIZE);
	init_t_img_tab(game->i_intro, 100);
	init_t_img_tab(game->i_btrap, TILE_SIZE);
	init_t_img_tab(game->i_exit, TILE_SIZE);
}
