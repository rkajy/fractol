/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:24:14 by radandri          #+#    #+#             */
/*   Updated: 2025/10/24 23:24:14 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**
** Iterates z = z² + c for each pixel of the complex plane.
** Here, c = pixel coordinate, and z starts at 0.
**
** Formula:
**    Re(zₙ₊₁) = Re(zₙ)² - Im(zₙ)² + Re(c)
**    Im(zₙ₊₁) = 2 * Re(zₙ) * Im(zₙ) + Im(c)
**
** where z starts at (0, 0) and c = (x, y) is the pixel point.
**
** Iterates:
**     zₙ₊₁ = zₙ² + c
** until |z|² > 4 or MAX_ITER is reached.
** Diverges when |z|² > 4 or max iteration reached.
*/
int	mandelbrot(double x, double y)
{
	double	zx;
	double	zy;
	int		i;
	double	tmp;

	zx = 0.0;
	zy = 0.0;
	i = 0;
	tmp = 0.0;
	while (zx * zx + zy * zy <= 4 && i < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + x;
		zy = 2 * zx * zy + y;
		zx = tmp;
		i++;
	}
	return (i);
}
