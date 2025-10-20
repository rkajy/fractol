/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 00:21:24 by radandri          #+#    #+#             */
/*   Updated: 2025/10/20 16:02:06 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)) || (4 == argc
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
        fractal.name = argv[1];
		if (4 == argc && !ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = atodouble(argv[2]);
			fractal.julia_y = atodouble(argv[3]);
		}
		fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
	
    }
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

// gcc *c -Lminilibx -lmlx -lX11 -lXext libft/libft.a -o fractol