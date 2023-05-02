# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 16:22:03 by mgraefen          #+#    #+#              #
#    Updated: 2023/02/09 09:18:54 by mgraefen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf
CC 			= 	cc
CFLAGS 		=   -Wall -Wextra -Werror
MLXFLAGS 	= 	-lglfw -L "$(HOME)/homebrew/opt/glfw/lib"
SRC_DIR		= 	src
OBJ_DIR 	= 	obj
DIR_DUP 	=	mkdir -p $(@D)

SRC 		= main.c \
					draw.c \
					utils.c \
					camera.c \
					keys.c \
					mouse.c \
					rotation.c \
					map_reader.c

SRC 		:= $(SRC:%=$(SRC_DIR)/%)
OBJ 		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT 		= ./libft/libft.a
MLX42 		= ./MLX42/build/libmlx42.a

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $^ -o $@

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(LINK_FLAGS) $(OBJ) $(MLX42) $(LIBFT) -o $(NAME) $(MLXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@git submodule init Libft
	@git submodule update Libft
	@cd libft && make && make clean

$(MLX42):
	@git submodule init MLX42
	@git submodule update MLX42
	@cd MLX42 && cmake -B build && cmake --build build -j4

test:
	@echo $(MLX42)

clean:
	@rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

libclean:
	@rm -rf ./libft
	@rm -rf ./MLX42
re: fclean all

.PHONY: all clean fclean re
