/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 00:21:24 by radandri          #+#    #+#             */
/*   Updated: 2025/10/16 03:18:26 by radandri         ###   ########.fr       */
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
        //1)
		fractal_init(&fractal);
		//2)
        fractal_render(&fractal);
		//3)
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