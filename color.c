/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:28:22 by radandri          #+#    #+#             */
/*   Updated: 2025/10/25 00:28:22 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Combine les trois composantes rouge, vert et bleu
** dans un seul entier de type 0xRRGGBB que MiniLibX comprend.
*/
int	create_trgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

/*
**
** Maps iteration count to a gradient color.
**
** Points that diverge slowly get warmer tones.
** Points that never diverge are colored black.
*/
int	get_color(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max_iter)
		return (0x000000);
	t = (double)i / max_iter;
	t = sqrt(t);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (create_trgb(r, g, b));
}
