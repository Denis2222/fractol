/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cam.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 01:15:42 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/16 22:41:55 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cam	*cam(void)
{
	t_cam *camera;

	camera = (t_cam*)malloc(sizeof(t_cam));
	camera->z = 1;
	camera->movex = 0;
	camera->movey = 0;
	camera->maxit = 30;
	camera->mousex = 0;
	camera->mousey = 0;
	camera->varx = 0;
	camera->vary = 0;
	camera->anim = 0;
	camera->color = 0;
	return (camera);
}
