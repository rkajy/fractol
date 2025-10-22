/* maths_utils.c */
#include "fractol.h"

double map_double(double val, double old_min, double old_max, double new_min, double new_max)
{
    double t;
    if (old_max == old_min)
        return new_min;
    t = (val - old_min) / (old_max - old_min);
    return new_min + t * (new_max - new_min);
}

/* complex helpers (tu as déjà) */
t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;
    result.re = z1.re + z2.re;
    result.im = z1.im + z2.im;
    return result;
}

t_complex square_complex(t_complex z)
{
    t_complex result;
    result.re = (z.re * z.re) - (z.im * z.im);
    result.im = (2 * z.re * z.im);
    return result;
}
double atodouble(char *s)
{
    long integer_part = 0;
    long fractional_part = 0;
    double pow;
    int sign = 1;

    pow = 1.0;
    while(ft_is_space(*s))
        s++;
    while(*s == '+' || *s == '-')
    {
        if(*s == '-')
            sign *= -1;
        s++;
    }
    while(*s >= '0' && *s <= '9')
    {
        integer_part = (integer_part * 10) + (*s - '0');
        s++;
    }
    if(*s == '.')
    {
        s++;
        while(*s >= '0' && *s <= '9')
        {
            fractional_part = (fractional_part * 10) + (*s - '0');
            pow *= 10;
            s++;
        }
    }
    return (double)(integer_part * sign) + (double)(fractional_part * sign) / pow;
}
