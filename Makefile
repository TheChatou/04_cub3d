# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:50:30 by fcoullou          #+#    #+#              #
#    Updated: 2024/10/03 18:01:40 by fcoullou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##	PROGS NAMES	################################################################
NAME			= cub3D
NAME_BONUS		= cub3D_bonus

################################################################################
##	OPERATING SYSTEM	########################################################
OS = $(shell uname -s)

################################################################################
##	PATHS		################################################################
SRC_PATH		= ./src/
INC_PATH		= ./include/
OBJ_PATH		= ./obj/
LIBFT			= ./libft_v2/
ifeq ($(OS),Linux)
MLX_PATH		= ./mlx/
endif
ifeq ($(OS),Darwin)
MLX_PATH		 = ./mlx_os/
endif

################################################################################
##	FILES		################################################################
SRC				= $(addprefix $(SRC_PATH), \
											main.c) \
				$(addprefix $(SRC_PATH)anim/, \
											anim_00_LoadingScreen.c \
											anim_01_BoobyTrap.c) \
				$(addprefix $(SRC_PATH)flood_fill/, \
											flood_fill_utils.c \
											flood_fill.c) \
				$(addprefix $(SRC_PATH)free/, \
											free_00.c) \
				$(addprefix $(SRC_PATH)hooks/, \
											hook_actions_utils.c \
											hook_actions_00.c) \
				$(addprefix $(SRC_PATH)minimap/, \
											minimap_utils.c \
											minimap.c) \
				$(addprefix $(SRC_PATH)mouse/, \
											mouse_tracking.c) \
				$(addprefix $(SRC_PATH)moves/, \
											control_moves.c \
											life_management.c \
											move_forward.c \
											move_backward.c \
											move_right.c \
											move_left.c) \
				$(addprefix $(SRC_PATH)parsing/, \
											check_map_elements.c \
											check_map_symbs.c \
											control_rights.c \
											errors.c \
											free_functions.c \
											parsing_map_info.c \
											parsing_map1.c \
											stock_textures.c \
											stock_textures1.c \
											utils.c) \
				$(addprefix $(SRC_PATH)raycasting/, \
											init_00_ray_n_img.c \
											raycasting_00_set_n_cast.c \
											raycasting_01_calc.c \
											raycasting_02_draw.c \
											raycasting_03_utils.c) \
				$(addprefix $(SRC_PATH)start_n_init/, \
											init_00_player.c \
											init_01_game.c \
											game_00_Start.c \
											game_01_UserInterface.c) \
				$(addprefix $(SRC_PATH)utils/, \
											utils_00.c \
											utils_01.c \
											utils_02_load_imgs.c \
											utils_03_prints.c \
											utils_04_ending.c)

SRC_BONUS		= $(addprefix $(SRC_PATH), \
											main_bonus.c) \
				$(addprefix $(SRC_PATH)anim/, \
											anim_00_LoadingScreen.c \
											anim_01_BoobyTrap.c) \
				$(addprefix $(SRC_PATH)flood_fill/, \
											flood_fill_utils_bonus.c \
											flood_fill.c) \
				$(addprefix $(SRC_PATH)free/, \
											free_00.c) \
				$(addprefix $(SRC_PATH)hooks/, \
											hook_actions_bonus.c) \
				$(addprefix $(SRC_PATH)minimap/, \
											minimap_utils.c \
											minimap.c) \
				$(addprefix $(SRC_PATH)mouse/, \
											mouse_tracking.c) \
				$(addprefix $(SRC_PATH)moves/, \
											control_moves.c \
											life_management.c \
											crouch.c \
											move_forward.c \
											move_backward.c \
											move_right.c \
											move_left.c) \
				$(addprefix $(SRC_PATH)parsing/, \
											check_map_elements_bonus.c \
											check_map_symbs_bonus.c \
											control_rights.c \
											errors.c \
											free_functions.c \
											parsing_map_info.c \
											parsing_map1.c \
											stock_textures.c \
											stock_textures1.c \
											utils.c) \
				$(addprefix $(SRC_PATH)raycasting/, \
											init_00_ray_n_img.c \
											raycasting_00_set_n_cast_bonus.c \
											raycasting_01_calc_bonus.c \
											raycasting_02_draw_bonus.c \
											raycasting_03_utils.c) \
				$(addprefix $(SRC_PATH)start_n_init/, \
											init_00_player.c \
											init_01_game_bonus.c \
											game_00_Start_bonus.c \
											game_01_UserInterface.c) \
				$(addprefix $(SRC_PATH)utils/, \
											utils_00.c \
											utils_01.c \
											utils_02_load_imgs.c \
											utils_03_prints.c \
											utils_04_ending.c)
#------------------------------------------------------------------------------#
OBJ				= $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
OBJ_BONUS		= $(SRC_BONUS:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)
#------------------------------------------------------------------------------#
DEP 			= $(OBJ:%.o=%.d) $(OBJ_BONUS:%.o=%.d)
#------------------------------------------------------------------------------#
MLX				= $(MLX_PATH)libmlx_Linux.a
#------------------------------------------------------------------------------#
OUTPUT_LEAKS 	= valgrind-out.txt

