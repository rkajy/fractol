#include "fractol.h"

void    handle_pixel(int x, int y, t_fractal *fractal)
{
    
}

void	fractal_render(t_fractal *fractal)
{
    // if (fractal == NULL)
    //     return ;
    // if (fractal->img.img_ptr && fractal->mlx_connection && fractal->mlx_windows)
    //     mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_windows,
    //         fractal->img.img_ptr, 0, 0);


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
