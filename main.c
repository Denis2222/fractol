/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:32 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 21:20:11 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(void)
{
	ft_putendl("./fractol <fractal_number>");
	ft_putendl("1 Mandelbrot");
	ft_putendl("2 Julia");
	ft_putendl("3 Mandelbrot (Z^3 + C)");
	ft_putendl("4 Mandelbrot (Z^2 + C^3)");
	ft_putendl("5 Julia (Z^3 + C^3)");
	ft_putendl("6 Pentagon de durer");
	ft_putendl("7 Custom");
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
	if (f > 0 && f < 9)
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
		i = get_iteration_mandelbrot2(e, x, y);
	else if (e->fractale == 4)
		i = get_iteration_mandelbrot3(e, x, y);
	else if (e->fractale == 5)
		i = get_iteration_julia2(e, x, y);
	else if (e->fractale == 6)
		i = get_iteration_julia3(e, x, y);
	else if (e->fractale == 7)
		i = get_iteration_julia4(e, x, y);
	if (i < e->cam->maxit)
		draw_dot(e, x, y,
		hsv_to_rgb(i % 256, 255, 255));
	else
		draw_dot(e, x, y, 0);
}
