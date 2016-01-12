/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:22:36 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/12 01:38:15 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyto(t_env *e, int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);

	if (keycode == KEY_UP)
		e->cam->moveY-=0.1/e->cam->zoom;
	if (keycode == KEY_DOWN)
		e->cam->moveY+=0.1/e->cam->zoom;
	if (keycode == KEY_LEFT)
		e->cam->moveX-=0.1/e->cam->zoom;
	if (keycode == KEY_RIGHT)
		e->cam->moveX+=0.1/e->cam->zoom;
	if (keycode == KEY_PLUS)
		e->cam->zoom*=1.1;
	if (keycode == KEY_MINUS)
		e->cam->zoom*=0.9;
	return (0);
}
