/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:48:29 by radandri          #+#    #+#             */
/*   Updated: 2025/10/24 23:48:29 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double zx, double zy, double c_re, double c_im)
{
	double	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (zx * zx + zy * zy <= 4 && i < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + c_re;
		zy = 2 * zx * zy + c_im;
		zx = tmp;
		i++;
	}
	return (i);
}
