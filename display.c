/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:31:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/12 16:35:18 by dmoureu-         ###   ########.fr       */
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

void	draw_fractal(t_env *e)
{

	double pr, pi;
	double newRe, newIm, oldRe, oldIm;
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
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
			draw_dot(e, x, y, hsv_to_rgb((int)(i) % 256, 255, 255 * (i < e->cam->maxIterations)));
			y++;
		}
		x++;
	}
}
