#include "fractol.h"

// zx et zy correspondent au pixel courant
int julia(double zx, double zy, double c_re, double c_im, int max_iter)
{
    double tmp = 0;
    int i = 0;
    while (zx * zx + zy * zy <= 4 && i < max_iter )
    {
        tmp = zx * zx - zy * zy + c_re; // Re(z^2) + c_re
        zy = 2 * zx * zy + c_im; // Im(z^2) + c_im
        zx = tmp;
        i++;
    }
    return (i);
}