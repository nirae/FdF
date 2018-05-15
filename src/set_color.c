/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:11:23 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/15 12:52:59 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Get the color if Z is > to 0
** FUCK THE NORM
*/

static int		color_positive(int z, int coeff)
{
	if (z > 4 * coeff)
		return (0xF5F4F2);
	else if (z > 11 * (coeff / 3))
		return (0xCAC3B8);
	else if (z > 3 * coeff)
		return (0xBAAE9A);
	else if (z > 21 * (coeff / 8))
		return (0xAC9A7C);
	else if (z > 2 * coeff)
		return (0xAA8753);
	else if (z > 3 * (coeff / 2))
		return (0xC3A76B);
	else if (z > 1 * coeff)
		return (0xD3CA9D);
	else if (z > 3 * (coeff / 4))
		return (0xE8E1B6);
	else if (z > 1 * (coeff / 2))
		return (0xD1D7AB);
	else if (z > 1 * (coeff / 4))
		return (0xBDCC96);
	else if (z > 1 * (coeff / 8))
		return (0x94BF8B);
	return (0xACD0A5);
}

/*
** Get the color if Z is < to 0
** FUCK THE NORM
*/

static int		color_negative(int z, int coeff)
{
	if (z > -1 * (coeff / 8))
		return (0xD8F2FE);
	else if (z > -1 * (coeff / 4))
		return (0xC6ECFF);
	else if (z > -1 * (coeff / 2))
		return (0xACDBFB);
	else if (z > -1 * coeff)
		return (0xA1D2F7);
	else if (z > -3 * (coeff / 2))
		return (0x96C9F0);
	else if (z > -2 * coeff)
		return (0x8DC1EA);
	else if (z > -21 * (coeff / 8))
		return (0x84B9E3);
	else if (z > -11 * (coeff / 3))
		return (0x79B2DE);
	return (0x71ABD8);
}

/*
** Dispatcher
** FUCK THE NORM
*/

static int		color(int z, int coeff)
{
	if (z > 0)
		return (color_positive(z, coeff));
	return (color_negative(z, coeff));
}

/*
** Set the color for each point
** The colors are from https://fr.wikipedia.org/wiki/Aide:Cartographie
** Calculating based on https://s2.qwant.com/thumbr/0x0/e/6/5ed58dfe3535b0ef
**	ef4b4328ea551113ad3092e7f4ffda090e2ff340cc1343/carte-relief-lambert-gran
**	des-villes-Le%20Plessis-l'Echelle.jpg?u=http%3A%2F%2Fwww.cartesfrance.fr
**	%2Fcarte-commune%2F41%2F41178%2Fcarte-relief-lambert-grandes-villes-Le%2
**	520Plessis-l%27Echelle.jpg&q=0&b=1&p=0&a=1
*/

void			set_color(t_env *env)
{
	int		coeff;
	int		i;
	int		ii;

	coeff = env->z_max / 10;
	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->or_tab[i][ii] = create_pixel(
									env->or_tab[i][ii].x,
									env->or_tab[i][ii].y,
									env->or_tab[i][ii].z,
									color(env->or_tab[i][ii].z, coeff));
		}
	}
}
