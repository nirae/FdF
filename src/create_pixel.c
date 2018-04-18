/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:00:55 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/18 17:01:05 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel		create_pixel(int x, int y, int z, int color)
{
	t_pixel		pixel;

	//if (!(pixel = (t_pixel *)ft_memalloc(sizeof(t_pixel))))
	//	return (NULL);
	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	pixel.color = color;

	return (pixel);
}
