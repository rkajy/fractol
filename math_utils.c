#include "fractol.h"

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

double	atodouble(char *s)
{
	long	int_part;
	long	frac_part;
	double	div;
	int		sign;

	int_part = 0;
	frac_part = 0;
	div = 1.0;
	sign = 1;
	while (ft_is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
		sign = (*s++ == '-') ? -1 : 1;
	while (*s >= '0' && *s <= '9')
		int_part = int_part * 10 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			frac_part = frac_part * 10 + (*s++ - '0');
			div *= 10.0;
		}
	}
	return (sign * (int_part + (frac_part / div)));
}