################################################################################
##	COMPILER	################################################################
CFLAGS			= -Wall -Werror -Wextra -I./mlx -I./include -I./libft_v2/include -g3 -ftrapv
# -fsanitize=undefined -fsanitize=address
##	-Wall -Werror -Wextra : Active tous les avertissements (-Wall), traite les avertissements comme des erreurs (-Werror), et active des avertissements supplémentaires (-Wextra).
##  -I./mlx -I./include -I./libft_v2/include : Spécifie les répertoires où le compilateur doit chercher les fichiers d'en-tête (-I), pour MiniLibX, vos propres en-têtes, et ceux de libft.
##	-g3 : Génère des informations de débogage détaillées dans le fichier exécutable.
##	-ftrapv : Génère des erreurs d'exécution en cas de débordement arithmétique.
CPPFLAGS		= -MMD -c
##  -MMD : Génère des fichiers .d avec des dépendances pour chaque fichier source, utile pour la recompilation conditionnelle avec make.
##  -c : Compile les fichiers source sans les lier, générant des fichiers objet (.o).
LFLAGS 			= -L./libft_v2 -lft -lreadline -lm
# -fsanitize=undefined -static-libsan -fsanitize=address
##  -L./libft_v2 : Spécifie le répertoire où le compilateur doit chercher la bibliothèque libft lors de la liaison.
##  -lft : Lie votre programme avec la bibliothèque libft.
##  -lreadline : Lie votre programme avec la bibliothèque readline.
ifeq ($(OS),Linux)
MLXFLAGS = -lmlx -L./$(MLX_PATH) -lXext -lX11
endif
ifeq ($(OS),Darwin)
MLXFLAGS = -lmlx -L./$(MLX_PATH) -framework OpenGL -framework AppKit
endif
##  -lmlx : Lie votre programme avec la bibliothèque MiniLibX.
##  -L./mlx : Spécifie le répertoire où le compilateur doit chercher la bibliothèque MiniLibX lors de la liaison.
##  -lXext : Lie votre programme avec la bibliothèque Xext, qui fournit diverses extensions pour X11.
##  -lX11 : Lie votre programme avec la bibliothèque X11, nécessaire pour l'affichage graphique et la gestion des événements sous Linux.
##  -framework OpenGL -framework AppKit : Lie votre programme avec les frameworks OpenGL et AppKit, nécessaires pour l'affichage graphique sur macOS.
#------------------------------------------------------------------------------#
AR				= ar
CC				= cc
RM				= rm -f
CD				= cd
DIR_DUP			= mkdir -p $(@D)

################################################################################
##	+++++		################################################################
GREEN=\033[0;32m
RED=\033[0;31m
RESET=\033[0m
CLEAR_EOL=\033[K
#------------------------------------------------------------------------------#
VALCHECK=--leak-check=full
VALSHOW=--show-leak-kinds=all
VALFD=--track-fds=yes
VALIGNORE=--suppressions=valgrind_readline_leaks_ignore.txt
VALCHILD=--trace-children=yes

################################################################################
##	RULES		################################################################
all: $(NAME)

$(MLX):
	@ranlib $(MLX_PATH)libmlx.a
	
$(NAME): $(OBJ) $(MLX)
	@if [ ! -f $(LIBFT)/libft.a ]; then make -s -C $(LIBFT); fi
	@if [ ! -f $(MLX_PATH)/libmlx.a ]; then make -s -C $(MLX_PATH); fi
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS) $(MLXFLAGS)
	@printf "$(GREEN)[CREATED]$(RESET) : $(NAME)\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(DIR_DUP)
	@printf "$(GREEN)[COMPILATION]$(RESET) : $<$(CLEAR_EOL)\r"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< 
#------------------------------------------------------------------------------#
bonus: fclean $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(MLX)
	@if [ ! -f $(LIBFT)/libft.a ]; then make -s -C $(LIBFT); fi
	@if [ ! -f $(MLX_PATH)/libmlx.a ]; then make -s -C $(MLX_PATH); fi
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME) $(LFLAGS) $(MLXFLAGS)
	@printf "$(GREEN)[CREATED]$(RESET) : $(NAME)\n"
		
$(OBJ_PATH)%.o: $(BONUS_PATH)%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "CREATED $@\n"
#------------------------------------------------------------------------------#
clean:
	@make -s -C $(LIBFT) fclean
	@printf " "
	@for file in $(OBJ); do \
		printf "$(RED)[DELETE FILES]$(RESET) : $(CLEAR_EOL)$$file "; \
		sleep 0.01; \
		printf "\r"; \
	done && \
	printf "$(CLEAR_EOL)$(RED)[ALL FILES DELETED]$(RESET)\n" && \
	$(RM) -rf $(OBJ_PATH)
	@$(RM) -rf $(LIBFT_OBJ)
#------------------------------------------------------------------------------#
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@$(RM) -rf $(OBJ_PATH)
#------------------------------------------------------------------------------#
re: fclean all
#------------------------------------------------------------------------------#
test: all
	./$(NAME)
#------------------------------------------------------------------------------#
leaks: all
	valgrind $(VALIGNORE) $(VALSHOW) $(VALCHECK) ./$(NAME)
	@cat valgrind-out.txt
#------------------------------------------------------------------------------#
valgrind : all
	valgrind $(VALIGNORE) $(VALSHOW) $(VALCHECK) $(VALCHILD) $(VALFD) ./${NAME}
#------------------------------------------------------------------------------#
.PHONY: all bonus clean fclean re test leaks  
#------------------------------------------------------------------------------#

-include $(DEP)
