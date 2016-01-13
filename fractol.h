/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:34:12 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/13 03:09:39 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"


# define WIN_WIDTH 840
# define WIN_HEIGHT 640

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

typedef struct	s_cam
{
	double		zoom;
	double		moveX;
	double		moveY;
	double		mouseX;
	double		mouseY;
	int			maxIterations;
}				t_cam;

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
}				t_env;

void	setup(int n);

int				mouse_hook(int button, int x, int y, t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);

int				keyto(t_env *e, int keycode);
int				mouseto(t_env *e, int button, int x, int y);

void			draw_dot(t_env *e, int x, int y, int color);
void			draw_fractal(t_env *e);

t_cam	*cam(void);

//color
int	rgb_to_int(int r, int g, int b);
int	hsv_to_rgb(unsigned int h, unsigned int s, unsigned int v);

#endif
