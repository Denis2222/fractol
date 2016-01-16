/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:32 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 17:24:13 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(void)
{
	ft_putendl("\n1 Mandelbrot");
	ft_putendl("2 Julia");
	ft_putendl("3 Mandelbrot (Z^3 + C)");
	ft_putendl("4 Mandelbrot (Z^2 + C^3)");
	ft_putendl("5 Julia (Z^3 + C^3)");
	exit(EXIT_FAILURE);
}

void	invalid(int f)
{
	ft_putstr("Fractale indisponible");
	help();
}

int		main(int ac, char **av)
{
	int	f;

	if (ac != 2)
		help();
	setbuf(stdout, NULL);
	f = ft_atoi(av[1]);
	if (f > 0 && f < 6)
		setup(f);
	else
		invalid(f);
	return (0);
}

void	switch_fractal(t_env *e, int x, int y)
{
	int	i;

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
	if (i < e->cam->maxit)
		draw_dot(e, x, y,
		hsv_to_rgb(i % 256, 255, 255));
	else
		draw_dot(e, x, y, 0);
}
