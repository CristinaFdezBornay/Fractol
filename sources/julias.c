/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julias.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:40:24 by crfernan          #+#    #+#             */
/*   Updated: 2019/06/04 14:27:33 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			f_julia(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + CR;
	y = 2 * MATRIX[i][j].x * MATRIX[i][j].y + CI;
	MATRIX[i][j].iter = iter;
	while (iter < ITER_RANGE)
	{
		x_temp = pow(x, 2) - pow(y, 2) + CR;
		y = 2 * x * y + CI;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
			return (iter);
		}
		iter++;
	}
	MATRIX[i][j].iter = 0;
	f_set_color(fractol, i, j, 0);
	return (iter);
}

int			f_julia3(t_fractol *fractol, int i, int j)
{
	t_complex	z;
	int			iter;

	z.real = MATRIX[i][j].x;
	z.imag = MATRIX[i][j].y;
	z = f_complex_power(z, 3);
	z.real += CR;
	z.imag += CI;
	MATRIX[i][j].iter = 0;
	iter = -1;
	while (++iter < ITER_RANGE)
	{
		z = f_complex_power(z, 3);
		z.real += CR;
		z.imag += CI;
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

int			f_julia5(t_fractol *fractol, int i, int j)
{
	t_complex	z;
	int			iter;

	z.real = MATRIX[i][j].x;
	z.imag = MATRIX[i][j].y;
	z = f_complex_power(z, 5);
	z.real += CR;
	z.imag += CI;
	MATRIX[i][j].iter = 0;
	iter = -1;
	while (++iter < ITER_RANGE)
	{
		z = f_complex_power(z, 5);
		z.real += CR;
		z.imag += CI;
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

int			f_julia7(t_fractol *fractol, int i, int j)
{
	t_complex	z;
	int			iter;

	z.real = MATRIX[i][j].x;
	z.imag = MATRIX[i][j].y;
	z = f_complex_power(z, 7);
	z.real += CR;
	z.imag += CI;
	MATRIX[i][j].iter = 0;
	iter = -1;
	while (++iter < ITER_RANGE)
	{
		z = f_complex_power(z, 7);
		z.real += CR;
		z.imag += CI;
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
