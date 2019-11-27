/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_shit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:40:50 by crfernan          #+#    #+#             */
/*   Updated: 2019/06/04 14:27:59 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			f_burning_ship(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	iter = 0;
	x = pow(MATRIX[i][j].x, 2) - pow(MATRIX[i][j].y, 2) + MATRIX[i][j].x;
	y = fabs(2 * MATRIX[i][j].x * MATRIX[i][j].y) + MATRIX[i][j].y;
	MATRIX[i][j].iter = iter;
	while (iter < ITER_RANGE)
	{
		x_temp = fabs(pow(x, 2) - pow(y, 2) + MATRIX[i][j].x);
		y = fabs(2 * x * y) + MATRIX[i][j].y;
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

int			f_flower(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	x = MATRIX[i][j].x;
	y = MATRIX[i][j].y;
	MATRIX[i][j].iter = 0;
	iter = -1;
	while (++iter < ITER_RANGE)
	{
		x_temp = ((2.0 * x / 3.0) - (pow(x, 2) - pow(y, 2))
			/ pow((pow(x, 2) + pow(y, 2)), 2)) / 3.0;
		y = ((2.0 * x / 3.0) + (2.0 * x * y)
			/ pow((pow(x, 2) + pow(y, 2)), 2)) / 3.0;
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) < 4.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, pow(x, 2) + pow(y, 2));
			return (iter);
		}
	}
	f_set_color(fractol, i, j, 0);
	return (iter);
}

int			f_kinda_newton(t_fractol *fractol, int i, int j)
{
	double		x;
	double		y;
	double		x_temp;
	int			iter;

	x = MATRIX[i][j].x;
	y = MATRIX[i][j].y;
	MATRIX[i][j].iter = 0;
	iter = -1;
	while (++iter < ITER_RANGE)
	{
		x_temp = (2.0 * x / 3.0) - (pow(x, 2) - pow(y, 2))
			/ (pow((pow(x, 2) + pow(y, 2)), 2) * 3.0);
		y = (2.0 * y / 3.0) + (2.0 * x * y)
			/ (pow((pow(x, 2) + pow(y, 2)), 2) * 3.0);
		x = x_temp;
		if (pow(x, 2) + pow(y, 2) > 400.0)
		{
			MATRIX[i][j].iter = iter;
			f_set_color(fractol, i, j, sqrt(pow(x, 2) + pow(y, 2)));
			return (iter);
		}
	}
	f_set_color(fractol, i, j, 0);
	return (iter);
}
