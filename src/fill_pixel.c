/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:56:13 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/07 22:13:31 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Put a pixel in the MLX image
**	Params:	struct t_env
**			x position of the pixel
**			y position of the pixel
**			color of the pixel
*/
void	fill_pixel(t_env *env, int x, int y, int color)
{
	int		pos;

	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		pos = y * WIN_WIDTH + x;
		env->img.data[pos] = color;
	}
}
