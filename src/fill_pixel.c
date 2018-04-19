/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:56:13 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/19 18:18:17 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(t_env *env, int x, int y, int color)
{
	int pos;

	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		pos = y * WIDTH + x;
		env->img.data[pos] = color;
	}
}
