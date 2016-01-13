/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:31:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/13 03:11:41 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_dot(t_env *e, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	//printf("RGB:%d %d %d", r, g, b);
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (e->size_line * y) + (x * (e->bpp / 8));
	e->imgpx[i] = b;
	e->imgpx[i + 1] = g;
	e->imgpx[i + 2] = r;
}

int	get_iteration_mandelbrot(t_env *e, int x, int y)
{
	long double pr, pi;
	long double newRe, newIm, oldRe, oldIm;
	int	i;

	pr = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * e->cam->zoom * WIN_WIDTH) + e->cam->moveX;
	pi = (y - WIN_HEIGHT / 2) / (0.5 * e->cam->zoom * WIN_HEIGHT) + e->cam->moveY;
	newRe = newIm = oldRe = oldIm = 0;
	i = 0;
	while (i < e->cam->maxIterations && ((newRe * newRe + newIm * newIm) <= 4))
	{
		i++;
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + pr;
		newIm = 2 * oldRe * oldIm + pi;
	}
	return (i);
}

int	get_iteration_julia(t_env *e, int x, int y)
{
	double	newRe, newIm, oldRe, oldIm;
	double	cRe, cIm;
	int	i;

	cRe = -0.7 + e->cam->mouseX / e->cam->zoom;
	cIm = 0.27015 + e->cam->mouseY / e->cam->zoom;

	newRe = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * e->cam->zoom * WIN_WIDTH) + e->cam->moveX;
	newIm = (y - WIN_HEIGHT / 2) / (0.5 * e->cam->zoom * WIN_HEIGHT) + e->cam->moveY;

	i = 0;
	while (i < e->cam->maxIterations && (newRe * newRe + newIm * newIm) <= 4)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;
		i++;
	}
	return (i);
}

void	draw_fractal(t_env *e)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			i = get_iteration_julia(e, x, y);
			draw_dot(e, x, y, hsv_to_rgb(i % 256, 255, 255 * (i < e->cam->maxIterations)));
			y++;
		}
		x++;
	}
}

