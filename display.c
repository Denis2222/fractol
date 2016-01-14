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

void	opcomplex(t_double2 *result, t_double2 d1, t_double2 d2)
{
	result->r = d1.r + d2.r;
	result->i = d1.i + d2.i;
}

void	souscomplex(t_double2 *result, t_double2 d1, t_double2 d2)
{
	result->r = d1.r - d2.r;
	result->i = d1.i - d2.i;
}

void	multcomplex(t_double2 *result, t_double2 d1, t_double2 d2)
{
	result->r = d1.r * d2.r + ((-1) *  d1.i * d2.i);
	result->i = (d1.r * d2.i) + (d1.i * d2.r);
}

int		get_iteration_mandelbrot(t_env *e, int x, int y)
{
	t_double2	new;
	t_double2	old;
	t_double2	p;
	int			i;

	p.r = 1.5 * (x - WIDTH / 2) / (0.5 * e->cam->z * WIDTH) + e->cam->moveX;
	p.i = (y - HEIGHT / 2) / (0.5 * e->cam->z * HEIGHT) + e->cam->moveY;
	double2(&new);
	double2(&old);
	i = 0;
	while (i < e->cam->maxIt && ((new.r * new.r + new.i * new.i) <= 4))
	{
		i++;
		old.r = new.r;
		old.i = new.i;
		multcomplex(&new, old, old);
		multcomplex(&new, new, old);
		souscomplex(&new, new, old);
		new.r += p.r;
		new.i += p.i;
	}
	return (i);
}

int		get_iteration_julia(t_env *e, int x, int y)
{
	t_double2	new;
	t_double2	old;
	t_double2	c;
	int			i;

	c.r = -0.7 + e->cam->mouseX / e->cam->z;
	c.i = 0.27015 + e->cam->mouseY / e->cam->z;
	new.r = 1.5 * (x - WIDTH / 2) / (0.5 * e->cam->z * WIDTH) + e->cam->moveX;
	new.i = (y - HEIGHT / 2) / (0.5 * e->cam->z * HEIGHT) + e->cam->moveY;
	double2(&old);
	i = 0;
	while (i < e->cam->maxIt && (new.r * new.r + new.i * new.i) <= 4)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
		i++;
	}
	return (i);
}

int		get_iteration_custom(t_env *e, int x, int y)
{
	t_double2	new;
	t_double2	old;
	t_double2	c;
	int			i;

	c.r = -0.7 + e->cam->mouseX / e->cam->z;
	c.i = 0.27015 + e->cam->mouseY / e->cam->z;
	new.r = 1.5 * (x - WIDTH / 2) / (0.5 * e->cam->z * WIDTH) + e->cam->moveX;
	new.i = (y - HEIGHT / 2) / (0.5 * e->cam->z * HEIGHT) + e->cam->moveY;
	double2(&old);
	i = 0;
	while (i < e->cam->maxIt && (new.r * new.r + new.i * new.i) <= 4)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
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
			else if (e->fractale == 4)
				i = get_iteration_custom(e, x, y) ;
			draw_dot(e, x, y,
				hsv_to_rgb(i % 256, 255 ,255 * (i < e->cam->maxIt)));
			x++;
		}
		y++;
	}
}

double	mult(double x)
{
	return (x * 7);
}

/*
void	draw_pentagon(t_env *e, double x, double y, double radius, double angle, int deep)
{
	int		i;
	int		j;
	double	d[6];
	t_dot	dot1;
	t_dot	dot2;

	d[0] = 2 * radius * cos(M_PI5);
	i = 0;
	while (i < 5)
	{
		d[1] = angle + M_PI5 * i * 2;
		d[2] = x - d[0] * cos(d[1]);
		d[3] = y - d[0] * sin(d[1]);
		d[4] = radius / (2 * cos(M_PI5) + 1);
		d[5] = angle + M_PI + (2 * i + 1) * M_PI5;
		
		j = 0;
		while (j < 4)
		{
			setdot(&dot1, mult(x + d[4] * cos(d[5] + j * M_PI5 * 2)), 
					mult(y + d[4] * sin(d[5] + j * M_PI5 * 2)));
				
			
			
			draw_line(e, 
				dot(
				dot(
				255);
			j++;
		}
		if (deep>0)
			draw_pentagon(e, d[2], d[3], radius / (2 * cos(M_PI5) + 1), angle + M_PI + (2 * i + 1) * M_PI5, deep - 1);
		i++;
	}
}
*/
