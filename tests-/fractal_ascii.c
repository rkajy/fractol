#include <stdio.h>
#include <math.h>

typedef struct s_complex {
    double re;
    double im;
} t_complex;

/**
 * Compute the square of a complex number.
 *
 * Calculates z * z for a complex number z = re + i*im using the formula:
 *   (re + i*im)^2 = (re*re - im*im) + i*(2*re*im)
 *
 * @param z  The complex value to square (type t_complex, with fields re and im).
 * @return   A t_complex containing the real and imaginary parts of z squared.
 *
 * Notes:
 * - Arithmetic is performed using the underlying real type of t_complex; no
 *   overflow or NaN checks are performed.
 * - This function is pure and has no side effects.
 */
t_complex square_complex(t_complex z)
{
    t_complex result;
    result.re = z.re * z.re - z.im * z.im;
    result.im = 2 * z.re * z.im;
    return result;
}

t_complex add_complex(t_complex a, t_complex b)
{
    t_complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

/**
 * Map a value from one numeric range to another using linear interpolation.
 *
 * Maps the input value `n`, assumed to lie in the source range [old_min, old_max],
 * to the corresponding value in the destination range [new_min, new_max] using
 * the formula:
 *
 *     new = (new_max - new_min) * (n - old_min) / (old_max - old_min) + new_min
 *
 * Parameters:
 *   n         - The value to be mapped.
 *   new_min   - Lower bound of the target range.
 *   new_max   - Upper bound of the target range.
 *   old_min   - Lower bound of the source range.
 *   old_max   - Upper bound of the source range.
 *
 * Returns:
 *   The linearly mapped value in the target range. If `n` is within [old_min, old_max],
 *   the result is within [new_min, new_max]. Values of `n` outside the source range
 *   are extrapolated accordingly.
 *
 * Preconditions / Notes:
 *   - The function requires old_max != old_min. If old_max equals old_min, the
 *     computation divides by zero and the result is undefined.
 *   - Works with double precision; no state is modified (pure function, thread-safe).
 *
 * Example:
 *   To convert a value from the range [0, 255] to [0.0, 1.0], call with
 *   old_min = 0, old_max = 255, new_min = 0.0, new_max = 1.0.
 */
double map(double n, double new_min, double new_max, double old_min, double old_max)
{
    return ((new_max - new_min) * (n - old_min) / (old_max - old_min) + new_min);
}

int main(void)
{
    int width = 80;
    int height = 40;
    int max_iter = 100;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // 1️⃣ Map écran → plan complexe
            double c_re = map(x, -2.0, 1.0, 0, width);
            double c_im = map(y, -1.0, 1.0, 0, height);

            t_complex z = {0, 0};
            t_complex c = {c_re, c_im};

            int iter = 0;

            // 2️⃣ Itération de z = z² + c
            while (z.re * z.re + z.im * z.im <= 4 && iter < max_iter)
            {
                z = add_complex(square_complex(z), c);
                iter++;
            }

            // 3️⃣ Affichage ASCII selon les itérations
            if (iter == max_iter)
                printf(".");
            else if (iter > max_iter / 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}