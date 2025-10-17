/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 00:19:29 by radandri          #+#    #+#             */
/*   Updated: 2025/10/16 03:21:17 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft/libft.h"
#include <stdlib.h> // malloc, free
#include <unistd.h> // write
#include <math.h>
#include "minilibx/mlx.h"


#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

// we use a square to keep the rendering math simple
#define WITH    800
#define HEIGH   800

/*
*this is basically a pixel buffer values from mlx_get_data_adr()
*/
typedef struct s_img
{
    void    *img_ptr; //pointer to image struct
    char    *pixels_ptr; //points to the actual pixels
    int     bits_per_pixel; // how many bit we have on my pixel
    int     endian;
    int     line_length
}   t_img;

typedef struct s_fractal
{
    char        *name;
    void        *mlx_connection; // mlx_init()
    void        *mlx_windows;
    t_img       img;
// Hooks member variable
    
}   t_fractal;


#endif