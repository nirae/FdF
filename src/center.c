/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:36:32 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/15 12:54:13 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Set the original tab starts points in the env structure
*/

void		set_or_center(t_env *env)
{
	int		xmid;
	int		ymid;

	xmid = env->curr_tab[env->height / 2][env->width / 2].x;
	ymid = env->curr_tab[env->height / 2][env->width / 2].y;
	env->or_start[0] = (WIN_WIDTH / 2) - xmid;
	env->or_start[1] = (WIN_HEIGHT / 2) - ymid;
}

/*
**	Set the current tab starts points in the env structure
*/

void		set_curr_center(t_env *env)
{
	int		xmid;
	int		ymid;

	xmid = env->curr_tab[env->height / 2][env->width / 2].x;
	ymid = env->curr_tab[env->height / 2][env->width / 2].y;
	env->curr_start[0] = (WIN_WIDTH / 2) - xmid;
	env->curr_start[1] = (WIN_HEIGHT / 2) - ymid;
}
