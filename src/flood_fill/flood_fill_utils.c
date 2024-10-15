/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:53:33 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/14 12:12:01 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	check_if_not_walls(char c)
{
	if (c == VOID || c == WEST || c == TOKEN
		|| c == EAST || c == SOUTH || c == NORTH)
		return (true);
	return (false);
}
