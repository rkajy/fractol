/* render_helpers.c */
#include "fractol.h"

static void compute_pixel_cords(int px, int py, t_fractal *f, double *out_re, double *out_im)
{
    /* map pixel -> plan complexe en tenant compte du zoom et offsets */
    double view_width = (4.0 / f->zoom);  /* exemple: zone initiale [-2,2] -> largeur 4 */
    double view_height = (4.0 / f->zoom); /* même hauteur pour garder aspect carré */

    double min_re = -2.0 / f->zoom + f->offset_x;
    double max_re = min_re + view_width;
    double min_im = -2.0 / f->zoom + f->offset_y;
    double max_im = min_im + view_height;

    *out_re = map_double((double)px, 0.0, (double)WIDTH, min_re, max_re);
    /* on inverse y pour que y=0 soit en haut */
    *out_im = map_double((double)py, 0.0, (double)HEIGHT, max_im, min_im);
}

void handle_pixel(int x, int y, t_fractal *f)
{
    double c_re;
    double c_im;
    double z_re;
    double z_im;
    int iter;
    int color;

    /* calcule les coordonnées complexes du pixel */
    compute_pixel_cords(x, y, f, &c_re, &c_im);

    if (f->type == MANDELBROT)
    {
        /* Mandelbrot: z0 = 0 ; c = point mappé */
        z_re = 0.0;
        z_im = 0.0;
        iter = mandelbrot_iter(c_re, c_im, f->max_iter);
    }
    else /* JULIA */
    {
        /* Julia: z0 = pixel ; c = constante fournie par l'utilisateur */
        z_re = c_re;
        z_im = c_im;
        iter = julia_iter(z_re, z_im, f->julia_re, f->julia_im, f->max_iter);
    }

    color = get_color(iter, f->max_iter);
    my_pixel_put(x, y, &f->img, color);
}
