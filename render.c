#include "fractol.h"

// Put a pixel in my image buffer
static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;

}
/*
 *
 *mandelbrot
 * z = z^2 + c
 * z initially is (0,0)
 * c is the actual point
 */
static  void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;
    // 1er iteration
    z.x = 0.0;
    z.y = 0.0;

    // pixel coordinate x && y scaled to fit mandel needs
    c.x = map(x, -2, +2, 0, WIDTH);
    c.y = map(x, +2, -2, 0, HEIGHT);

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
    my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);

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
    
}
