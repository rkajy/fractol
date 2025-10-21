#include "fractol.h"

// z = z^2 + c
int mandelbrot(double x, double y, int max_iter)
{
    double zx = 0.0;
    double zy = 0.0;
    int i = 0;
    double tmp = 0;

    while(zx * zx + zy *zy <= 4 && i < max_iter )
    {
        tmp = zx * zx - zy * zy + x;
        zy = 2 * zx * zy + y;
        zx = tmp;
        i++;
    }
    return (i);
}