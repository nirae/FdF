/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:27:19 by ndubouil          #+#    #+#             */
/*   Updated: 2018/05/08 18:34:01 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
/*
int		gere_mouse(int key, int x, int y, t_env *env)
{
	if (key == 1)
	{
		env->curr_x = x;
		env->curr_y = y;
	}
	else
		return (0);
	printf("x : %d, y : %d\n", x, y);
	mlx_pixel_put(env->mlx_ptr, env->win_ptr, env->curr_x, env->curr_y, WHITE);
	return (0);
}
*/


/* int		main(void)
{
	t_env	env;
	int first[3];
	int second[3];

	printf("nombre : %d\n", ft_count_words("0 0  0  0 0     0 ", ' '));

	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT, "Ma fenetre de ouf");
	//mlx_key_hook(env.win_ptr, deal_key, &env);
	//mlx_hook(env.win_ptr, 2, (1L<<0), deal_key, &env);
	//carre(env.curr_x, env.curr_y, env.size_x, env.size_y, &env);
	//mlx_hook(env.win_ptr, 2, (1L<<0), agrandir_carre, &env);
	//mlx_hook(env.win_ptr, 4, (1L<<2), gere_mouse, &env);

	//segment(X1, Y1, X2, Y2, &env);
	//mlx_string_put(env.mlx_ptr, env.win_ptr, X1, Y1, WHITE, "1");
	//mlx_string_put(env.mlx_ptr, env.win_ptr, X2, Y2, WHITE, "2");
	//mlx_loop(env.mlx_ptr);

	env.img.img_ptr = mlx_new_image(env.mlx_ptr, WIDTH, HEIGHT);
	env.img.data = (unsigned int *)mlx_get_data_addr(env.img.img_ptr, &env.img.bpp, &env.img.size_l, &env.img.endian);

	fill_pixel(&env.img, 200, 200, WHITE);
	//carre(300, 300, 50, 50, &env);
	first[0] = X1;
	first[1] = Y1;
	second[0] = X2;
	second[1] = Y2;
	print_segment(first, second, &env.img);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 10, WHITE, "coucou");
	mlx_loop(env.mlx_ptr);
	return (0);
}*/

void	fill_img(t_env *env);
void	put_to_window(t_env *env);

int		deal_key(int key, t_env *env)
{
	if (key == 53)
		quit_fdf(env);
	else if (key == 126)
		move_start(env, 0, -6);
	else if (key == 125)
		move_start(env, 0, 6);
	else if (key == 123)
		move_start(env, -6, 0);
	else if (key == 124)
		move_start(env, 6, 0);
	else if (key == 24)
		set_zoom(env, env->zoom + 1);
	else if (key == 27)
		set_zoom(env, env->zoom - 1);
	else if (key == 34)
		change_proj(env, ISO);
	else if (key == 35)
		change_proj(env, PARA);
	else if (key == 11)
		change_proj(env, BASIC);
	else
		return (0);
	put_to_window(env);
	return (0);
}

void	create_img(t_env *env)
{
	env->img.img_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img.data = (int *)mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, 
				&env->img.size_l, &env->img.endian);
}

void	fill_img(t_env *env)
{
	int		i;
	int		ii;

	create_img(env);
	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			if (i != env->height - 1)
				fill_segment(env, env->curr_tab[i][ii], env->curr_tab[i + 1][ii]);
			if (ii != env->width - 1)
				fill_segment(env, env->curr_tab[i][ii], env->curr_tab[i][ii + 1]);
			//fill_pixel(&env.img, env.tab[i][ii].x, env.tab[i][ii].y, WHITE);
		}
	}
}

/*void	reset_proj(t_env *env)
{
	env->curr_tab = env->or_tab;
	set_default_zoom;
}*/

void	put_to_window(t_env *env)
{
	fill_img(env);
	fill_menu_bars(env);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	print_keybinds(env);
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc == 2)
	{
		// FAIL A GERER
		env.height = get_height(argv[1]);
		// FAIL A GERER
		env.width = get_width(argv[1]);
		// malloc a proteger
		env.or_tab = parser(env.height, env.width, argv[1], &env);
		set_color(&env);
		env.curr_tab = make_array(env.height, env.width);
		set_or_to_curr(&env);
		/*set_default_zoom(&env);
		isometry(&env);
		//parallel(&env);
		set_default_start(&env);*/
		change_proj(&env, PARA);
		//set_start_points(&env, 10, 10);
		//add_zoom(&env);
		//env.tab[10][18][0] = 666;
		//printf("contenu de tab[%d][%d][0] : %d\n", 10, 18, env.tab[11][18].x);
		env.mlx_ptr = mlx_init();
		env.win_ptr = mlx_new_window(env.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Ma fenetre de ouf");
		//fill_pixel(&env.img, 400, 200, WHITE);
		//fill_segment(first, second, &env.img);
		/*
		fill_img(&env);
		fill_menu_bars(&env);
		mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
		//mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 10, WHITE, "coucou");
		print_menu(&env);*/
		put_to_window(&env);
		mlx_hook(env.win_ptr, 2, (1L<<0), deal_key, &env);
		mlx_loop(env.mlx_ptr);
	}
	return (0); // Sortie du main
}
