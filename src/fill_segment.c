/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 08:46:11 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/19 18:18:10 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	horizontal(t_pixel first, t_pixel second, t_img *img)
{
	int x;
	int y;
	int tmp;

	if (first.x > second.x)
	{
		tmp = first.x;
		first.x = second.x;
		second.x = tmp;
		tmp = first.y;
		first.y = second.y;
		second.y = tmp;
	}
	x = first.x;
	while (x <= second.x)
	{
		y = first.y + ((second.y - first.y) * (x - first.x)) / (second.x - first.x);
		if (first.z > 0 && second.z > 0)
			fill_pixel(img, x, y, 0x8DB600);
		else
			fill_pixel(img, x, y, WHITE);
		x++;
	}
}

void	vertical(t_pixel first, t_pixel second, t_img *img)
{
	int x;
	int y;
	int tmp;

	if (first.y > second.y)
	{
		tmp = first.x;
		first.x = second.x;
		second.x = tmp;
		tmp = first.y;
		first.y = second.y;
		second.y = tmp;
	}
	y = first.y;
	while (y <= second.y)
	{
		x = first.x + ((second.x - first.x) * (y - first.y)) / (second.y - first.y);
		printf("x : %d, y : %d\n", x, y);
		if (first.z > 0 && second.z > 0)
			fill_pixel(img, x, y, 0x8DB600);
		else
			fill_pixel(img, x, y, WHITE);
		y++;
	}
}

void	fill_segment(t_img *img, t_pixel first, t_pixel second)
{
	if ((second.x - first.x) >= abs(second.y - first.y))
		horizontal(first, second, img);
	else
		vertical(first, second, img);
}*/

void	horizontal(t_env *env, t_seg seg)
{
	int i;

	seg.cumul = seg.dx / 2 ;
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
		fill_pixel(env, seg.x, seg.y, WHITE);
	}
}

void	vertical(t_env *env, t_seg seg)
{
	int i;
	
	seg.cumul = seg.dy / 2;
	i = 0;
	while(++i <= seg.dy)
	{
		seg.y += seg.yinc;
		seg.cumul += seg.dx;
		if (seg.cumul >= seg.dy)
		{
			seg.cumul -= seg.dy;
			seg.x += seg.xinc;
		}
		fill_pixel(env, seg.x, seg.y, WHITE);
	}
}

void	fill_segment(t_env *env, t_pixel first, t_pixel second)
{
	t_seg	seg;
	
	seg.x = first.x;
	seg.y = first.y;
	seg.dx = second.x - first.x;
	seg.dy = second.y - first.y;
	seg.xinc = ( seg.dx > 0 ) ? 1 : -1;
	seg.yinc = ( seg.dy > 0 ) ? 1 : -1;
	seg.dx = abs(seg.dx);
	seg.dy = abs(seg.dy);
	fill_pixel(env, seg.x, seg.y, WHITE);
	if ( seg.dx > seg.dy ) 
		horizontal(env, seg);
	else
		vertical(env, seg);
}
