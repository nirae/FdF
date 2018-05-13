/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:51:03 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/13 22:51:53 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(t_env *env)
{
	int		i;
	int		ii;

	create_img(env);
	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			if (i != env->height - 1)
				fill_segment(env, env->curr_tab[i][ii],
								env->curr_tab[i + 1][ii]);
			if (ii != env->width - 1)
				fill_segment(env, env->curr_tab[i][ii],
								env->curr_tab[i][ii + 1]);
		}
	}
}
