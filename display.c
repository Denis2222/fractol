/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:31:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/11 23:09:27 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	e->imgpx[i = 1] = g;
	e->imgpx[i + 2] = r;
}

void	draw_fractal(t_env *e)
{

	double pr, pi;
	double newRe, newIm, oldRe, oldIm;
	double zoom = 1, moveX = -0.5, moveY = 0;
	int	color;
	int maxIterations = 80;
	double time, oldTime, frameTime;
	int keyReleased, keyPressed;
	int showText = 0;
	int	x;
	int	y;
	int i;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			pr = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * zoom * WIN_WIDTH) + moveX;
			pi = (y - WIN_HEIGHT / 2) / (0.5 * zoom * WIN_HEIGHT) + moveY;
			newRe = newIm = oldRe = oldIm = 0;
			i = 0;
			while (i < maxIterations && ((newRe * newRe + newIm * newIm) <= 4))
			{
				i++;
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
			}
		
			draw_dot(e, x, y, hsv_to_rgb(i % 256, 255, 255 * (i < maxIterations)));
			y++;
		}
		x++;
	}
	draw_dot(e, 104, 103, 256 * 256 * 255);
}
