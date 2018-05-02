/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:24:58 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/02 13:42:51 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		apply_proj(t_env *env, int proj)
{
	env->proj = proj;
	if (proj == ISO)
		isometry(env);
	else if (proj == PARA)
		parallel(env);
	else if (proj != BASIC)
	{
		env->proj = BASIC;
		reset_to_or(env);
		set_default_zoom(env);
		set_default_start(env);
	}
}

void		change_proj(t_env *env, int proj)
{
	reset_to_or(env);
	set_default_zoom(env);
	apply_proj(env, proj);
	set_default_start(env);
}

void		isometry(t_env *env)
{
	int		i;
	int		ii;
	int		x;
	int		y;
	int		z;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			x = env->curr_tab[i][ii].x;
			y = env->curr_tab[i][ii].y;
			z = env->curr_tab[i][ii].z;
			env->curr_tab[i][ii] =
			create_pixel(
							(CTE1 * x - CTE2 * y),
							(-z + ((CTE1 / 2 + CTE1 % 2) * x) + ((CTE2 / 2 + CTE2 % 2) * y)),
							env->curr_tab[i][ii].z,
							env->curr_tab[i][ii].color
						);
		}
	}
}

void		parallel(t_env *env)
{
	int		i;
	int		ii;
	int		x;
	int		y;
	int		z;

	env->curr_tab = env->or_tab;
	set_default_zoom(env);
	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			x = env->curr_tab[i][ii].x;
			y = env->curr_tab[i][ii].y;
			z = env->curr_tab[i][ii].z / 2;
			env->curr_tab[i][ii] =
			create_pixel(
							(x + (CTE1 * z)),
							(y + ((CTE1 / 2 + CTE1 % 2) * -z)),
							env->curr_tab[i][ii].z,
							env->curr_tab[i][ii].color
						);
		}
	}
}
