#include <stdio.h>
#include <math.h>

typedef struct s_complex
{
    double re;
    double im;
} t_complex;

// Fonction pour calculer z^2 + c
t_complex iterate(t_complex z, t_complex c)
{
    t_complex result;
    result.re = z.re * z.re - z.im * z.im + c.re;
    result.im = 2 * z.re * z.im + c.im;
    return result;
}

int main(void)
{
    t_complex z = {0.0, 0.0};       // z0 = 0
    t_complex c = {1.0, 1.0};      // point du plan complexe
    int max_iter = 20000;

    printf("Simulation Mandelbrot pour c = %f + %fi\n\n", c.re, c.im);
    for (int i = 0; i < max_iter; i++)
    {
        double module = sqrt(z.re * z.re + z.im * z.im);
        printf("It %2d : z = %+.6f %+.6fi  |z| = %.6f\n", i, z.re, z.im, module);
        // if (module > 2)
        // {
        //     printf("→ Diverge à l’itération %d\n", i);
        //     break;
        // }
        z = iterate(z, c);
    }
    return 0;
}