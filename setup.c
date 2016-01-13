/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:11:24 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/13 23:30:11 by dmoureu-         ###   ########.fr       */
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
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
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


void	draw_img(t_env *e)
{
/*	printf("zoom: %f \nmoveX:%f moveY:%f \nmouse X:%f mouseY:%f \n",
		e->cam->zoom, 
		e->cam->moveX, 
		e->cam->moveY, 
		e->cam->mouseX, 
		e->cam->mouseY);
*/
	e->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->imgpx = mlx_get_data_addr(
	e->img, &(e->bpp), &(e->size_line), &(e->endian));
	
	if (e->fractale == 1 || e->fractale == 2)
		draw_fractal(e);
	if (e->fractale == 3)
		draw_pentagon(e);
	//draw_fern(e);
	
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
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
	mouseto(e, 0, x, y);
	//draw_img(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	keyto(e, keycode);
	draw_img(e);
	return (0);
}
