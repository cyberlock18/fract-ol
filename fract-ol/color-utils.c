/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:27:08 by ruortiz-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/05 17:17:19 by ruortiz-         ###   ########.fr       */
=======
/*   Updated: 2025/02/02 21:29:31 by ruortiz-         ###   ########.fr       */
>>>>>>> 2e72583 (optimizacion de archivos)
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	set_rgb_values(t_rgb *rgb)
{
	if (rgb->r > 255)
		rgb->r = 255; 
	else if (rgb->r < 0)
		rgb->r = 0;
	if (rgb->g > 255)
		rgb->g = 255;
	else if (rgb->g < 0)
		rgb->g = 0;
	if (rgb->b > 255)
		rgb->b = 255;
	else if (rgb->b < 0)
		rgb->b = 0;
}

void	handle_color_shift(t_data *data, int x, int y, t_rgb rgb)
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

void	handle_exterior_colors(t_data *data, int x, int y, int iter)
{
	t_rgb	rgb;
	double	t;
	double	smooth_iter;
	double	zn;

	if (iter == MAX_ITER)
	{
		put_pixel(data, x, y, 0x000000);
		return ;
	}
	zn = sqrt(data->z_re * data->z_re + data->z_im * data->z_im);
	smooth_iter = iter + 1 - log2(log2(zn));
	t = smooth_iter / MAX_ITER;
	get_color_scheme(data->color_shift, t, &rgb);
	set_rgb_values(&rgb);
	put_pixel(data, x, y, (rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

int	calculate_color(int iteration, int max_iter, int shift)
{
	double	t;
	int		rgb[3];
	double	offset; // Añadido para desplazar el punto de referencia

	if (iteration == max_iter)
		return (0x000000);
	t = (double)iteration / max_iter;
	offset = 0.25; // Desplazar el punto de referencia a una esquina
	t = t + shift * 0.1 + offset;
	while (t > 1.0)
		t -= 1.0;
	rgb[0] = (int)(sin(2 * M_PI * t) * 127.5 + 127.5);
	rgb[1] = (int)(sin(2 * M_PI * (t + 0.3333)) * 127.5 + 127.5);
	rgb[2] = (int)(sin(2 * M_PI * (t + 0.6666)) * 127.5 + 127.5);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
