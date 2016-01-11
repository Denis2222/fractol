/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 22:52:12 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/11 23:07:54 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = 0;
	color = (r << 16 || g << g | b);
	return (color);
}

int	hsv_to_rgb(unsigned int h, unsigned int s, unsigned int v)
{
	unsigned char	region;
	unsigned char	fpart;
	unsigned char	p;
	unsigned char	q;
	unsigned char	t;

	if (h == 0)
		return (rgb_to_int(v, v, v));
	region = h / 43;
	fpart = (h - (region * 43)) * 6;
	p = (v * (255 - s)) >> 8;
    q = (v * (255 - ((s * fpart) >> 8))) >> 8;
    t = (v * (255 - ((s * (255 - fpart)) >> 8))) >> 8;
	if (region == 0)
		return (rgb_to_int(v, t, p));
	if (region == 1)
		return (rgb_to_int(q, v, p));
	if (region == 2)
		return (rgb_to_int(p, v, t));
	if (region == 3)
		return (rgb_to_int(p, q, v));
	if (region == 4)
		return (rgb_to_int(t, p, v));
	else
		return (rgb_to_int(v, p, q));
}
