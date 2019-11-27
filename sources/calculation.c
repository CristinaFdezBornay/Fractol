/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:39:30 by crfernan          #+#    #+#             */
/*   Updated: 2019/06/04 14:27:09 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	color_scheme1(t_fractol *fractol, int i, int j)
{
	int		red;
	int		green;
	int		blue;

	red = (double)(COLOR_REF % 256 % 256)
		* ((double)MATRIX[i][j].iter / (double)ITER_RANGE);
	green = (double)(COLOR_REF / 256 % 256)
		* ((double)MATRIX[i][j].iter / (double)ITER_RANGE);
	blue = (double)(COLOR_REF / 256 / 256)
		* ((double)MATRIX[i][j].iter / (double)ITER_RANGE);
	IMG_STR[(i * IMAGE_X + j) * 4 + 0] = (char)red;
	IMG_STR[(i * IMAGE_X + j) * 4 + 1] = (char)green;
	IMG_STR[(i * IMAGE_X + j) * 4 + 2] = (char)blue;
	IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
	return ((red * 0x100 + green) * 0x100 + blue);
}

void			f_set_color(t_fractol *fractol, int i, int j, double z)
{
	if (COLOR_ALG != 'i')
		MATRIX[i][j].color = color_scheme1(fractol, i, j);
	else
	{
		z = 0;
		MATRIX[i][j].color = COLOR_REF * MATRIX[i][j].iter;
		IMG_STR[(i * IMAGE_X + j) * 4 + 0] =
			(char)(MATRIX[i][j].color % 256 % 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 1] =
			(char)(MATRIX[i][j].color / 256 % 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 2] =
			(char)(MATRIX[i][j].color / 256 / 256);
		IMG_STR[(i * IMAGE_X + j) * 4 + 3] = 0;
	}
}

t_complex		f_complex_power(t_complex z, int power)
{
	t_complex	a;
	t_complex	b;

	a = z;
	while (--power > 0)
	{
		b = z;
		z.real = (a.real * b.real) - (a.imag * b.imag);
		z.imag = (a.real * b.imag) + (a.imag * b.real);
	}
	z.z = sqrt(pow(z.real, 2) + pow(z.imag, 2));
	return (z);
}
