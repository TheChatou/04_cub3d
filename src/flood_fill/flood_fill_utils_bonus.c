/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:59:34 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/14 12:13:13 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	check_if_not_walls(char c)
{
	if (c == VOID || c == TOKEN || c == WEST
		|| c == EAST || c == SOUTH || c == NORTH
		|| c == LIFE)
		return (true);
	return (false);
}
