/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:31:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/13 23:30:05 by dmoureu-         ###   ########.fr       */
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

int	get_iteration_mandelbrot(t_env *e, int x, int y)
{
	double newRe, newIm, oldRe, oldIm;
	double pr, pi;
	int	i;

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
	return (i);
}

int	get_iteration_julia(t_env *e, int x, int y)
{
	double	newRe, newIm, oldRe, oldIm;
	double	cRe, cIm;
	int	i;

	cRe = -0.7 + e->cam->mouseX / e->cam->zoom;
	cIm = 0.27015 + e->cam->mouseY / e->cam->zoom;

	newRe = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * e->cam->zoom * WIN_WIDTH) + e->cam->moveX;
	newIm = (y - WIN_HEIGHT / 2) / (0.5 * e->cam->zoom * WIN_HEIGHT) + e->cam->moveY;

	i = 0;
	while (i < e->cam->maxIterations && (newRe * newRe + newIm * newIm) <= 4)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;
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
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (e->fractale == 1)
				i = get_iteration_mandelbrot(e, x, y);
			else
				i = get_iteration_julia(e, x, y);
			draw_dot(e, x, y, hsv_to_rgb(i % 256, 255 - (i*255/e->cam->maxIterations), 255));
			ft_putstr_fd(ft_itoa(i*2), e->fd);
			ft_putstr_fd(" ", e->fd);
			x++;
		}
		ft_putstr_fd(" \n", e->fd);
		y++;
	}
}

double mult(double x)
{
	return (x*7);
}

void	draw_line(t_env *e, t_dot *p0, t_dot *p1, int color)
{
	t_dot	*d;
	t_dot	*s;
	int		err;
	int		e2;

	d = dot(ft_abs(p1->x - p0->x), ft_abs(p1->y - p0->y), 0);
	s = dot((p0->x < p1->x ? 1 : -1), (p0->y < p1->y ? 1 : -1), 0);
	err = (d->x > d->y ? d->x : -d->y) / 2;
	while (!(p0->x == p1->x && p0->y == p1->y))
	{
		if (p0->x < WIN_WIDTH && p0->x > 0 && p0->y < WIN_HEIGHT && p0->y > 0)
			draw_dot(e, p0->x, p0->y, color);
		e2 = err;
		if (e2 > -d->x)
		{
			err -= d->y;
			p0->x += s->x;
		}
		if (e2 < d->y)
		{
			err += d->x;
			p0->y += s->y;
		}
	}
	freedot(p0, p1, d, s);
}

void	draw_pentagon_func(t_env *e, double x, double y, double radius, double angle, int deep)
{
	double pi5 = 3.141596/5;
	double h = 2*radius*cos(pi5);
	int i;
	int j;
	double ang2;
	double x2;
	double y2;
	double rad2;
	double ang3;

	i = 0;
	while (i < 5)
	{
		ang2 = angle + pi5 * i * 2;
		x2 = x - h * cos(ang2);
		y2 = y - h * sin(ang2);
		rad2 = radius / (2 * cos(pi5) + 1);
		ang3 = angle + 3.141596 + (2* i + 1) * pi5;
		
		j = 0;
		while (j < 4)
		{
			draw_line(e, 
				dot(
					mult(x+rad2*cos(ang3+j*pi5*2)),
					mult(y+rad2 * sin(ang3+j*pi5*2)),
				0), 
				dot(
					mult(x+rad2*cos(ang3+(j+1)*pi5*2)),
					mult(y+rad2*sin(ang3+(j+1)*pi5*2)),
				0),
				255);
			j++;
		}
		if (deep>0)
			draw_pentagon_func(e, x2, y2, radius/(2*cos(pi5)+1), angle+3.141596+(2*i+1)*pi5, deep-1);
		i++;
	}
}

void	draw_pentagon(t_env *e)
{
	draw_pentagon_func(e, e->cam->moveX * e->cam->zoom + 50, e->cam->moveY * e->cam->zoom + 40, e->cam->zoom * 6, e->cam->mouseX, e->cam->zoom);
}

void	draw_newton(t_env *e)
{
	
}
