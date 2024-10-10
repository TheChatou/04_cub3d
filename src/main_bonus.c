/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:05:43 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/10 13:25:11 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	launch_levels(t_game *game, char *level, int i)
{
	if (!launch(game, level, i))
		return (destroy_game(game), 1);
	set_hooks(game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_game	game;
	int		i;

	if (argc < 2)
		return (ft_putstr_fd("Error\nYou need a map\n", STDERR_FILENO), 1);
	if (!envp)
		return (0);
	i = 0;
	while (argv[++i])
		launch_levels(&game, argv[i], i);
	return (0);
}
