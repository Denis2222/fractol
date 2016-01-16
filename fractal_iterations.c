/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_iterations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 16:52:03 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 17:19:21 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Z^2 + C
*/

int			get_iteration_mandelbrot(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	p;
	int			i;

	p = offsetcomplex(e, x, y);
	new = initcomplex();
	new.r += e->cam->varx;
	new.i += e->cam->vary;
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxit && ((new.r * new.r + new.i * new.i) <= 4))
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + p.r;
		new.i = 2 * old.r * old.i + p.i;
		i++;
	}
	return (i);
}

int			get_iteration_julia(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;
	int			i;

	c.r = -0.7 + e->cam->varx;
	c.i = 0.27015 + e->cam->vary;
	new = offsetcomplex(e, x, y);
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxit && (new.r * new.r + new.i * new.i) <= 4)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
		i++;
	}
	return (i);
}

/*
** Z^3 + C
*/

int			get_iteration_custom(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	p;
	int			i;

	p = offsetcomplex(e, x, y);
	new = initcomplex();
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxit && ((new.r * new.r + new.i * new.i) <= 4))
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = multcomplex(old, new);
		new = addcomplex(new, p);
		i++;
	}
	return (i);
}

/*
** Z^2 + C^3
*/

int			get_iteration_custom2(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	p;
	int			i;

	p = offsetcomplex(e, x, y);
	p = multcomplex(p, p);
	p = multcomplex(p, offsetcomplex(e, x, y));
	new = initcomplex();
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxit && ((new.r * new.r + new.i * new.i) <= 4))
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = addcomplex(new, p);
		i++;
	}
	return (i);
}

/*
** custom
*/

int			get_iteration_custom3(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;
	int			i;

	c.r = -0.7 + e->cam->varx;
	c.i = 0.27015 + e->cam->vary;
	new = offsetcomplex(e, x, y);
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxit && (new.r * new.r + new.i * new.i) <= 4)
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = multcomplex(new, old);
		new = addcomplex(new, c);
		i++;
	}
	return (i);
}
