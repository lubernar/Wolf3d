# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubernar <lubernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 11:26:39 by lubernar          #+#    #+#              #
#    Updated: 2019/03/19 15:13:47 by lubernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d

CC = gcc

SRC_PATH = src

SRC_NAME = init_map.c initialize.c read_map.c ray.c wolf.c textures.c tools.c valid_map.c \
			player.c music.c get_next_line.c

OBJ_PATH = obj

CPPFLAGS = -Iincludes

LDFLAGS = -Llibft
LDLIBS = -lft

MLXFLAGS = -Lminilibx_macos
MLXLIBS = -lmlx

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
    RED=\033[1;31m
    GREEN=\033[1;32m
.SILENT:

all: $(NAME)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null 
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C minilibx_macos
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@ $(MLXFLAGS) $(MLXLIBS) -framework OpenGL -framework AppKit
	echo "$(GREEN)[✓] Wolf3D"

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx_macos clean
	rm -rf $(OBJ_PATH)
	echo "$(RED)[✓] Clean!"


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	echo "$(RED)[✓] Fclean!"

re: fclean all

.PHONY: all, clean, fclean, re
