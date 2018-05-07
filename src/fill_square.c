/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:53:14 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/07 22:16:08 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Put a square in the MLX image
**	Params:	t_pixel pixel represent the first point on the top of left
**			width of the square
**			height of the square
**			t_env structure
**
**	The color of the square is the color of the start pixel
*/

void		fill_square(t_pixel start, int width, int height, t_env *env)
{
	int		x;
	int		y;

	x = start.x;
	y = start.y;
	while (x < (start.x + width))
	{
		fill_pixel(env, x, y, start.color);
		x++;
		if (x == (start.x + width) && y < (start.y + height))
		{
			y++;
			x = start.x;
		}
	}
}
