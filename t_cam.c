/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cam.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 01:15:42 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/13 23:30:09 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cam *cam(void)
{
	t_cam *camera;

	camera = (t_cam*)malloc(sizeof(t_cam));
	camera->zoom = 1;
	camera->moveX = 0;
	camera->moveY = 0;
	camera->maxIterations = 100;
	camera->mouseX = 0;
	camera->mouseY = 0;
	return (camera);
}
