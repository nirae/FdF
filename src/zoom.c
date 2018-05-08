/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:08:49 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/08 15:59:26 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


/*
**	Applique le zoom de env
*/
void		add_zoom(t_env *env)
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
								env->curr_tab[i][ii].x * env->zoom,
								env->curr_tab[i][ii].y * env->zoom,
								(env->curr_tab[i][ii].z * env->zoom) / (6 + (env->z_max / 10)),
								env->curr_tab[i][ii].color
								);
		}
	}
	printf("zoom : %d\n", env->zoom);
}

/*
**	Applique le zoom par defaut
*/
void		set_default_zoom(t_env *env)
{
	int		y_coeff;
	int		x_coeff;
	int		xmax;
	int		ymax;

	xmax = env->or_tab[env->height - 1][env->width - 1].x;
	ymax = env->or_tab[env->height - 1][env->width - 1].y;

	x_coeff = 0;
	y_coeff = 0;
	while (xmax * x_coeff <= WS_WIDTH)
		x_coeff++;
	while (ymax * y_coeff <= WS_HEIGHT)
		y_coeff++;
	if (x_coeff < y_coeff)
		env->zoom = x_coeff / 2;
	else
		env->zoom = y_coeff / 2;
	if (env->zoom < 1)
		env->zoom = 1;
	add_zoom(env);
}

/*
**	Enleve le zoom actuellement applique
*/
void		reset_zoom(t_env *env)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->curr_tab[i][ii].x = (env->curr_tab[i][ii].x / env->zoom);
			env->curr_tab[i][ii].y = (env->curr_tab[i][ii].y / env->zoom);
		}
	}

}

/*
** Appliquer un zoom specifique manuellement
*/
void		set_zoom(t_env *env, int zoom)
{
	//reset_zoom(env);
	set_or_to_curr(env);
	env->zoom = zoom;
	add_zoom(env);
	printf("proj  : %d\n", env->proj);
	apply_proj(env, env->proj);
	add_start(env);
}
