/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:32 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/14 14:55:20 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help()
{
	ft_putendl("\n1 Mandelbrot");
	ft_putendl("2 Julia");
	ft_putendl("3 Pentagone");
	ft_putendl("4 MandelJuliaBrot");
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
