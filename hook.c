/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 17:15:54 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 17:34:38 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	draw_img(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	mouseto(e, button, x, y);
	draw_img(e);
	return (0);
}

int		mouse_motion(int x, int y, t_env *e)
{
	if (e->cam->anim)
	{
		mouseto(e, 0, x, y);
		draw_img(e);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	keyto(e, keycode);
	draw_img(e);
	return (0);
}
