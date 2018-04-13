/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 08:46:11 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/13 08:48:30 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	horizontal(int *first, int *second, t_img *img, int color)
{
	int x;
	int y;
	int tmp;

	if (first[0] > second[0])
	{
		tmp = first[0];
		first[0] = second[0];
		second[0] = tmp;
		tmp = first[1];
		first[1] = second[1];
		second[1] = tmp;
	}
	x = first[0];
	while (x <= second[0])
	{
		y = first[1] + ((second[1] - first[1]) * (x - first[0])) / (second[0] - first[0]);
		fill_pixel(img, x, y, color);
		x++;
	}
}

void	vertical(int *first, int *second, t_img *img, int color)
{
	int x;
	int y;
	int tmp;

	if (first[1] > second[1])
	{
		tmp = first[0];
		first[0] = second[0];
		second[0] = tmp;
		tmp = first[1];
		first[1] = second[1];
		second[1] = tmp;
	}
	y = first[1];
	while (y <= second[1])
	{
		x = first[0] + ((second[0] - first[0]) * (y - first[1])) / (second[1] - first[1]);
		printf("x : %d, y : %d\n", x, y);
		fill_pixel(img, x, y, color);
		y++;
	}
}

/*
 * **	tab[0] = x
 * **	tab[1] = y
 * **	tab[2] = color
 * */
void	fill_segment(t_img *img, int *first, int *second)
{
	if ((second[0] - first[0]) >= abs(second[1] - first[1]))
		horizontal(first, second, img, WHITE);
	else
		vertical(first, second, img, WHITE);
}
