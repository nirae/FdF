/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:00:55 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/15 10:55:24 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel		create_pixel(int x, int y, int z, int color)
{
	t_pixel		pixel;

	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	pixel.color = color;
	return (pixel);
}
