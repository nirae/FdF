/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 08:10:26 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/15 12:48:14 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Reset the starts points in the current tab
*/

static void		reset_start(t_env *env)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->curr_tab[i][ii].x = env->curr_tab[i][ii].x -
				env->curr_start[0];
			env->curr_tab[i][ii].y = env->curr_tab[i][ii].y -
				env->curr_start[1];
		}
	}
}

/*
** Move the starts points of the current tab
*/

void			move_start(t_env *env, int x, int y)
{
	reset_start(env);
	env->curr_start[0] = env->curr_start[0] + x;
	env->curr_start[1] = env->curr_start[1] + y;
	add_start(env);
}

/*
**	Set the default start (center)
*/

void			set_default_start(t_env *env)
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
					env->curr_tab[i][ii].color);
		}
	}
}

/*
**	Add the current tab starts points to the current tab
*/

void			add_start(t_env *env)
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
					env->curr_tab[i][ii].color);
		}
	}
}
