/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:01:21 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/02/03 21:46:24 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_ITER 100

int calculate_julia_iter (double real_pt, double im_pt,double const_real, double const_im)
{
	int i;
	double temp;
	double z_real;
	double z_im;

	i = 0;
	z_real = real_pt;
	z_im = im_pt;
	while (i < MAX_ITER)
	{
		temp = z_real * z_real - z_im * z_im + const_real;
		z_im = 2 * z_real * z_im + const_im;
		z_real = temp;
		if (z_real * z_real + z_im * z_im > 4)
			break;
		i++;
	}
	return (i);
}

static void calc_interior_col(t_data *data, t_rgb *rgb, int x , int y)
{
	double inner_glow;
	double angle;

	inner_glow = ((x - data->width / 2.0) * (x - data->width /2.0) 
	+ (y - data->height  / 2.0) * (y - data->height / 2.0)) 
	/ (data->width * data->width);
	angle = atan2(y - data->height / 2.0, x - data->width / 2.0)
	+ data->color_shift * M_PI / 3;
	rgb->r = (int)(127 + 127 * sin(angle * 3 +inner_glow));
	rgb->g = (int)(127 + 127 * sin(angle * 2 + inner_glow *2));
	rgb->b = (int)(200 + 55 * sin(angle + inner_glow * 3));
}
static void	apply_color_shift(t_data *data, t_rgb rgb, int x, int y)
{
	int	color;

	if (data->color_shift == 1)
		color = (rgb.g << 16) | (rgb.b << 8) | rgb.r;
	else if (data->color_shift == 2)
		color = (rgb.b << 16) | (rgb.r << 8) | rgb.g;
	else if (data->color_shift == 3)
		color = (rgb.r << 16) | (rgb.b << 8) | rgb.g;
	else if (data->color_shift == 4)
		color = (rgb.g << 16) | (rgb.r << 8) | rgb.b;
	else if (data->color_shift == 5)
		color = (rgb.b << 16) | (rgb.g << 8) | rgb.r;
	else
		color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	put_pixel(data, x, y, color);
}

static void	calculate_julia_colors(t_data *data, int x, int y, int iter)
{
	t_rgb	rgb;

	if (iter == MAX_ITER)
	{
		calc_interior_color(data, &rgb, x, y);
		set_rgb_values(&rgb);
		apply_color_shift(data, rgb, x, y);
	}
	else
		handle_exterior_colors(data, x, y, iter);
}

void render_julia_set(t_data *data, double constant_real, double constant_imaginary)
{
	int x, y;
	double mapped_re, mapped_im;
	int iter;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mapped_re = (x - data->width / 2.0) / (0.25 * data->width * data->zoom) + data->offset_x;
			mapped_im = (y - data->height / 2.0) / (0.25 * data->height * data->zoom) + data->offset_y;
			
			iter = calculate_julia_iterations(mapped_re, mapped_im, constant_real, constant_imaginary);
			calculate_julia_colors(data, x, y, iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
