/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:40:43 by crfernan          #+#    #+#             */
/*   Updated: 2019/06/04 14:27:54 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			f_mandelbrot(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + MATRIX[i][j].x;
	y = 2 * MATRIX[i][j].x * MATRIX[i][j].y + MATRIX[i][j].y;
	MATRIX[i][j].iter = iter;
	while (iter < ITER_RANGE)
	{
		x_temp = pow(x, 2) - pow(y, 2) + MATRIX[i][j].x;
		y = 2 * x * y + MATRIX[i][j].y;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
			return (iter);
		}
		iter++;
	}
	f_set_color(fractol, i, j, 0);
	return (iter);
}

int			f_mandelbrot3(t_fractol *fractol, int i, int j)
{
	t_complex	z;
	int			iter;

	z.real = MATRIX[i][j].x;
	z.imag = MATRIX[i][j].y;
	z = f_complex_power(z, 3);
	z.real += MATRIX[i][j].x;
	z.imag += MATRIX[i][j].y;
	MATRIX[i][j].iter = 0;
	iter = -1;
	while (++iter < ITER_RANGE)
	{
		z = f_complex_power(z, 3);
		z.real += MATRIX[i][j].x;
		z.imag += MATRIX[i][j].y;
		z.z = sqrt(pow(z.real, 2) + pow(z.imag, 2));
		if (z.z > 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(z.z, 2));
			return (iter);
		}
	}
	f_set_color(fractol, i, j, 0);
	return (iter);
}

int			f_mandelbrot5(t_fractol *fractol, int i, int j)
{
	t_complex	z;
	int			iter;

	z.real = MATRIX[i][j].x;
	z.imag = MATRIX[i][j].y;
	z = f_complex_power(z, 5);
	z.real += MATRIX[i][j].x;
	z.imag += MATRIX[i][j].y;
	MATRIX[i][j].iter = 0;
	iter = -1;
	while (++iter < ITER_RANGE)
	{
		z = f_complex_power(z, 5);
		z.real += MATRIX[i][j].x;
		z.imag += MATRIX[i][j].y;
		z.z = sqrt(pow(z.real, 2) + pow(z.imag, 2));
		if (z.z > 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(z.z, 2));
			return (iter);
		}
	}
	f_set_color(fractol, i, j, 0);
	return (iter);
}

int			f_mandelbrot7(t_fractol *fractol, int i, int j)
{
	t_complex	z;
	int			iter;

	z.real = MATRIX[i][j].x;
	z.imag = MATRIX[i][j].y;
	z = f_complex_power(z, 7);
	z.real += MATRIX[i][j].x;
	z.imag += MATRIX[i][j].y;
	MATRIX[i][j].iter = 0;
	iter = -1;
	while (++iter < ITER_RANGE)
	{
		z = f_complex_power(z, 7);
		z.real += MATRIX[i][j].x;
		z.imag += MATRIX[i][j].y;
		z.z = sqrt(pow(z.real, 2) + pow(z.imag, 2));
		if (z.z > 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(z.z, 2));
			return (iter);
		}
	}
	f_set_color(fractol, i, j, 0);
	return (iter);
}
