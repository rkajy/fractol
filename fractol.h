/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 00:19:29 by radandri          #+#    #+#             */
/*   Updated: 2025/10/21 10:11:44 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft/libft.h"
#include <stdlib.h> // malloc, free
#include <unistd.h> // write
#include <math.h> // pow, sqrt, 
#include "minilibx/mlx.h" // mlx_init
#include <errno.h> // errno
#include <stdio.h> // perror
#include <X11/X.h> // KeyPress, KeyRelease, etc.

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

// we use a square to keep the rendering math simple
#define WIDTH    800
#define HEIGHT   800

#define MANDELBROT 0
#define JULIA 1

typedef struct s_complex
{
    double re; // real
    double im; // imaginary
} t_complex;

// COLORS
#define BLACK 0x000000 // RGB(0,0,0)
#define WHITE 0xFFFFFF // RGB(255,255,255)
#define RED   0xFF0000 // RGB(255,0,0)
#define GREEN 0x00FF00 // RGB(0,255,0)
#define BLUE  0x0000FF // RGB(0,0,255)

// Psychedelic colors
#define MAGENTA_BURST 0xFF00FF // RGB(255,0,255), A vibrant magenta
#define LIME_SHOCK  0x00FF7F // RGB(0,255,127), A bright lime green
#define NEON_ORANGE 0xFF4500 // RGB(255,69,0), A striking neon orange
#define PSYCHEDELIC_PURPLE 0x8A2BE2 // RGB(138,43,226), A deep psychedelic purple
#define AQUA_DREAM 0x00FFFF // RGB(0,255,255), A dreamy aqua blue
#define HOT_PINK 0xFF69B4 // RGB(255,105,180), A hot pink shade
#define ELECTRIC_BLUE 0x7DF9FF // RGB(125,249,255), An electric blue hue
#define LAVA_RED 0xCF1020 // RGB(207,16,32), A fiery lava red

/*
*this is basically a pixel buffer values from mlx_get_data_adr()
*/
typedef struct s_img
{
    void    *img_ptr; //pointer to image struct
    char    *pixels_ptr; //points to the actual pixels
    int     bits_per_pixel; // how many bit we have in my pixel
    int     endian;
    int     line_len;
}   t_img;

typedef struct s_fractal
{
    char        *name;
    void        *mlx_connection; // mlx_init()
    void        *mlx_windows;
    t_img       img;
// Hooks member variable
    double  escape_value; // hypotenuse
    int     iterations_definition; //value tight with the image quality and rendering speed
    double shift_x;
    double shift_y;
    double zoom;
    double julia_x; // real part for julia
    double julia_y; // imaginary part for julia
    int type;
}   t_fractal;

//*** init ***
void fractal_init(t_fractal *fractal);

void is_null_img_ptr_checker(t_fractal *fractal);

void is_null_mlx_connection_checker(t_fractal *fractal);

void is_null_mlx_windows(t_fractal *fractal);

//*** render */
void    fractal_render(t_fractal *fractal);

//*** math */
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

//*** events */
int key_handler(int keycode, t_fractal *fractal);
int mouse_handler(int button, int x, int y, t_fractal *fractal);
int close_handler(t_fractal *fractal);
int julia_track(int x, int y, t_fractal *fractal);

double atodouble(char *s);

int get_color(int iter, int max_iter);


#endif