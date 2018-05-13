/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:16:39 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/13 23:23:55 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Free the env and quit the program
*/

void		quit_fdf(t_env *env)
{
	free_env(env);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	ft_putendl("Goodbye!");
	exit(0);
}
