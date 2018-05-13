/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:55:54 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/13 23:02:16 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Create a new MLX image and put it in the env struct
**	Destroy the old image if it's not the first time
*/

void	create_img(t_env *env)
{
	if (env->img.img_ptr != NULL)
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img.data = (int *)mlx_get_data_addr(env->img.img_ptr, &env->img.bpp,
				&env->img.size_l, &env->img.endian);
}
