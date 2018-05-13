/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 23:32:07 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/13 23:32:26 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Call when a key is pressed
**	Macros is from mlx_keycode.h
*/

int		deal_key(int key, t_env *env)
{
	if (key == ESC_KEY)
		quit_fdf(env);
	else if (key == UP_KEY)
		move_start(env, 0, -6);
	else if (key == DOWN_KEY)
		move_start(env, 0, 6);
	else if (key == LEFT_KEY)
		move_start(env, -6, 0);
	else if (key == RIGHT_KEY)
		move_start(env, 6, 0);
	else if (key == PL_KEY)
		set_zoom(env, env->zoom + 1);
	else if (key == MN_KEY)
		set_zoom(env, env->zoom - 1);
	else if (key == I_KEY)
		change_proj(env, ISO);
	else if (key == P_KEY)
		change_proj(env, PARA);
	else if (key == B_KEY)
		change_proj(env, BASIC);
	else
		return (0);
	put_to_window(env);
	return (0);
}
