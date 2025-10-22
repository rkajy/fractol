#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problem with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_sq = 4;
	fractal->max_iter = 200;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->zoom = 1.0;
    fractal->julia_re = -0.7;
    fractal->julia_im = 0.27015;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win, KeyPress, KeyPressMask, key_handler,
		fractal);
	mlx_hook(fractal->win, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
	mlx_hook(fractal->win, MotionNotify, PointerMotionMask, julia_track,
		fractal);
}

void is_null_checker(t_fractal *fractal)
{
    if (fractal->mlx == NULL)
        malloc_error();
    else if (fractal->win == NULL)
    {
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        malloc_error();
    }
    else if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        malloc_error();
    }
    else if (fractal->img.pixels_ptr == NULL)
    {
        mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        malloc_error();
    }
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
    is_null_checker(fractal);
    fractal->win = mlx_new_window(fractal->mlx,
											WIDTH,
											HEIGHT,
											fractal->name
	);
    is_null_checker(fractal);
    fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH,
			HEIGHT);
    is_null_checker(fractal);
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_len,
			&fractal->img.endian);
    is_null_checker(fractal);
	events_init(fractal);
	data_init(fractal);
}

