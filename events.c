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
        fractal->shift_x += (0.5 * fractal->zoom);
    }
    else if (keycode == XK_Right)
    {
        fractal->shift_x -= (0.5 * fractal->zoom);
    }
    else if(keycode == XK_Up)
    {
        fractal->shift_y -= (0.5 * fractal->zoom);
    }
    else if(keycode == XK_Down)
    {
        fractal->shift_y += (0.5 * fractal->zoom);
    }
    else if(keycode == XK_plus)
    {
        fractal->max_iter += 10;
    }
    else if(keycode == XK_minus)
    {
        fractal->max_iter -= 10;
    }

    // Re-render the fractal after handling the key event
    fractal_render(fractal);
    return (0);
}

// int (*f)(int button, int x, int y, void *param)
int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    // Convert mouse coordinates to complex plane coordinates
    double mouse_real = map(x, -2, +2, 0, WIDTH) * fractal->zoom + fractal->shift_x;
    double mouse_imag = map(y, +2, -2, 0, HEIGHT) * fractal->zoom + fractal->shift_y;

    //Zoom in (scroll up)
    if(button == Button4)
    {
        // Zoom towards the mouse cursor
        fractal->shift_x = mouse_real + (fractal->shift_x - mouse_real) * 0.95;
        fractal->shift_y = mouse_imag + (fractal->shift_y - mouse_imag) * 0.95;
        fractal->zoom *= 0.95;
    }
    //Zoom out (scroll down)
    else if(button == Button5)
    {
        // Zoom away from the mouse cursor
        fractal->shift_x = mouse_real + (fractal->shift_x - mouse_real) * 1.05;
        fractal->shift_y = mouse_imag + (fractal->shift_y - mouse_imag) * 1.05;
        fractal->zoom *= 1.05;
    }
    // Left click - center on mouse position
    else if(button == Button1)
    {
        fractal->shift_x = mouse_real;
        fractal->shift_y = mouse_imag;
    }

    // Re-render the fractal after handling the mouse event
    fractal_render(fractal);

    return (0);
}

// track the mouse to change julia parameters dynamically
int julia_track(int x, int y, t_fractal *fractal)
{
    if(!ft_strncmp(fractal->name, "julia", 5))
    {
        fractal->julia_x = map(x, -2, +2, 0, WIDTH) * fractal->zoom + fractal->shift_x;
        fractal->julia_y = map(y, +2, -2, 0, HEIGHT) * fractal->zoom + fractal->shift_y;
        fractal_render(fractal);
    }
    return (0);
}
