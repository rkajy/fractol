#include "fractol.h"

static void malloc_error(void)
{
    perror("Problem with malloc");
    exit(EXIT_FAILURE);
}

void data_init(t_fractal *fractal)
{
    fractal->escape_value = 4; // 2 ^ 2, my hypotenuse
    fractal->iterations_definition = 42;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
}

static void events_init(t_fractal *fractal)
{
    mlx_hook(
        fractal->mlx_windows,
        KeyPress,
        KeyPressMask,
        key_handler,
        fractal
    );
    mlx_hook(
        fractal->mlx_windows,
        ButtonPress,
        ButtonPressMask,
        mouse_handler,
        fractal
    );
    mlx_hook(
        fractal->mlx_windows,
        DestroyNotify,
        StructureNotifyMask,
        close_handler,
        fractal
    );
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if(NULL == fractal->mlx_connection)
        malloc_error();
    fractal->mlx_windows = mlx_new_window(
        fractal->mlx_connection, // mlx_ptr:
        WIDTH, //size_x:
        HEIGHT, //size_y:
        fractal->name //title
    );

    if(NULL == fractal->mlx_windows)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if(NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_windows); // mlx_ptr: win_ptr:
        mlx_destroy_display(fractal->mlx_connection); // mlx_ptr:
        free(fractal->mlx_connection); //ptr
        malloc_error();
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
    &fractal->img.bits_per_pixel,
    &fractal->img.line_len,
    &fractal->img.endian
    );
    events_init(fractal);
    data_init(fractal);
}
