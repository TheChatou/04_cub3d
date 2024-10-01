/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:46:31 by chatou            #+#    #+#             */
/*   Updated: 2024/09/11 15:37:35 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_point	count_lines_n_length(char *path)
{
	int		fd;
	char	*line;
	t_point	size;

	line = NULL;
	size = (t_point){0, 0};
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ((t_point){0, 0});
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		size.x = ft_strlen(line);
		size.y++;
		free(line);
	}
	close(fd);
	return (size);
}

bool	no_moves(t_player *player)
{
	t_dpoint	new_pos;

	new_pos = (t_dpoint){player->pos.x, player->pos.y};
	while (player->pos.x == new_pos.x && player->pos.y == new_pos.y)
		return (true);
	return (false);
}

double	ft_floor(double x)
{
	if (x >= 0)
		return ((int)x);
	else
		return ((int)x - 1);
}

int	ft_truncate(float x)
{
	return ((int)x);
}

int	ft_strcmp_spe(char *str, char *dest)
{
	int		i;
	int		j;

	if (!str || !dest)
		return (1);
	i = 0;
	j = 0;
	if (dest[0] == '.')
		i++;
	if (dest[1] == '/')
		i++;
	while (str[j] && str[j] == dest[i])
	{
		j++;
		i++;
	}
	return ((unsigned int)str[j] - (unsigned int)dest[i]);
}
