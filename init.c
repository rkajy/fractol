#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problem with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4; // 2 ^ 2, my hypotenuse
	fractal->max_iter = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	// Zoom factor
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_windows, KeyPress, KeyPressMask, key_handler,
		fractal);
	mlx_hook(fractal->mlx_windows, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_windows, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
	mlx_hook(fractal->mlx_windows, MotionNotify, PointerMotionMask, julia_track,
		fractal);
}
void is_null_mlx_connection_checker(t_fractal *fractal)
{
    if (fractal->mlx_connection == NULL)
        malloc_error();
}

void is_null_mlx_windows_checker(t_fractal *fractal)
{
    if (fractal->mlx_windows == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
}

void is_null_img_ptr_checker(t_fractal *fractal)
{
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_windows);
        // mlx_ptr: win_ptr:
        mlx_destroy_display(fractal->mlx_connection);
        // mlx_ptr:
        free(fractal->mlx_connection);
        // ptr
        malloc_error();
    }
}

void is_null_img_pixels_ptr(t_fractal *fractal)
{
    if (fractal->img.pixels_ptr == NULL)
    {
        mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_windows);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
    is_null_mlx_connection_checker(fractal);
    fractal->mlx_windows = mlx_new_window(fractal->mlx_connection, // mlx_ptr:
											WIDTH,                   // size_x:
											HEIGHT,                  // size_y:
											fractal->name            // title
	);
    is_null_mlx_windows_checker(fractal);
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
    is_null_img_ptr_checker(fractal);
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_len,
			&fractal->img.endian);
    is_null_img_pixels_ptr(fractal);
	events_init(fractal);
	data_init(fractal);
}

