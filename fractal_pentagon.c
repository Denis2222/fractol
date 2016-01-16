/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_pentagon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 17:56:28 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 22:12:35 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_line(t_env *e, t_dot *p0, t_dot *p1, int color)
{
	t_dot	*d;
	t_dot	*s;
	int		err;
	int		e2;

	d = dot(ft_abs(p1->x - p0->x), ft_abs(p1->y - p0->y));
	s = dot((p0->x < p1->x ? 1 : -1), (p0->y < p1->y ? 1 : -1));
	err = (d->x > d->y ? d->x : -d->y) / 2;
	while (!(p0->x == p1->x && p0->y == p1->y))
	{
		if (p0->x < WIDTH && p0->x > 0 && p0->y < HEIGHT && p0->y > 0)
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

void	draw_pentagon_func(t_env *e, t_pentagon p, int deep)
{
	t_pentagon	p2;
	int			i;
	int			j;
	double		ang3;

	i = 0;
	while (i < 5)
	{
		ang3 = p.angle + M_PI + (2 * i + 1) * M_PI5 + e->cam->vary;
		p2 = pentaform(p, i);
		j = 0;
		while (j < 4)
		{
			draw_line(e,
				dotpro(p, p2, ang3, j), dotpro(p, p2, ang3, j + 1), 255);
			j++;
		}
		if (deep > 0)
			draw_pentagon_func(e,
				newpenta(
					p2.x, p2.y, p.radius / (2 * cos(M_PI5) + 1),
					p.angle + M_PI + (2 * i + 1) * M_PI5),
					deep - 1);
		i++;
	}
}

void	draw_pentagon(t_env *e)
{
	t_pentagon	p;

	if (e->cam->maxit > 8)
		e->cam->maxit = 3;
	p = newpenta(
		150 - e->cam->movex * 100 * e->cam->z,
		150 - e->cam->movey * 100 * e->cam->z,
		e->cam->z * 6,
		e->cam->varx);
	draw_pentagon_func(e, p, e->cam->maxit);
}
