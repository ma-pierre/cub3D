# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 18:31:12 by mapierre          #+#    #+#              #
#    Updated: 2024/07/12 17:40:34 by mapierre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D
BUILD_DIR := .build
SRC_DIR := srcs
INCLUDE_DIR := includes

SRCS := 	\
	parsing/check_data.c \
	parsing/check_extensions.c \
	parsing/check_map.c \
	parsing/floodfill.c \
	parsing/ft_clean.c \
	parsing/store_map.c\
	parsing/handle_colors.c \
	parsing/handle_floors_data.c \
	parsing/handle_textures.c \
	parsing/handle_walls_data.c \
	parsing/check_data_utils.c \
	parsing/main.c \
	parsing/map_utils.c \
	parsing/parsing_utils.c \
	parsing/start_parse.c \
	raycast/draw.c \
	raycast/end_game.c \
	raycast/image.c \
	raycast/keys.c \
	raycast/minimap.c \
	raycast/move_camera.c \
	raycast/move_init.c \
	raycast/move.c \
	raycast/raycast_init.c \
	raycast/raycasting.c \
	raycast/textures.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
CPPFLAGS := -I $(INCLUDE_DIR) -I ./inc -I ./libft -I ./mlx
RM := rm -f
MAKEFLAGS += --no-print-directory
LIBRARIES := -L libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C ./mlx
	@$(MAKE) -s -C ./libft
	@$(CC) $(OBJS) $(LIBRARIES) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(MAKE) -s -C libft fclean
	@$(MAKE) -s -C mlx clean
	@$(RM) -r $(BUILD_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
