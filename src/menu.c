/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:27:44 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/15 11:22:25 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Put in the MLX image the menus bars and borders
** Top bar, top bar border, down bart, down bar border
*/

void			fill_menu_bars(t_env *env)
{
	t_pixel start;

	start = create_pixel(0, 0, 0, T_M_COLOR);
	fill_square(start, T_M_WIDTH, T_M_HEIGHT, env);
	start = create_pixel(0, (T_M_HEIGHT - B_HEIGHT), 0, B_COLOR);
	fill_square(start, T_M_WIDTH, B_HEIGHT, env);
	start = create_pixel(0, (WIN_HEIGHT - D_M_HEIGHT), 0, D_M_COLOR);
	fill_square(start, D_M_WIDTH, D_M_HEIGHT, env);
	start = create_pixel(0, (WIN_HEIGHT - D_M_HEIGHT), 0, B_COLOR);
	fill_square(start, D_M_WIDTH, B_HEIGHT, env);
}

/*
**	FUCK THE NORM
*/

static void		top(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, COL1, 0, TEXT_COLOR,
							"KEYBINDS :");
	if (env->proj == ISO)
		mlx_string_put(env->mlx_ptr, env->win_ptr, COL1, ROW1, TEXT_ACTIVE,
							"I : Isometry");
	else
		mlx_string_put(env->mlx_ptr, env->win_ptr, COL1, ROW1, TEXT_COLOR,
							"I : Isometry");
	if (env->proj == BASIC)
		mlx_string_put(env->mlx_ptr, env->win_ptr, COL1, ROW2, TEXT_ACTIVE,
							"B : Basic");
	else
		mlx_string_put(env->mlx_ptr, env->win_ptr, COL1, ROW2, TEXT_COLOR,
							"B : Basic");
	if (env->proj == PARA)
		mlx_string_put(env->mlx_ptr, env->win_ptr, COL1, ROW3, TEXT_ACTIVE,
							"P : Parallel");
	else
		mlx_string_put(env->mlx_ptr, env->win_ptr, COL1, ROW3, TEXT_COLOR,
							"P : Parallel");
	mlx_string_put(env->mlx_ptr, env->win_ptr, COL2, ROW1, TEXT_COLOR,
							"Zoom : + / -");
	mlx_string_put(env->mlx_ptr, env->win_ptr, COL3, ROW1, TEXT_COLOR,
							"Move : UP / DOWN / LEFT / RIGHT");
}

/*
**	Print the instructions in the menu
*/

void			print_keybinds(t_env *env)
{
	top(env);
	mlx_string_put(env->mlx_ptr, env->win_ptr, D_COL2, D_CENTER, TEXT_COLOR,
							"Made with <3 for Theo");
}
