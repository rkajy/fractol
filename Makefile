# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 15:34:36 by radandri          #+#    #+#              #
#    Updated: 2025/10/24 15:49:47 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
MINILIBX_DIR = minilibx/
INCLUDES = -I . -I $(LIBFT_DIR) -I $(MINILIBX_DIR)

SRC = main.c \
		init.c \
		render.c \
		math_utils.c \
		events.c \
		color.c \
		julia.c \
		mandelbrot.c

OBJ= $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)libft.a
MINILIBX_LIB = $(MINILIBX_DIR)libmlx.a
LIBS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

all: $(MINILIBX_DIR) $(NAME) 

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX_LIB): $(MINILIBX_DIR)
	$(MAKE) -C $(MINILIBX_DIR)       

$(MINILIBX_DIR):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		echo "Cloning minilibx..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR); \
	else \
		echo "minilibx already present."; \
	fi
	
clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re