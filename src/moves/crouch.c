/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crouch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:34:34 by fcoullou          #+#    #+#             */
/*   Updated: 2024/09/25 18:12:48 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	crouch(t_player *player)
{
	if (player->view_height == 0.05)
		player->view_height = 1.0;
	else
		player->view_height = 0.05;
	return ;
}
