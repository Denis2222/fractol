/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:31:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/14 21:09:37 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	offsetcomplex(t_env *e, int x, int y)
{
	t_complex	p;

	p.r = 1.5 * (x - WIDTH / 2) / (0.5 * e->cam->z * WIDTH) + e->cam->moveX;
	p.i = (y - HEIGHT / 2) / (0.5 * e->cam->z * HEIGHT) + e->cam->moveY;
	return (p);
}

/* Z^2 + C */
int		get_iteration_mandelbrot(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	p;
	int			i;

	p = offsetcomplex(e, x, y);
	new = initcomplex();
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxIt && ((new.r * new.r + new.i * new.i) <= 4))
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = addcomplex(new, p);
		i++;
	}
	return (i);
}

int		get_iteration_julia(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;
	int			i;

	c.r = -0.7 + e->cam->varX;
	c.i = 0.27015 + e->cam->varY;
	new = offsetcomplex(e, x, y);
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxIt && (new.r * new.r + new.i * new.i) <= 4)
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = addcomplex(new, c);
		i++;
	}
	return (i);
}

/* Z^3 + C */
int		get_iteration_custom(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	p;
	int			i;

	p = offsetcomplex(e, x, y);
	new = initcomplex();
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxIt && ((new.r * new.r + new.i * new.i) <= 4))
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = multcomplex(old, new);
		new = addcomplex(new, p);
		i++;
	}
	return (i);
}

/* Z^2 + C^3 */
int		get_iteration_custom2(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	p;
	int			i;

	p = offsetcomplex(e, x, y);
	p = multcomplex(p, p);
	p = multcomplex(p, offsetcomplex(e, x, y));
	new = initcomplex();
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxIt && ((new.r * new.r + new.i * new.i) <= 4))
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = addcomplex(new, p);
		i++;
	}
	return (i);
}

/* manu copyright */
int		get_iteration_custom3(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;
	int			i;

	c.r = -0.7;
	c.i = 0.27015;
	new = offsetcomplex(e, x, y);
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxIt && (new.r * new.r + new.i * new.i) <= 4)
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = addcomplex(new, c);
		new.r = cos(new.r);
		i++;
	}
	return (i);
}

void	draw_fractal(t_env *e)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (e->fractale == 1)
				i = get_iteration_mandelbrot(e, x, y);
			else if (e->fractale == 2)
				i = get_iteration_julia(e, x, y);
			else if (e->fractale == 3)
				i = get_iteration_custom(e, x, y);
			else if (e->fractale == 4)
				i = get_iteration_custom2(e, x, y);
			else if (e->fractale == 5)
				i = get_iteration_custom3(e, x, y);
			if (i < e->cam->maxIt)
				draw_dot(e, x, y,
				hsv_to_rgb(i % 256, 255 ,255));
			else
				draw_dot(e, x, y, 0);
			x++;
		}
		y++;
	}
}

double	mult(double x)
{
	return (x * 7);
}
