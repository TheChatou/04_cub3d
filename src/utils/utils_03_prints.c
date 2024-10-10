/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03_prints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:58:13 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/07 17:51:23 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	print_t_ray(t_ray *ray)
{
	printf("ray_dir: %f, %f\n", ray->dir.x, ray->dir.y);
	printf("delta_dist: %f, %f\n", ray->delta_dist.x, ray->delta_dist.y);
	printf("map_pos: %d, %d\n", ray->map_pos.x, ray->map_pos.y);
	printf("side_dist: %f, %f\n", ray->side_dist.x, ray->side_dist.y);
	printf("step: %d, %d\n", ray->step.x, ray->step.y);
	printf("side: %d\n", ray->side);
	printf("hit: %d\n", ray->hit);
	printf("perp_wall_dist: %f\n", ray->perp_wall_dist);
	printf("line_height: %d\n", ray->line_height);
	printf("draw_start: %d\n", ray->draw_start);
	printf("draw_end: %d\n\n", ray->draw_end);
}

void	print_t_line(t_line *line)
{
	printf("pos: %f, %f\n", line->pos.x, line->pos.y);
	printf("dist: %f\n", line->dist);
	printf("hit: %d\n", line->hit);
	printf("draw_start: %d, %d\n", line->draw_start.x, line->draw_start.y);
	printf("draw_end: %d, %d\n", line->draw_end.x, line->draw_end.y);
	printf("line_height: %d\n", line->line_height);
	printf("line_width: %d\n", line->line_width);
	printf("relative_pos: %f, %f\n", line->relative_pos.x, line->relative_pos.y);
	printf("transform: %f, %f\n", line->transform.x, line->transform.y);
	printf("inv_det: %f\n", line->inv_det);
	printf("screen_x: %d\n\n", line->screen_x);
}

void	print_map(t_map *map)
{
	size_t	i;

	i = 0;
	ft_printf("This is the map:\n");
	while (i < map->map_h)
	{
		ft_printf("%d: ", i);
		ft_printf("%s", map->map[i]);
		i++;
	}
}

int	ft_print_map_tab(t_game *game)
{
	size_t	i;

	i = 0;
	if (!game->map->map)
		return (0);
	while (i < game->map->map_h)
	{
		printf("%s", game->map->map[i]);
		i++;
	}
	printf("\n");
	printf("\n");
	return (0);
}

int	ft_print_map_info(t_game *game)
{
	if (game->map->path_wall_w)
		ft_printf("We wall path is : %s\n", game->map->path_wall_w);
	if (game->map->path_wall_n)
		ft_printf("No wall path is : %s\n", game->map->path_wall_n);
	if (game->map->path_wall_e)
		ft_printf("Ea wall path is : %s\n", game->map->path_wall_e);
	if (game->map->path_wall_s)
		ft_printf("So wall path is : %s\n", game->map->path_wall_s);
	if (game->map->floor)
	{
		ft_printf("floor rgb color is %d, %d, %d\n", game->map->floor->r,
			game->map->floor->g, game->map->floor->b);
	}
	if (game->map->ceiling)
	{
		ft_printf("ceiling rgb color is %d, %d, %d\n", game->map->ceiling->r,
			game->map->ceiling->g, game->map->ceiling->b);
	}
	return (0);
}
