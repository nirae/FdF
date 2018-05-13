/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:27:19 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/14 00:04:47 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
**	MAIN FUNCTION
**
**	If the argument is "help" or different to 1, print the usage
*/

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "help") == 0)
			usage();
		ft_putendl("Welcome to the FdF!");
		env.img.img_ptr = NULL;
		env.height = get_height(argv[1]);
		env.width = get_width(argv[1]);
		env.or_tab = parser(argv[1], &env);
		set_color(&env);
		env.curr_tab = make_array(env.height, env.width);
		set_or_to_curr(&env);
		set_default_start(&env);
		change_proj(&env, PARA);
		env.mlx_ptr = mlx_init();
		env.win_ptr = mlx_new_window(env.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
		put_to_window(&env);
		mlx_hook(env.win_ptr, KEYPRESS, KEYPRESSMASK, deal_key, &env);
		mlx_loop(env.mlx_ptr);
	}
	else
		usage();
	return (0);
}
