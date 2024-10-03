/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crouch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:34:34 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/03 12:43:27 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	crouch(t_player *player)
{
	if (player->shrink == 0.9)
		player->shrink = 0.0;
	else
		player->shrink = 0.9;
	return ;
}
