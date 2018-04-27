/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_to_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:06:38 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/27 15:07:14 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reset_to_or(t_env *env)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->curr_tab[i][ii].x = env->or_tab[i][ii].x;
			env->curr_tab[i][ii].y = env->or_tab[i][ii].y;
			env->curr_tab[i][ii].z = env->or_tab[i][ii].z;
			env->curr_tab[i][ii].color = env->or_tab[i][ii].color;
		}
	}
}
