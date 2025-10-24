/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 00:19:29 by radandri          #+#    #+#             */
/*   Updated: 2025/10/25 00:52:46 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h" // mlx_init
# include <X11/X.h>        // KeyPress, KeyRelease, etc.
# include <errno.h>        // errno
# include <math.h>         // pow, sqrt,
# include <stdio.h>        // perror
# include <stdlib.h>       // malloc, free
# include <unistd.h>       // write

# define WIDTH 800
# define HEIGHT 800

# define MAX_ITER 100

typedef struct s_map_values
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}			t_values;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_value;
	int		max_iter;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	julia_re;
	double	julia_im;
	int		type;
}			t_fractal;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(t_values val);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handler(int keycode, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);

int			get_color(int iter, int max_iter);

int			julia(double zx, double zy, double c_re, double c_im);
int			mandelbrot(double x, double y);

#endif