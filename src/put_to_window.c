/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:39:58 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/13 22:42:32 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Fill the image with the map
**	Fill the image with the menu
**	Clear the window
**	Put the image on the window
**	Put the strings keybinds on the window
*/

void	put_to_window(t_env *env)
{
	fill_img(env);
	fill_menu_bars(env);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	print_keybinds(env);
}
