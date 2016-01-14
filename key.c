/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:22:36 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/14 23:11:20 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyto(t_env *e, int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);

	if (keycode == KEY_UP)
		e->cam->moveY -= 0.1 / e->cam->z;
	if (keycode == KEY_DOWN)
		e->cam->moveY += 0.1 / e->cam->z;
	if (keycode == KEY_LEFT)
		e->cam->moveX -= 0.1 / e->cam->z;
	if (keycode == KEY_RIGHT)
		e->cam->moveX += 0.1 / e->cam->z;
	if (keycode == KEY_PADUP)
		e->cam->maxIt++;
	if (keycode == KEY_PADDOWN)
		e->cam->maxIt--;
	if (keycode == KEY_PLUS)
	{
		e->cam->z *= 1.1;
	}
	if (keycode == KEY_MINUS)
	{
		e->cam->z *= 0.9;
	}
	if (keycode == 1)
	{
		if (e->cam->anim)
		{
			e->cam->anim = 0;
			e->cam->mouseX = e->cam->mouseY = 0;
		}
		else
			e->cam->anim = 1;
		e->cam->anim = e->cam->anim ? 0 : 1;
	}
	if (keycode == KEY_F)
		print_fractal_fdf(e);

	printf("zoom:%f", e->cam->z);
	return (0);
}

int	mouseto(t_env *e, int button, int x, int y)
{
	e->cam->mouseX = ((double)x / WIDTH) - 0.5;
	e->cam->mouseY = ((double)y / HEIGHT) - 0.5;
	if (button == 6)
		e->cam->z*=1.1;
	if (button == 7)
		e->cam->z*=0.9;
	if (button)
	{
		e->cam->moveX+=e->cam->mouseX * (1 / e->cam->z);
		e->cam->moveY+=e->cam->mouseY * (1 / e->cam->z);
	}
	return (0);
}
