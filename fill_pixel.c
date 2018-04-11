/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 21:56:13 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/11 22:22:53 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	fill_pixel(t_img *img, int x, int y, int color)
{
	int pos;

	pos = y * WIDTH + x;
	img->data[pos] = color;
}
