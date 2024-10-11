/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:17:45 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/11 17:25:40 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

unsigned int	t_color_to_uint(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

// Extraire les composantes RGBA du pixel
// Calculer les différences avec la couleur cible
// Appliquer le pourcentage
// Recomposer la couleur ajustée
unsigned int	apply_gradient_shader(unsigned int pixel, double percent,
															SDL_Color target)
{
	SDL_Color		color;
	SDL_Color		delta;
	unsigned int	new_pixel;

	color.r = (int)(pixel >> 24) & 0xFF;
	color.g = (int)(pixel >> 16) & 0xFF;
	color.b = (int)(pixel >> 8) & 0xFF;
	color.a = (int)(pixel) & 0xFF;
	delta.r = target.r - color.r;
	delta.g = target.g - color.g;
	delta.b = target.b - color.b;
	delta.a = target.a - color.a;
	color.r += (int)((double)delta.r * percent);
	color.g += (int)((double)delta.g * percent);
	color.b += (int)((double)delta.b * percent);
	color.a += (int)((double)delta.a * percent);
	new_pixel = ((color.r & 0xFF) << 24) | ((color.g & 0xFF) << 16)
		| ((color.b & 0xFF) << 8) | (color.a & 0xFF);
	return (new_pixel);
}

long	get_current_time_ms(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

void	init_t_img_tab(t_img *img, int size)
{
	int		i;

	i = 0;
	while (i++ < 4)
	{
		init_img(&img[i], size);
		i++;
	}
}
