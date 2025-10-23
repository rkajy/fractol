#include "fractol.h"
#include <X11/keysym.h> // for XK_Escape, KeyPress, etc.

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx, fractal->win);
    mlx_destroy_display(fractal->mlx);
    free(fractal->mlx);
    exit(EXIT_SUCCESS);
}

int key_handler(int keycode, t_fractal *fractal)
{
    if (keycode == XK_Escape)
        close_handler(fractal);
    else if(keycode == XK_Left)
    {
        fractal->offset_x += (0.5 * fractal->zoom);
    }
    else if (keycode == XK_Right)
    {
        fractal->offset_x -= (0.5 * fractal->zoom);
    }
    else if(keycode == XK_Up)
    {
        fractal->offset_y -= (0.5 * fractal->zoom);
    }
    else if(keycode == XK_Down)
    {
        fractal->offset_y += (0.5 * fractal->zoom);
    }
    else if(keycode == XK_plus)
        fractal->max_iter += 10;
    else if(keycode == XK_minus)
        fractal->max_iter -= 10;
    fractal_render(fractal);
    return (0);
}

void	compute_complex_coords(int px, int py, t_fractal *f, double *out_re, double *out_im)
{
	double	re_min = -2.0;
	double	re_max = 2.0;
	double	im_min = -2.0;
	double	im_max = 2.0;

	*out_re = re_min + (px / (double)WIDTH) * (re_max - re_min);
	*out_im = im_max - (py / (double)HEIGHT) * (im_max - im_min);

	// Appliquer zoom et décalage
	*out_re = *out_re * f->zoom + f->offset_x;
	*out_im = *out_im * f->zoom + f->offset_y;
}

/*
** Gestion du zoom à la molette
** Button4 = molette vers le haut → zoom avant
** Button5 = molette vers le bas → zoom arrière
**
** L'idée :
** - On calcule la position du curseur dans le plan complexe.
** - On déplace les offsets pour que le zoom soit centré sur la souris.
** - On ajuste le facteur de zoom.
** - On redessine la fractale.
*/
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	if (button != Button4 && button != Button5)
		return (0);
	compute_complex_coords(x, y, fractal, &mouse_re, &mouse_im);
	if (button == Button4)
	{
		/* Zoom avant (on se rapproche du curseur) */
		zoom_factor = 1.1;
		fractal->offset_x = mouse_re + (fractal->offset_x - mouse_re) / zoom_factor;
		fractal->offset_y = mouse_im + (fractal->offset_y - mouse_im) / zoom_factor;
		fractal->zoom *= zoom_factor;
	}
	else if (button == Button5)
	{
		/* Zoom arrière (on s'éloigne du curseur) */
		zoom_factor = 1.1;
		fractal->offset_x = mouse_re + (fractal->offset_x - mouse_re) * zoom_factor;
		fractal->offset_y = mouse_im + (fractal->offset_y - mouse_im) * zoom_factor;
		fractal->zoom /= zoom_factor;
	}
	fractal_render(fractal);
	return (0);
}

