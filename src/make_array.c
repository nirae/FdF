/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:08:14 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/18 14:45:21 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Params : height, width
**	Return : 2 dimensional array of t_pixel structure or NULL if malloc failed
**	Example of an array that will be returned :
** 		height (Y) : 3
**		width (X) : 4
**														 		X
**			0 ____________________________________________________
**			| {x, y, z} | {x, y, z} | {x, y, z} | {x, y, z} | NULL
**			| ----------------------------------------------------
**			| {x, y, z} | {x, y, z} | {x, y, z} | {x, y, z} | NULL
**			| ----------------------------------------------------
**		 Y	| {x, y, z} | {x, y, z} | {x, y, z} | {x, y, z} | NULL
**			| ----------------------------------------------------
**			|	NULL	|	NULL	|	NULL	|	NULL	|
*/
t_pixel		**make_array(int height, int width)
{
	int		i;
	int 	ii;
	t_pixel		**tab;

	tab = NULL;
	if (!(tab = (t_pixel **)ft_memalloc((height + 1) * sizeof(t_pixel *))))
		return (NULL);
	i = -1;
	while (++i < height + 1)
	{
		if (!(tab[i] = (t_pixel *)ft_memalloc((width + 1) * sizeof(t_pixel))))
			return (NULL);
		ii = -1;
		while (++ii < width + 1)
		{
			tab[i][ii].x = 0;
			tab[i][ii].y = 0;
			tab[i][ii].z = 0;
			tab[i][ii].color = 0;
		}
	}
	return (tab);
}
