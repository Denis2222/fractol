#include "fractol.h"

t_complex	initcomplex(void)
{
	t_complex	nb;

	nb.r = 0;
	nb.i = 0;
	return (nb);
}

t_complex	addcomplex(t_complex d1, t_complex d2)
{
	t_complex	result;

	result.r = d1.r + d2.r;
	result.i = d1.i + d2.i;
	return (result);
}

t_complex	souscomplex(t_complex d1, t_complex d2)
{
	t_complex	result;

	result.r = d1.r - d2.r;
	result.i = d1.i - d2.i;
	return (result);
}

t_complex	multcomplex(t_complex d1, t_complex d2)
{
	t_complex	result;

	result.r = d1.r * d2.r + ((-1) *  d1.i * d2.i);
	result.i = (d1.r * d2.i) + (d1.i * d2.r);
	return (result);
}
