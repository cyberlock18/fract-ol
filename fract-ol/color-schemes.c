/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color-schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruortiz- <ruortiz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:29:31 by ruortiz-          #+#    #+#             */
/*   Updated: 2025/02/02 21:29:31 by ruortiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_classic_scheme(double t, t_rgb *rgb)
{
	rgb->r = (int)(255 * (1 - cos(20 * t)) / 2);
	rgb->g = (int)(255 * (1 - cos(10 * t + 2.094)) / 2);
	rgb->b = (int)(255 * (1 - cos(5 * t + 4.188)) / 2);
}

void	get_warm_scheme(double t, t_rgb *rgb)
{
	rgb->r = (int)(255 * (1 - cos(15 * t)) / 2);
	rgb->g = (int)(255 * (1 - cos(7.5 * t + 2.094)) / 2);
	rgb->b = (int)(255 * (1 - cos(3.75 * t + 4.188)) / 2);
}

void	get_cold_scheme(double t, t_rgb *rgb)
{
	rgb->b = (int)(255 * (1 - cos(20 * t)) / 2);
	rgb->g = (int)(255 * (1 - cos(10 * t + 2.094)) / 2);
	rgb->r = (int)(255 * (1 - cos(5 * t + 4.188)) / 2);
}

void	get_pastel_scheme(double t, t_rgb *rgb)
{
	rgb->r = (int)(255 * (0.7 - 0.7 * cos(20 * t)) / 2 + 100);
	rgb->g = (int)(255 * (0.7 - 0.7 * cos(10 * t + 2.094)) / 2 + 100);
	rgb->b = (int)(255 * (0.7 - 0.7 * cos(5 * t + 4.188)) / 2 + 100);
}
