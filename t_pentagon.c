/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pentagon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 19:18:29 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 19:31:27 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pentagon	newpenta(double x, double y, double radius, double angle)
{
	t_pentagon	p;

	p.x = x;
	p.y = y;
	p.radius = radius;
	p.angle = angle;
	return (p);
}

t_pentagon	pentaform(t_pentagon p, int i)
{
	t_pentagon	p2;
	double		h;

	h = 2 * p.radius * cos(M_PI5);
	p2.angle = p.angle + M_PI5 * i * 2;
	p2.x = p.x - h * cos(p2.angle);
	p2.y = p.y - h * sin(p2.angle);
	p2.radius = p.radius / (2 * cos(M_PI5) + 1);
	return (p2);
}
