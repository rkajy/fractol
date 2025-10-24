/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:26:12 by radandri          #+#    #+#             */
/*   Updated: 2025/10/25 01:22:13 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			iterations;
	int			color;

	iterations = 0;
	z.re = (map((t_values){x, -2, +2, 0, WIDTH}) * fractal->zoom)
		+ fractal->offset_x;
	z.im = (map((t_values){y, +2, -2, 0, HEIGHT}) * fractal->zoom)
		+ fractal->offset_y;
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		iterations = mandelbrot(z.re, z.im);
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		iterations = julia(z.re, z.im, fractal->julia_re, fractal->julia_im);
	}
	color = get_color(iterations, fractal->max_iter);
	my_pixel_put(x, y, &fractal->img, color);
}

/*
**
** Iterates over all pixels and maps (x, y) to
** complex coordinates (re, im).
**
** Computes the iteration count using the selected fractal
** and colors each pixel accordingly.
*/
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0,
		0);
}
