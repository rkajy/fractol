#include "fractol.h"

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if(NULL == fractal->mlx_connection)
    {
        malloc_error();
        
    }
    fractal->mlx_windows = mlx_new_window(
        fractal->mlx_connection, mlx_ptr, WIDTH, size_x, HEIGHT, size_y , fractal->name);

        void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)
}