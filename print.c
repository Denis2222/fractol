/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:57:38 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/14 14:19:14 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractal_fdf(t_env *e)
{
	int	x;
	int	y;
	int	i;

	e->fd = open("./fractol.fdf", O_WRONLY | O_TRUNC);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (e->fractale == 1)
				i = get_iteration_mandelbrot(e, x, y);
			else
				i = get_iteration_julia(e, x, y);
			ft_putstr_fd(ft_itoa(i * 2), e->fd);
			ft_putstr_fd(" ", e->fd);
			x++;
		}
		ft_putstr_fd(" \n", e->fd);
		y++;
	}
	close(e->fd);
}
