/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cam.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 01:15:42 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/12 01:18:34 by dmoureu-         ###   ########.fr       */
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
	return (camera);
}
