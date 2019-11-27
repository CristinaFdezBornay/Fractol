/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:39:41 by crfernan          #+#    #+#             */
/*   Updated: 2019/06/04 14:27:14 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	f_key_esc(int key, t_fractol *fractol)
{
	key = 0;
	mlx_destroy_image(MLX_PTR, IMG_PTR);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
	f_free_points(fractol);
	ft_printf("Good bye and have a good day!\n");
	exit(0);
}

void	f_key_iteration(int key, t_fractol *fractol)
{
	if (key == 69)
		ITER_RANGE++;
	else if (key == 78 && ITER_RANGE != 0)
		ITER_RANGE--;
}

void	f_key_trans(int key, t_fractol *fractol)
{
	if (key == 123 && MAX_X >= -2.0)
	{
		MIN_X -= STEP_X * 15;
		MAX_X -= STEP_X * 15;
	}
	if (key == 124 && MIN_X <= 2.0)
	{
		MIN_X += STEP_X * 15;
		MAX_X += STEP_X * 15;
	}
	if (key == 125 && MAX_Y >= -2.0)
	{
		MIN_Y -= STEP_Y * 15;
		MAX_Y -= STEP_Y * 15;
	}
	if (key == 126 && MIN_Y <= 2.0)
	{
		MIN_Y += STEP_Y * 15;
		MAX_Y += STEP_Y * 15;
	}
	STEP_X = (MAX_X - MIN_X) / (double)IMAGE_X;
	STEP_Y = (MAX_Y - MIN_Y) / (double)IMAGE_Y;
}

void	f_key_color_ref(int key, t_fractol *fractol)
{
	key = 0;
	if (COLOR_REF == 0xff4162)
		COLOR_REF = 0x62ff41;
	else if (COLOR_REF == 0x62ff41)
		COLOR_REF = 0x7f41ff;
	else if (COLOR_REF == 0x7f41ff)
		COLOR_REF = 0xffde41;
	else if (COLOR_REF == 0xffde41)
		COLOR_REF = 0x00a6ff;
	else if (COLOR_REF == 0x00a6ff)
		COLOR_REF = 0xff4162;
}

void	f_key_fdf_output(int key, t_fractol *fractol)
{
	int		fd;
	int		i;
	int		j;

	key = 0;
	fd = open("map.txt", O_TRUNC | O_CREAT | O_RDWR, 0777);
	i = 0;
	while (i < IMAGE_Y)
	{
		j = 0;
		while (j < IMAGE_X)
		{
			ft_dprintf(fd, "%d,%#x", MATRIX[i][j].iter, MATRIX[i][j].color);
			if (j + 1 != IMAGE_X)
				ft_dprintf(fd, " ");
			else if (i + 1 != IMAGE_Y)
				ft_dprintf(fd, "\n");
			j++;
		}
		i++;
	}
	close(fd);
}
