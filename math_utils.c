#include "fractol.h"

double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    (void)old_max;
    return (new_max - new_min) * (unscaled_num - old_min);
}

/*
 * [0..799] -> [-2..+2]
 *
*/
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}
// sum complex is fairly easy is vector addition
t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;

    result.re = z1.re + z2.re;
    result.im = z1.im + z2.im;
    return result;
}

//square is trickier
// real = (x^2 - y^2)
// imaginary = 2*x*y
t_complex square_complex(t_complex z)
{
    t_complex result;

    result.re = (z.re * z.re) - (z.im * z.im);
    result.im = (2 * z.re * z.im);
    return result;
}

