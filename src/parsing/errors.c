/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:13:04 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/15 11:57:03 by mamoulin         ###   ########.fr       */
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
	exit(EXIT_FAILURE);
}

void	ft_error_map1(t_game *game, char *str, char *to_free)
{
	char	*line;

	free(to_free);
	ft_free_all(game);
	ft_printf("%s\n", str);
	line = get_next_line(game->map_fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(game->map_fd);
	}
	exit(EXIT_FAILURE);
}
