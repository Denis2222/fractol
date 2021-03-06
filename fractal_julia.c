/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_iterations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 16:52:03 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 22:27:24 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Z^2 + C
*/

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

int			get_iteration_julia2(t_env *e, int x, int y)
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

int			get_iteration_julia3(t_env *e, int x, int y)
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
		new.r = cos(old.r * old.r - old.i * old.i + c.r);
		new.i = 2 * old.r * old.i + c.i;
		i++;
	}
	return (i);
}

int			get_iteration_julia4(t_env *e, int x, int y)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;
	int			i;

	c.r = -0.7 + e->cam->varx;
	c.i = tan(0.27015 + e->cam->vary);
	new = offsetcomplex(e, x, y);
	old = initcomplex();
	i = 0;
	while (i < e->cam->maxit && (new.r * new.r + new.i * new.i) <= 4)
	{
		old = addcomplex(new, initcomplex());
		new = multcomplex(old, old);
		new = multcomplex(new, new);
		new = multcomplex(new, old);
		new = addcomplex(new, c);
		i++;
	}
	return (i);
}
