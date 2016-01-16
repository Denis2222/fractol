/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:22:36 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 21:22:04 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyto_move(t_env *e, int keycode)
{
	if (keycode == KEY_UP)
		e->cam->movey -= 0.1 / e->cam->z;
	if (keycode == KEY_DOWN)
		e->cam->movey += 0.1 / e->cam->z;
	if (keycode == KEY_LEFT)
		e->cam->movex -= 0.1 / e->cam->z;
	if (keycode == KEY_RIGHT)
		e->cam->movex += 0.1 / e->cam->z;
	return (0);
}

int	keyto_iter(t_env *e, int keycode)
{
	if (keycode == KEY_PADUP || keycode == KEY_D)
		e->cam->maxit++;
	if ((keycode == KEY_PADDOWN || keycode == KEY_A) && e->cam->maxit > 1)
		e->cam->maxit--;
	return (0);
}

int	keyto_zoom(t_env *e, int keycode)
{
	if (keycode == KEY_PLUS || keycode == KEY_W)
		e->cam->z *= 1.1;
	if ((keycode == KEY_MINUS || keycode == KEY_S) && e->cam->z > 0.5)
		e->cam->z *= 0.9;
	return (0);
}

int	keyto(t_env *e, int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	keyto_move(e, keycode);
	keyto_iter(e, keycode);
	keyto_zoom(e, keycode);
	if (keycode == KEY_F)
	{
		if (e->cam->anim)
			e->cam->anim = 0;
		else
			e->cam->anim = 1;
	}
	if (keycode == KEY_L)
		print_fractal_fdf(e);

	if (keycode == KEY_LBRACKET && e->fractale > 1)
		e->fractale -= 1;
	if (keycode == KEY_RBRACKET && e->fractale < 8)
		e->fractale += 1;
	ft_putnbr(keycode);
	return (0);
}

int	mouseto(t_env *e, int button, int x, int y)
{
	e->cam->mousex = ((double)x / WIDTH) - 0.5;
	e->cam->mousey = ((double)y / HEIGHT) - 0.5;
	if (e->cam->anim)
	{
		e->cam->varx = e->cam->mousex;
		e->cam->vary = e->cam->mousey;
	}
	if (button == 6 || button == 5)
	{
		e->cam->movex += (e->cam->mousex * (1 / e->cam->z)) * 0.5;
		e->cam->movey += (e->cam->mousey * (1 / e->cam->z)) * 0.5;
		e->cam->z *= 1.1;
	}
	if (button == 7 || button == 4)
	{
		e->cam->movex += (e->cam->mousex * (1 / e->cam->z)) * 0.5;
		e->cam->movey += (e->cam->mousey * (1 / e->cam->z)) * 0.5;
		e->cam->z *= 0.9;
	}
	if (button == 1)
	{
		e->cam->movex += e->cam->mousex * (1 / e->cam->z) * 0.5;
		e->cam->movey += e->cam->mousey * (1 / e->cam->z) * 0.5;
	}
	return (0);
}
