/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_04_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:25:21 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/10 13:41:19 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//	Calcule la distance entre le joueur et le token
void	calc_ray_token(t_game *game, t_player *player, t_line *tk)
{
	double	det;

	det = 0;
	if (tk->hit)
	{
		calc_ray_token_line(game, player, tk);
		det = (player->plane.x * player->dir.y)
			- (player->dir.x * player->plane.y);
		if (det == 0)
			return (ft_putstr_fd("Error: invalid transformation.\n",
					STDERR_FILENO));
		tk->inv_det = 1.0 / det;
		tk->transform.x = tk->inv_det * (player->dir.y * tk->relative_pos.x
				- player->dir.x * tk->relative_pos.y);
		tk->transform.y = tk->inv_det * (-player->plane.y * tk->relative_pos.x
				+ player->plane.x * tk->relative_pos.y);
		if (tk->transform.y == 0)
			return (ft_putstr_fd("Error: invalid transformation.\n",
					STDERR_FILENO));
		tk->screen_x = (int)((WIN_SIZE / 2)
				* (1 + tk->transform.x / tk->transform.y));
		tk->draw_start.x = tk->screen_x - tk->line_width / 2;
		tk->draw_end.x = tk->screen_x + tk->line_width / 2;
	}
}

void	calc_ray_token_line(t_game *game, t_player *player, t_line *tk)
{
	tk->dist = sqrt(pow(tk->pos.x - player->pos.x, 2)
			+ pow(tk->pos.y - player->pos.y, 2));
	if (game->level == 2 && tk->dist < 0.2 && !game->drinked)
		game->drinked = true;
	tk->line_height = (int)(WIN_SIZE / tk->dist);
	tk->line_width = (int)(WIN_SIZE / tk->dist);
	tk->draw_start.y = -tk->line_height / 2 + WIN_CENTER
		- (WIN_CENTER * player->shrink / tk->dist);
	tk->draw_end.y = tk->line_height / 2 + WIN_CENTER
		- (WIN_CENTER * player->shrink / tk->dist);
	tk->relative_pos.x = tk->pos.x - player->pos.x;
	tk->relative_pos.y = tk->pos.y - player->pos.y;
}

void	draw_lifes_tex(t_game *game, t_img *i_lifes, t_img *img,
						t_point pxl_pos)
{
	unsigned int	color;
	t_dpoint		relative_pos;

	relative_pos.y = (double)(pxl_pos.y - game->ray->lifes.draw_start.y)
		/ game->ray->lifes.line_height;
	relative_pos.x = (double)(pxl_pos.x - game->ray->lifes.draw_start.x)
		/ game->ray->lifes.line_width;
	if (relative_pos.x < 0)
		relative_pos.x = 0;
	else if (relative_pos.x > 1)
		relative_pos.x = 1;
	game->ray->texture.y = (int)(relative_pos.y
			* i_lifes->height) % i_lifes->height;
	game->ray->texture.x = (int)(relative_pos.x
			* i_lifes->width) % i_lifes->width;
	color = get_pixel_color(*i_lifes, game->ray->texture.x,
			game->ray->texture.y);
	if ((int)color != ALPHA_ZERO)
		set_pixel(img, pxl_pos.x, pxl_pos.y, color);
}

void	draw_token_tex(t_game *game, t_img *i_token,
							t_img *img, t_point pxl_pos)
{
	unsigned int	color;
	t_dpoint		relative_pos;

	relative_pos.y = (double)(pxl_pos.y - game->ray->token.draw_start.y)
		/ game->ray->token.line_height;
	relative_pos.x = (double)(pxl_pos.x - game->ray->token.draw_start.x)
		/ game->ray->token.line_width;
	if (relative_pos.x < 0)
		relative_pos.x = 0;
	else if (relative_pos.x > 1)
		relative_pos.x = 1;
	game->ray->texture.y = (int)(relative_pos.y
			* i_token->height) % i_token->height;
	game->ray->texture.x = (int)(relative_pos.x
			* i_token->width) % i_token->width;
	color = get_pixel_color(*i_token, game->ray->texture.x,
			game->ray->texture.y);
	if ((int)color != ALPHA_ZERO)
		set_pixel(img, pxl_pos.x, pxl_pos.y, color);
}

void	draw_booby_trap(t_game *game, t_img *trap, t_img img, t_point pxl_pos)
{
	unsigned int	color;
	t_line			*btrap;

	btrap = &game->ray->btrap;
	btrap->relative_pos.y = (double)(pxl_pos.y - btrap->draw_start.y)
		/ btrap->line_height;
	btrap->relative_pos.x = (double)(pxl_pos.x - btrap->draw_start.x)
		/ btrap->line_width;
	if (btrap->relative_pos.x < 0)
		return ;
	else if (btrap->relative_pos.x > 1)
		return ;
	game->ray->texture.y = (int)(btrap->relative_pos.y * trap->height)
		% trap->height;
	game->ray->texture.x = (int)(btrap->relative_pos.x * trap->width)
		% trap->width;
	color = get_pixel_color(*trap, game->ray->texture.x, game->ray->texture.y);
	if ((int)color != ALPHA_ZERO)
		set_pixel(&img, pxl_pos.x, pxl_pos.y, color);
}
