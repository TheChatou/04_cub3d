/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:13:04 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/10 15:18:52 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_error_map(t_game *game, char *str)
{
	char	*line;

	ft_free_all(game);
	ft_printf("%s\n", str);
	line = get_next_line(game->map_fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(game->map_fd);
	}
	destroy_game(game);
}

void	ft_error_map1(char *str, t_game *game)
{
	char	*line;

	ft_printf("%s\n", str);
	line = get_next_line(game->map_fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(game->map_fd);
	}
	destroy_game(game);
}
