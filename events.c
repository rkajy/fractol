#include "fractol.h"
#include <X11/keysym.h> // for XK_Escape, KeyPress, etc.

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_windows);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

int key_handler(int keycode, t_fractal *fractal)
{
    // debug: print keycode
    printf("Key pressed: %d\n", keycode);

    if (keycode == XK_Escape)
        close_handler(fractal);
    else if(keycode == XK_Left)
    {
        fractal->shift_x += 0.5;
    }
    else if (keycode == XK_Right)
    {
        fractal->shift_x -= 0.5;
    }
    else if(keycode == XK_Up)
    {
        fractal->shift_x -= 0.5;
    }
    else if(keycode == XK_Down)
    {

    }
    else if(keycode == XK_plus)
    {
        fractal->iterations_definition += 10;
    }
    else if(keycode == XK_minus)
    {
        fractal->iterations_definition -= 10;
    }

    // Re-render the fractal after handling the key event
    fractal_render(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    (void)button;
    (void)x;
    (void)y;
    (void)fractal;
    return (0);
}