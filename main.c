/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 00:21:24 by radandri          #+#    #+#             */
/*   Updated: 2025/10/24 17:29:01 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_number(const char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	i = 0;
	has_digit = 0;
	has_dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			has_digit = 1;
		else if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else
			return (0);
		i++;
	}
	return (has_digit);
}

void	check_julia_parameters(char *argv[])
{
	if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
	{
		ft_putstr_fd("Error: Julia parameters must be numeric.\n", 2);
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)) || (4 == argc
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (4 == argc && !ft_strncmp(argv[1], "julia", 5))
		{
			check_julia_parameters(argv);
			fractal.julia_re = atodouble(argv[2]);
			fractal.julia_im = atodouble(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}


