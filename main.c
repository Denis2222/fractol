/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:07:32 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/12 01:00:07 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	int	intrgb;
	intrgb = hsv_to_rgb(359, 100, 100);

	//intrgb = rgb_to_int(150, 50, 50);

	printf("R:%d G:%d B:%d", intrgb / 256 / 256 % 256, intrgb / 256 % 256, intrgb % 256);

	printf("int rgb :%d,  another test in wind:%d", intrgb, 100 >> 8);
	setup(1);
	return (0);
}
