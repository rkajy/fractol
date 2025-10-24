/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:43:19 by radandri          #+#    #+#             */
/*   Updated: 2025/10/25 00:52:04 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/keysym.h> // for XK_Escape, KeyPress, etc.

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		close_handler(fractal);
	else if (keycode == XK_Left)
		fractal->offset_x += (0.5 * fractal->zoom);
	else if (keycode == XK_Right)
		fractal->offset_x -= (0.5 * fractal->zoom);
	else if (keycode == XK_Up)
		fractal->offset_y -= (0.5 * fractal->zoom);
	else if (keycode == XK_Down)
		fractal->offset_y += (0.5 * fractal->zoom);
	else if (keycode == XK_plus)
		fractal->max_iter += 10;
	else if (keycode == XK_minus)
		fractal->max_iter -= 10;
	fractal_render(fractal);
	return (0);
}

static void	apply_zoom(t_fractal *f, double mx, double my, double factor)
{
	f->offset_x = mx + (f->offset_x - mx) * factor;
	f->offset_y = my + (f->offset_y - my) * factor;
	f->zoom *= factor;
}

/**
 * @brief Handles mouse events for zooming and centering in the fractal window.
 *
 * This function allows the user to interact with the fractal using the mouse:
 * - Scroll up (Button4): zooms IN, centered around the mouse position.
 * - Scroll down (Button5): zooms OUT, centered around the mouse position.
 * - Left click (Button1): recenters the fractal at the mouse position.
 *
 * The function first converts the mouse pixel position (x, y)
 * into complex plane coordinates (mouse_real, mouse_imag),
 * then adjusts the zoom and offsets accordingly.
 *
 * @param button The mouse button pressed (Button1, Button4, Button5, etc.).
 * @param x The x-coordinate of the mouse cursor in pixels.
 * @param y The y-coordinate of the mouse cursor in pixels.
 * @param fractal The structure containing fractal parameters (zoom, offset...).
 *
 * @return Always returns 0 (required by the MiniLibX event hook system).
 */
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = map((t_values){x, -2, +2, 0, WIDTH}) * fractal->zoom
		+ fractal->offset_x;
	mouse_imag = map((t_values){y, +2, -2, 0, HEIGHT}) * fractal->zoom
		+ fractal->offset_y;
	if (button == Button4)
	{
		apply_zoom(fractal, mouse_real, mouse_imag, 0.95);
	}
	else if (button == Button5)
	{
		apply_zoom(fractal, mouse_real, mouse_imag, 1.05);
	}
	else if (button == Button1)
	{
		fractal->offset_x = mouse_real;
		fractal->offset_y = mouse_imag;
	}
	fractal_render(fractal);
	return (0);
}
