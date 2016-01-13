/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:07:11 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/13 18:27:18 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_dot	*dot(int x, int y, int z)
{
	t_dot	*dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	dot->z = z;
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
