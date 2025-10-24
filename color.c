#include "fractol.h"
/*
** Combine les trois composantes rouge, vert et bleu
** dans un seul entier de type 0xRRGGBB que MiniLibX comprend.
*/
int	create_trgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

/*
** Calcule une couleur dégradée selon le nombre d’itérations (i)
** Si i == max_iter → point "dans" la fractale → noir.
** Sinon → couleur variable selon la rapidité de divergence.
*/
int	get_color(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max_iter)
		return (0x000000); // noir
	t = (double)i / max_iter;
	t = sqrt(t);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (create_trgb(r, g, b));
}
