/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:35:12 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/14 14:39:21 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include "libft.h"

////////////////////////////////////////////////////////////////////////////////
//	STRUCTS		////////////////////////////////////////////////////////////////
//	Structure pour représenter un point precis dans un espace 2D
typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

//	Structure pour représenter un point precis dans un espace 3D
typedef struct s_tri_point
{
	double	x;
	double	y;
	double	z;
}	t_tri_point;

// Structure pour représenter une couleur RGB
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

//	Structure pour les threads
typedef struct s_i_threads
{
	pthread_t	loading_th;
	pthread_t	raycast_th;
}	t_i_threads;

//  Structure pour les données du joueur
//  pos:       Position du joueur
//  dir:       Direction du joueur/knife
//  plane:     Le plan de la caméra du joueur, largeur du champ de vision
typedef struct s_player
{
	t_tri_point	pos;
	double		height;
	double		shrink;
	t_dpoint	dir;
	t_dpoint	plane;
	int			lifes;
	bool		token;
	double		speed;
}	t_player;

//  Structure pour les lignes de dessin des tokens et des pièges
typedef struct s_line
{
	t_dpoint	pos;
	double		dist;
	int			hit;
	t_point		draw_start;
	t_point		draw_end;
	int			line_height;
	int			line_width;
	t_dpoint	relative_pos;
	t_dpoint	transform;
	double		inv_det;
	int			screen_x;
}	t_line;

//  Structure pour les rayons du raycasting
//  dir:			Direction du rayon
//  map_pos:		Position actuelle das la carte
//  side_dist:		Distance latérale jusqu'au prochain mur
//  delta_dist:		Distance entre les murs en x ou y
//  perp_wall_dist:	Distance perpendiculaire au mur rencontré
//  step:			Direction du pas en x et y (1 ou -1)
//  hit:			Indicateur de collision avec un mur (0 ou 1)
//  side:			Cote du mur touché par le rayon (0 pour x, 1 pour y)
//  draw_start:		Position de départ du mur à dessiner
//  draw_end:		Position de fin du mur à dessiner
//  line_height:	Hauteur du mur à dessiner
//// PIXELS & TEXTURES calculs ////
//  pxl_step:		ratio pour trouver le pixel de la texture
//  texture_pos_y:	Position y de la texture
//  texture:		Position de la texture
typedef struct s_ray
{
	t_dpoint	dir;
	t_point		map_pos;
	t_dpoint	side_dist;
	t_dpoint	delta_dist;
	double		perp_wall_dist;
	t_point		step;
	int			token_hit;
	int			side;
	bool		is_door;
	int			hit;
	int			draw_start;
	int			draw_end;
	int			line_height;
	double		pxl_step;
	double		texture_pos_y;
	t_point		texture;
	t_line		token;
	t_line		lifes;
	t_line		btrap;
}	t_ray;

//	Structure pour les donnees d'image
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

//	Structure pour la carte
typedef struct s_map
{
	char	**map;
	size_t	map_h;
	size_t	map_w;
	char	*path;
	char	*path_wall_n;
	char	*path_wall_s;
	char	*path_wall_e;
	char	*path_wall_w;
	t_color	*floor;
	t_color	*ceiling;
	t_point	exit;
}	t_map;

typedef struct s_window
{
	void	*win;
	int		width;
	int		height;
}	t_window;

//	Structure pour la minimap
typedef struct t_mmap
{
	t_point		center;
	int			mmap_x;
	int			mmap_y;
	int			line_length;
	int			color_pxl;
}	t_mmap;

typedef struct s_game
{
	t_window		win;
	char			*map_file;
	int				map_fd;
	int				has_token;
	t_player		player;
	t_map			*map;
	t_ray			*ray;
	t_img			raycasted;
	t_img			home_screen;
	t_img			i_loading;
	t_img			i_home;
	t_img			i_flash;
	t_img			i_wall_n;
	t_img			i_wall_s;
	t_img			i_wall_e;
	t_img			i_wall_w;
	t_img			i_floor;
	t_img			i_ceiling;
	t_img			i_hands;
	t_img			i_heart;
	t_img			i_lifes;
	t_img			i_token;
	t_img			i_door;
	t_img			i_intro[4];
	t_img			i_btrap[4];
	t_img			i_exit[4];
	char			*p_intro[4];
	char			*p_btrap[4];
	char			*p_exit[4];
	t_i_threads		th;
	pthread_mutex_t	mutex;
	t_mmap			mmap;
	float			move_x;
	float			move_y;
	float			dist_x;
	float			dist_y;
	t_dpoint		potion_pos;
	int				level;
	bool			is_loading;
	bool			drinked;
	int				state;
	int				current_frame;
	long			last_frame_time;
	void			*mlx;
	bool			print;
	int				cub_info;
	int				nl;
	bool			rabbit;
}	t_game;

#endif