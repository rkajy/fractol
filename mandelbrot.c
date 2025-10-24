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
