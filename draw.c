/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:30:44 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 22:45:51 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_info(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, 10, 0xFFFFFF, "fractol:");
	mlx_string_put(e->mlx, e->win, 85, 10, 0xFFFFFF, ft_itoa(e->fractale));
	mlx_string_put(e->mlx, e->win, 5, 25, 0xFFFFFF, "it:");
	mlx_string_put(e->mlx, e->win, 60, 25, 0xFFFFFF, ft_itoa(e->cam->maxit));
	mlx_string_put(e->mlx, e->win, 5, 40, 0xFFFFFF, "zoom:");
	mlx_string_put(e->mlx, e->win, 80, 40, 0xFFFFFF, ft_itoa(e->cam->z * 10));
}

void	draw_fractal(t_env *e)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = switch_fractal(e, x, y);
			if (i < e->cam->maxit)
				draw_dot(e, x, y,
				hsv_to_rgb(((i + e->cam->color) % 256), 255, 255));
			else
				draw_dot(e, x, y, 0);
			x++;
		}
		y++;
	}
}

void	draw_dot(t_env *e, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (e->size_line * y) + (x * (e->bpp / 8));
	e->imgpx[i] = b;
	e->imgpx[i + 1] = g;
	e->imgpx[i + 2] = r;
}
