/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:26:58 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/03 18:21:55 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

//	Tout les elements de la map
# define WALL			'1'
# define VOID			'0'
# define PLAYER			'P'
# define NORTH			'N'
# define SOUTH			'S'
# define EAST			'E'
# define WEST			'W'
# define DOOR			'D'
# define TOKEN			'T'
# define TRAP			'B'
# define LIFE			'L'

//	Etat du jeu
# define LOADING		99
# define GAME_LOOP		100

//	Orientations
# define N_SIDE 0
# define S_SIDE 1
# define W_SIDE 2
# define E_SIDE 3
# define DOOR_SIDE 4

//	Quelques tailles
# define WIN_SIZE		800
# define WIN_CENTER		400
# define TILE_SIZE		256

//	MINIMAP, y a des define similaires apres
# define WALL_COLOR 	0x000000
# define EMPTY_COLOR 	0xFFFFFF
# define PLAYER_COLOR 	0xFF0000
# define TOKEN_COLOR 	0xFFD700
# define EXIT_COLOR 	0x00FF00
# define MMAP_WIDTH		200
# define MMAP_HEIGHT	200
# define SCALE_FACTOR	10
# define MMAP_OFFSET_X	20
# define MMAP_OFFSET_Y	20

//	Evénements
# define KEY_PRESS_EVENT		2
# define KEY_RELEASE_EVENT		3
# define MOUSE_MOVE_EVENT		6
# define MOUSE_PRESS_EVENT		4
# define MOUSE_RELEASE_EVENT	5
# define WIN_CLOSE_EVENT		17

//	Masques d'événements
# define KEY_PRESS_MASK		1L<<0
# define KEY_RELEASE_MASK	1L<<1
# define MOUSE_MOVE_MASK	1L<<6
# define MOUSE_PRESS_MASK	1L<<2
# define MOUSE_RELEASE_MASK	1L<<3
# define NO_EVENT_MASK		0

//	Macros des Directions et des Plans
# define DIR_N		(t_dpoint){0, -1}
# define DIR_S		(t_dpoint){0, 1}
# define DIR_E		(t_dpoint){1, 0}
# define DIR_W		(t_dpoint){-1, 0}
# define PLANE_N	(t_dpoint){0.66, 0}
# define PLANE_S	(t_dpoint){-0.66, 0}
# define PLANE_E	(t_dpoint){0, 0.66}
# define PLANE_W	(t_dpoint){0, -0.66}

//	Tout les chemins des assets
# define LEVEL1_MAP			"./maps/level1_bonus.cub"
# define LEVEL2_MAP			"./maps/level2_bonus.cub"
# define MANDATORY_MAP		"./maps/mandatory.cub"

# define FLOOR_PATH_1		"./assets/Alic3D/Floor_Grass.xpm"
# define FLOOR_PATH_2		"./assets/Alic3D/Floor_lvl2.xpm"
# define DOOR_PATH_1		"./assets/Alic3D/Door_RabbitHole.xpm"
# define DOOR_PATH_2		"./assets/Alic3D/Door_RabbitHole.xpm"
# define CEILING_PATH_1		"./assets/Alic3D/Ceiling_Clouds.xpm"
# define CEILING_PATH_2		"./assets/Alic3D/Ceiling_Simple_lv2.xpm"
# define HOMESCREEN_PATH_1	"./assets/Alic3D/HomeScreen_lvl1.xpm"
# define HOMESCREEN_PATH_2	"./assets/Alic3D/HomeScreen_lvl2.xpm"
# define HANDS_PATH_1		"./assets/Alic3D/Hands_Empty_lvl1.xpm"
# define HANDS_PATH_1_W		"./assets/Alic3D/Hands_Watch_lvl1.xpm"
# define HANDS_PATH_2		"./assets/Alic3D/Hands_Empty_lvl2.xpm"
# define HANDS_PATH_2_W		"./assets/Alic3D/Hands_Watch_lvl2.xpm"
# define HEART_PATH			"./assets/Alic3D/heart_25_17.xpm"
# define WATCH_PATH			"./assets/Alic3D/Token_Watch.xpm"
# define POTION_PATH		"./assets/Alic3D/Token_Potion.xpm"
# define LOADING_PATH		"./assets/Alic3D/loading.xpm"

//	Loading screen
# define INTRO_1			"./assets/Alic3D/sablier_0.xpm"
# define INTRO_2			"./assets/Alic3D/sablier_1.xpm"
# define INTRO_3			"./assets/Alic3D/sablier_2.xpm"
# define INTRO_4			"./assets/Alic3D/sablier_3.xpm"

//	Booby trap
# define BTRAP_L1_1			"./assets/Alic3D/BoobyTrap_lv1_0.xpm"
# define BTRAP_L1_2			"./assets/Alic3D/BoobyTrap_lv1_1.xpm"
# define BTRAP_L1_3			"./assets/Alic3D/BoobyTrap_lv1_2.xpm"
# define BTRAP_L1_4			"./assets/Alic3D/BoobyTrap_lv1_3.xpm"

# define ALPHA_ZERO -16777216

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

#endif