/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:10:26 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/07 20:39:22 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reset_start(t_env *env)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->curr_tab[i][ii].x = env->curr_tab[i][ii].x - env->curr_start[0];
			env->curr_tab[i][ii].y = env->curr_tab[i][ii].y - env->curr_start[1];
		}
	}
}

void		add_start(t_env *env)
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
					env->curr_tab[i][ii].x + env->curr_start[0],
					env->curr_tab[i][ii].y + env->curr_start[1],
					env->curr_tab[i][ii].z,
					env->curr_tab[i][ii].color
					);
		}
	}
}

void		set_or_center(t_env *env)
{
	int		xmid;
	int		ymid;

	xmid = env->curr_tab[env->height / 2][env->width / 2].x;
	ymid = env->curr_tab[env->height / 2][env->width / 2].y;

	env->or_start[0] = (WIN_WIDTH / 2) - xmid;
	env->or_start[1] = (WIN_HEIGHT / 2) - ymid;
}

void		set_curr_center(t_env *env)
{
	int		xmid;
	int		ymid;

	xmid = env->curr_tab[env->height / 2][env->width / 2].x;
	ymid = env->curr_tab[env->height / 2][env->width / 2].y;

	env->curr_start[0] = (WIN_WIDTH / 2) - xmid;
	env->curr_start[1] = (WIN_HEIGHT / 2) - ymid;
}

void		move_start(t_env *env, int x, int y)
{
	reset_start(env);
	env->curr_start[0] = env->curr_start[0] + x;
	env->curr_start[1] = env->curr_start[1] + y;
	add_start(env);
}

void		set_default_start(t_env *env)
{
	int		i;
	int		ii;

	set_or_center(env);
	set_curr_center(env);
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
