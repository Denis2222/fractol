/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 14:30:44 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 17:35:23 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_info(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "it:");
	mlx_string_put(e->mlx, e->win, 60, 10, 0xFFFFFF, ft_itoa(e->cam->maxit));
	mlx_string_put(e->mlx, e->win, 10, 40, 0xFFFFFF, "zoom:");
	mlx_string_put(e->mlx, e->win, 80, 40, 0xFFFFFF, ft_itoa(e->cam->z * 10));
}

void	draw_fractal(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			switch_fractal(e, x, y);
			x++;
		}
		y++;
	}
}

void	draw_dot(t_env *e, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (e->size_line * y) + (x * (e->bpp / 8));
	e->imgpx[i] = b;
	e->imgpx[i + 1] = g;
	e->imgpx[i + 2] = r;
}

void	draw_line(t_env *e, t_dot *p0, t_dot *p1, int color)
{
	t_dot	d;
	t_dot	s;
	int		err;
	int		e2;

	setdot(&d, ft_abs(p1->x - p0->x), ft_abs(p1->y - p0->y));
	setdot(&d, (p0->x < p1->x ? 1 : -1), (p0->y < p1->y ? 1 : -1));
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (!(p0->x == p1->x && p0->y == p1->y))
	{
		if (p0->x < WIDTH && p0->x > 0 && p0->y < HEIGHT && p0->y > 0)
			draw_dot(e, p0->x, p0->y, color);
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			p0->x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			p0->y += s.y;
		}
	}
}
