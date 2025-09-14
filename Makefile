# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 15:34:36 by radandri          #+#    #+#              #
#    Updated: 2025/09/14 02:00:54 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -ffast-math -march=native -funroll-loops -mtune=native -O3 -mavx2 -mfma

LIBFT_DIR = libft/
MLX42_DIR = mlx42/
INCLUDES = -I include/ -I $(LIBFT_DIR) -I $(MLX42_DIR)include/

SRC = main.c
OBJ= $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)libft.a
MLX42_LIB = $(MLX42_DIR)build/libmlx42.a
LIBS = -L$(MLX42_DIR)build -lglfw -lGL -ldl -lm -lpthread

all: submodules $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX42_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42_LIB) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX42_LIB):
	cmake -B $(MLX42_DIR)build -S $(MLX42_DIR)
	cmake --build $(MLX42_DIR)build

submodules:
	@if [ ! -f "$(MLX42_DIR)/CMakeLists.txt" ]; then \
		echo "Submodule 'mlx42' is missing. Initializing..."; \
		git submodule update --init --recursive > /dev/null 2>&1 || { \
			echo "  Failed to fetch 'mlx42'. You may try:"; \
			echo "   git submodule add https://github.com/codam-coding-college/MLX42.git mlx42"; \
			exit 1; \
		}; \
	else \
		echo "Submodule 'mlx42' already present."; \
	fi
	
clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean submodules