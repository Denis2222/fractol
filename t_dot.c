/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:07:11 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 19:41:42 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setdot(t_dot *dot, int x, int y)
{
	dot->x = x;
	dot->y = y;
}

t_dot	*dot(int x, int y)
{
	t_dot	*dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	return (dot);
}

void	freedot(t_dot *d1, t_dot *d2, t_dot *d3, t_dot *d4)
{
	if (d1)
		free(d1);
	if (d2)
		free(d2);
	if (d3)
		free(d3);
	if (d4)
		free(d4);
}

t_dot	*dotpro(t_pentagon p, t_pentagon p2, double ang3, int j)
{
	t_dot	*d;

	d = dot(
		p.x + p2.radius * cos(ang3 + j * M_PI5 * 2),
		p.y + p2.radius * sin(ang3 + j * M_PI5 * 2));
	return (d);
}
