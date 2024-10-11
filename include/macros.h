/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:26:58 by fcoullou          #+#    #+#             */
/*   Updated: 2024/10/11 17:18:43 by fcoullou         ###   ########.fr       */
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
# define GAME_OVER		101
# define SENSITIVITY	0.00025
# define SHRINK			0.7

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
# define KEY_PRESS_MASK		0x01
# define KEY_RELEASE_MASK	0x02
# define MOUSE_MOVE_MASK	0x40
# define MOUSE_PRESS_MASK	0x04
# define MOUSE_RELEASE_MASK	0x08
# define NO_EVENT_MASK		0x00

// Directions
# define DIR_N_X 0
# define DIR_N_Y -1
# define DIR_S_X 0
# define DIR_S_Y 1
# define DIR_E_X 1
# define DIR_E_Y 0
# define DIR_W_X -1
# define DIR_W_Y 0

// Planes
# define PLANE_N_X 0.66
# define PLANE_N_Y 0
# define PLANE_S_X -0.66
# define PLANE_S_Y 0
# define PLANE_E_X 0
# define PLANE_E_Y 0.66
# define PLANE_W_X 0
# define PLANE_W_Y -0.66

//	Tout les chemins des assets
// Les maps
# define LEVEL1_MAP			"./maps/level1_bonus.cub"
# define LEVEL2_MAP			"./maps/level2_bonus.cub"
# define MANDATORY_MAP		"./maps/mandatory.cub"

// Les textures
# define FLOOR_PATH_1		"./assets/Alic3D/Floor_Grass.xpm"
# define FLOOR_PATH_2		"./assets/Alic3D/Floor2_lvl2.xpm"
# define DOOR_PATH_1		"./assets/Alic3D/Door_RabbitHole.xpm"
# define DOOR_LVL2_PATH_1	"./assets/Alic3D/Tiny_Door_lvl2_1.xpm"
# define DOOR_LVL2_PATH_2	"./assets/Alic3D/Tiny_Door_lvl2_2.xpm"
# define OPEN_DOOR_PATH_1	"./assets/Alic3D/Tiny_Open_Door_lvl2_1.xpm"
# define OPEN_DOOR_PATH_2	"./assets/Alic3D/Tiny_Open_Door_lvl2_2.xpm"
# define CEILING_PATH_1		"./assets/Alic3D/Ceiling_Clouds.xpm"
# define CEILING_PATH_2		"./assets/Alic3D/Ceiling6_lvl2.xpm"
# define HOMESCREEN_PATH_1	"./assets/Alic3D/HomeScreen_lvl1.xpm"
# define HOMESCREEN_PATH_2	"./assets/Alic3D/HomeScreen_lvl2.xpm"
# define ENDING_PATH		"./assets/Alic3D/HomeScreen_Ending.xpm"
# define HANDS_PATH_1		"./assets/Alic3D/Hands_Empty_lvl1.xpm"
# define HANDS_PATH_1_W		"./assets/Alic3D/Hands_Watch_lvl1.xpm"
# define HANDS_PATH_2		"./assets/Alic3D/Hands_Empty_lvl2.xpm"
# define HANDS_PATH_2_W		"./assets/Alic3D/Hands_Watch_lvl2.xpm"
# define HEART_PATH			"./assets/Alic3D/heart_25_17.xpm"
# define LIFES_PATH			"./assets/Alic3D/Life.xpm"
# define WATCH_PATH			"./assets/Alic3D/Token_Watch.xpm"
# define POTION_PATH		"./assets/Alic3D/Token_Table_Potion_2.xpm"
# define TABLE_PATH			"./assets/Alic3D/Token_Table_Shrinked.xpm"
# define LOADING_PATH		"./assets/Alic3D/loading.xpm"
# define WHITE_PATH			"./assets/Mandatory/white.xpm"
# define BLACK_PATH			"./assets/Mandatory/black.xpm"
# define RED_PATH			"./assets/Mandatory/red.xpm"
# define GREEN_PATH			"./assets/Mandatory/green.xpm"

//	Ecran de chargement
# define INTRO_1			"./assets/Alic3D/sablier_0.xpm"
# define INTRO_2			"./assets/Alic3D/sablier_1.xpm"
# define INTRO_3			"./assets/Alic3D/sablier_2.xpm"
# define INTRO_4			"./assets/Alic3D/sablier_3.xpm"

//	Pieges
# define BTRAP_L1_1			"./assets/Alic3D/BoobyTrap_lv1_0.xpm"
# define BTRAP_L1_2			"./assets/Alic3D/BoobyTrap_lv1_1.xpm"
# define BTRAP_L1_3			"./assets/Alic3D/BoobyTrap_lv1_2.xpm"
# define BTRAP_L1_4			"./assets/Alic3D/BoobyTrap_lv1_3.xpm"

# define ALPHA_ZERO -16777216

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

#endif