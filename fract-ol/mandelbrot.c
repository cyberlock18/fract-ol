/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:36:14 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/01/31 09:20:40 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(double c_re, double c_im, t_data *data)
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
		{
			data->z_re = z_re;
			data->z_im = z_im;
			break ;
		}
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		i++;
	}
	return (i);
}

static void	handle_mandelbrot_colors(t_data *data, int x, int y, int iter)
{
	if (iter == MAX_ITER)
		put_pixel(data, x, y, 0x000000);  // Interior negro
	else
		handle_exterior_colors(data, x, y, iter);
}

static void	map_coordinates(t_data *data, int x, int y, double *coords)
{
	coords[0] = (x - data->width / 2.0)
		/ (0.25 * data->width * data->zoom) + data->offset_x;
	coords[1] = (y - data->height / 2.0)
		/ (0.25 * data->height * data->zoom) + data->offset_y;
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	coords[2];
	int		iter;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			map_coordinates(data, x, y, coords);
			iter = mandelbrot_iter(coords[0], coords[1], data);
			handle_mandelbrot_colors(data, x, y, iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
