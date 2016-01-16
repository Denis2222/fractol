/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:11:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/14 22:59:46 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_motion(int x, int y, t_env *e);

void	setup(int f)
{
	t_env	e;

	e.fractale = f;
	e.fd = open("./fractol.fdf", O_WRONLY | O_TRUNC);
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
	close(e.fd);
}

void	draw_info(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "it:");
	mlx_string_put(e->mlx, e->win, 60, 10, 0xFFFFFF, ft_itoa(e->cam->maxIt));
	
	mlx_string_put(e->mlx, e->win, 10, 25, 0xFFFFFF, "offset:");
	mlx_string_put(e->mlx, e->win, 80, 25, 0xFFFFFF, ft_itoa(e->cam->moveX*10));
	mlx_string_put(e->mlx, e->win, 110, 25, 0xFFFFFF, ft_itoa(e->cam->moveY*10));
	
	mlx_string_put(e->mlx, e->win, 10, 40, 0xFFFFFF, "zoom:");
	mlx_string_put(e->mlx, e->win, 80, 40, 0xFFFFFF, ft_itoa(e->cam->z*10));
}

void	draw_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->imgpx = mlx_get_data_addr(
	e->img, &(e->bpp), &(e->size_line), &(e->endian));
	draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	draw_info(e);
	mlx_destroy_image(e->mlx, e->img);
}

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

int			mouse_motion(int x, int y, t_env *e)
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
