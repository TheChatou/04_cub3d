/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_symbs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:21:19 by mamoulin          #+#    #+#             */
/*   Updated: 2024/10/11 10:57:30 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_check_symb(char c)
{
	if (c == ' ' || !ft_player_symb(c) || c == WALL
		|| c == VOID || c == '\n')
		return (0);
	return (1);
}

int	ft_player_symb(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	ft_check_inner_elements(char c)
{
	if (!ft_player_symb(c) || c == WALL || c == VOID
		|| c == DOOR || c == TOKEN || c == TRAP || c == LIFE)
		return (0);
	return (1);
}

int	ft_check_empty_spot(char c)
{
	if (!ft_player_symb(c) || c == WALL || c == VOID
		|| c == DOOR || c == TOKEN || c == TRAP || c == LIFE)
		return (0);
	return (1);
}
