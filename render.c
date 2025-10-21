/* render.c */
#include "fractol.h"

/* Put a pixel in my image buffer */
void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = (unsigned int)color;
}

/*
** Map pixel coordinates (px,py) -> complex plane, taking zoom & offsets into account.
** We use base ranges:
**   re: [-2.0, 1.0]
**   im: [-1.5, 1.5]
*/
static void	compute_complex_coords(int px, int py, t_fractal *f, double *out_re, double *out_im)
{
	double base_min_re = -2.0;
	double base_max_re =  1.0;
	double base_min_im = -1.5;
	double base_max_im =  1.5;

	/* Apply zoom around center: we shrink range by zoom factor, then shift by offsets */
	double view_width = (base_max_re - base_min_re) / f->zoom;
	double view_height = (base_max_im - base_min_im) / f->zoom;

	double min_re = f->offset_x + ( (base_min_re + base_max_re) / 2.0 ) - view_width / 2.0;
	double max_re = min_re + view_width;
	double min_im = f->offset_y + ( (base_min_im + base_max_im) / 2.0 ) - view_height / 2.0;
	double max_im = min_im + view_height;

	/* map px in [0, WIDTH] -> [min_re, max_re] */
	*out_re = map_double((double)px, 0.0, (double)WIDTH, min_re, max_re);
	/* map py in [0, HEIGHT] -> [max_im, min_im] to invert Y (screen y grows downwards) */
	*out_im = map_double((double)py, 0.0, (double)HEIGHT, max_im, min_im);
}

/* Choose mandelbrot / julia iteration and draw pixel */
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	double	c_re;
	double	c_im;
	int		iter;
	int		color;

	compute_complex_coords(x, y, fractal, &c_re, &c_im);

	if (fractal->type == MANDELBROT)
	{
		/* Mandelbrot: z0 = 0 ; c = mapped point (c_re/c_im) */
		iter = mandelbrot_iter(c_re, c_im, fractal->max_iter);
	}
	else
	{
		/* Julia: z0 = mapped point ; c = constant (julia_re/julia_im) */
		iter = julia_iter(c_re, c_im, fractal->julia_re, fractal->julia_im,
				fractal->max_iter);
	}

	color = get_color(iter, fractal->max_iter);
	my_pixel_put(x, y, &fractal->img, color);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0, 0);
}
