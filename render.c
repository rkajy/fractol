#include "fractol.h"

// Put a pixel in my image buffer
static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;

}

// EASY TOGGLE BETWEEN MANDELBROT AND JULIA
static void mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if(!ft_strncmp(fractal->name, "mandelbrot", 10))
    {
        c->x = z->x;
        c->y = z->y;
    }
    else if(!ft_strncmp(fractal->name, "julia", 5))
    {
        // for julia, c is constant
        c->x = fractal->julia_x;
        c->y = fractal->julia_y;
    }
}

/*
 *
 * Mandelbrot
 * z = z^2 + c
 * z initially is (0,0)
 * c is the actual point
 * 
 * z = z^2 + constant -> z1 = c
 * 
 * Julia
 * ./fractol julia <real part> <imaginary part>
 * z = pixel_point + constant
 */
static  void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;

    // pixel coordinate x && y scaled to fit mandel needs
    z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

    mandel_vs_julia(&z, &c, fractal);

    // How many times you want to iterate z^2 + c to check if the pointer escaped?
    while(i < fractal->iterations_definition)
    {
        //actual z^2 + c
        // z = z^2 +c
        z = sum_complex(square_complex(z), c);

        // Is the value escaped???
        // if hypotenuse > 2, I assume the point has escaped
        if((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = map(i, BLACK, WHITE, 0, fractal->iterations_definition);
            my_pixel_put(x, y, &fractal->img, color);
            return;
        }
        ++i;
    }
    // We are in MANDELBROT given the iterations made
    my_pixel_put(x, y, &fractal->img, WHITE);

}

void	fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while(++x < WIDTH)
        {
            handle_pixel(x, y, fractal);
        }
    }
    mlx_put_image_to_window(
        fractal->mlx_connection,
        fractal->mlx_windows,
        fractal->img.img_ptr,
        0,
        0
    );
}
