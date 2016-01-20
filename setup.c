/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:11:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/18 21:16:12 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup(int f)
{
	t_env	e;

	e.fractale = f;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Fractol");
	e.bpp = 0;
	e.size_line = 0;
	e.endian = 0;
	e.cam = cam();
	mlx_hook(e.win, 2, 1, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, 1, mouse_motion, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}

void	draw_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->imgpx = mlx_get_data_addr(
	e->img, &(e->bpp), &(e->size_line), &(e->endian));
	if (e->fractale == 8)
		draw_pentagon(e);
	else
		draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	draw_info(e);
	mlx_destroy_image(e->mlx, e->img);
}
