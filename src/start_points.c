/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:10:26 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/24 09:00:21 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_start(t_env *env, int *xy)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->curr_tab[i][ii] = create_pixel(
					env->curr_tab[i][ii].x + curr_start[0],
					env->curr_tab[i][ii].y + curr_start[1],
					env->curr_tab[i][ii].z,
					env->curr_tab[i][ii].color
					);
		}
	}
}

static void		*set_or_center(t_env *env)
{
	int		xmid;
	int		ymid;

	xmid = env->curr_tab[env->height / 2][env->width / 2].x;
	ymid = env->curr_tab[env->height / 2][env->width / 2].y;

	env->or_start[0] = (WIDTH / 2) - xmid;
	env->or_start[1] = (HEIGHT / 2) - ymid;
}

void		move_start(t_env *env, int x, int y)
{
	int		xy[];

	env->curr_start[0] = x;
	env->curr_start[1] = y;
	set_start(env, xy);
}

void		set_default_start(t_env *env)
{
	int		i;
	int		ii;
	
	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->curr_tab[i][ii] = create_pixel(
					env->curr_tab[i][ii].x + env->or_start[0],
					env->curr_tab[i][ii].y + env->or_start[1],
					env->curr_tab[i][ii].z,
					env->curr_tab[i][ii].color
					);
		}
	}
}
