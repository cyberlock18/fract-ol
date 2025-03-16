/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color-schemes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:29:31 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/02/10 21:16:24 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_purple_scheme(double t, t_rgb *rgb)
{
	rgb->r = (int)(255 * (1 - cos(15 * t + 1.047)) / 2);
	rgb->b = (int)(255 * (1 - cos(15 * t)) / 2);
	rgb->g = (int)(255 * (1 - cos(7.5 * t + 3.142)) / 2);
}

void	get_cyan_scheme(double t, t_rgb *rgb)
{
	rgb->g = (int)(255 * (1 - cos(20 * t)) / 2);
	rgb->b = (int)(255 * (1 - cos(10 * t + 2.094)) / 2);
	rgb->r = (int)(255 * (1 - cos(5 * t + 4.188)) / 2);
}

void	get_color_scheme(int shift, double t, t_rgb *rgb)
{
	if (shift == 0)
		get_classic_scheme(t, rgb);
	else if (shift == 1)
		get_warm_scheme(t, rgb);
	else if (shift == 2)
		get_cold_scheme(t, rgb);
	else if (shift == 3)
		get_pastel_scheme(t, rgb);
	else if (shift == 4)
		get_purple_scheme(t, rgb);
	else
		get_cyan_scheme(t, rgb);
}
