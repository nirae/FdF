/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 08:46:11 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/15 11:09:08 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Locale functions for manage differents cases and color
*/

static void		horizontal(t_env *env, t_seg seg)
{
	int i;

	seg.cumul = seg.dx / 2;
	i = 0;
	while (++i <= seg.dx)
	{
		seg.x += seg.xinc;
		seg.cumul += seg.dy;
		if (seg.cumul >= seg.dx)
		{
			seg.cumul -= seg.dx;
			seg.y += seg.yinc;
		}
		fill_pixel(env, seg.x, seg.y, seg.color);
	}
}

static void		vertical(t_env *env, t_seg seg)
{
	int i;

	seg.cumul = seg.dy / 2;
	i = 0;
	while (++i <= seg.dy)
	{
		seg.y += seg.yinc;
		seg.cumul += seg.dx;
		if (seg.cumul >= seg.dy)
		{
			seg.cumul -= seg.dy;
			seg.x += seg.xinc;
		}
		fill_pixel(env, seg.x, seg.y, seg.color);
	}
}

static int		calc_color(t_pixel first, t_pixel second)
{
	if (first.z > second.z)
		return (first.color);
	return (second.color);
}

/*
**	Put a segment in the MLX image
**	Params:	struct t_env
**			t_pixel pixel represent the start point
**			t_pixel pixel represent the end point
**
**	The color of the segment is the color of the point with the biggest Z
*/

void			fill_segment(t_env *env, t_pixel first, t_pixel second)
{
	t_seg	seg;

	seg.x = first.x;
	seg.y = first.y;
	seg.dx = second.x - first.x;
	seg.dy = second.y - first.y;
	seg.xinc = (seg.dx > 0) ? 1 : -1;
	seg.yinc = (seg.dy > 0) ? 1 : -1;
	seg.dx = abs(seg.dx);
	seg.dy = abs(seg.dy);
	seg.color = calc_color(first, second);
	fill_pixel(env, seg.x, seg.y, seg.color);
	if (seg.dx > seg.dy)
		horizontal(env, seg);
	else
		vertical(env, seg);
}
