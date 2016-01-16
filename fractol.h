/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 16:51:13 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 19:30:20 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx/mlx.h"
# include <math.h>
# include "libft/libft.h"
# include <complex.h>

# define WIDTH 640
# define HEIGHT 480

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_PADUP 91
# define KEY_PADDOWN 84
# define KEY_PADLEFT 86
# define KEY_PADRIGHT 88
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_PAD0 82
# define KEY_PADDOT 65

# define KEY_CTRL 269
# define KEY_SHIFT 258

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_L 37

# define M_PI5 M_PI / 5

typedef struct	s_cam
{
	double		z;
	double		movex;
	double		movey;
	double		mousex;
	double		mousey;
	double		varx;
	double		vary;
	int			maxit;
	int			anim;
}				t_cam;

t_cam			*cam(void);

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*imgpx;
	int			bpp;
	int			size_line;
	int			endian;
	t_cam		*cam;
	int			fractale;
	int			fd;
}				t_env;

typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

void			setdot(t_dot *dot, int x, int y);
void			draw_dot(t_env *e, int x, int y, int color);
void			draw_line(t_env *e, t_dot *p0, t_dot *p1, int color);
t_dot			*dot(int x, int y);
void			freedot(t_dot *d1, t_dot *d2, t_dot *d3, t_dot *d4);

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

t_complex		initcomplex(void);
t_complex		addcomplex(t_complex d1, t_complex d2);
t_complex		souscomplex(t_complex d1, t_complex d2);
t_complex		multcomplex(t_complex d1, t_complex d2);
t_complex		offsetcomplex(t_env *e, int x, int y);

typedef struct	s_pentagon
{
	double		x;
	double		y;
	double		radius;
	double		angle;
}				t_pentagon;

t_pentagon		newpenta(double x, double y, double radius, double angle);
t_pentagon		pentaform(t_pentagon p, int i);
t_dot			*dotpro(t_pentagon p, t_pentagon p2, double ang3, int j);

void			setup(int n);

int				mouse_hook(int button, int x, int y, t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				keyto(t_env *e, int keycode);
int				mouseto(t_env *e, int button, int x, int y);
int				mouse_motion(int x, int y, t_env *e);

void			draw_img(t_env *e);
void			draw_fractal(t_env *e);
void			switch_fractal(t_env *e, int x, int y);
void			print_fractal_fdf(t_env *e);
void			draw_info(t_env *e);

void			draw_pentagon(t_env *e);

int				get_iteration_mandelbrot(t_env *e, int x, int y);
int				get_iteration_mandelbrot2(t_env *e, int x, int y);
int				get_iteration_mandelbrot3(t_env *e, int x, int y);
int				get_iteration_julia(t_env *e, int x, int y);
int				get_iteration_julia2(t_env *e, int x, int y);

int				rgb_to_int(int r, int g, int b);
int				hsv_to_rgb(unsigned int h, unsigned int s, unsigned int v);

#endif
