/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:27:19 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/09 20:32:31 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define WHITE 0xFFFFFF

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				curr_x;
	int				curr_y;
}					t_env;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		deal_key(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == 126)
		env->curr_y -= 1;
	else if (key == 125)
		env->curr_y += 1;
	else if (key == 123)
		env->curr_x -= 1;
	else if (key == 124)
		env->curr_x += 1;
	else
		return (0);
	mlx_pixel_put(env->mlx_ptr, env->win_ptr, env->curr_x, env->curr_y, WHITE);
	return (0);
}

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

void	segment(int x1, int y1, int x2, int y2, t_env *env)
{
	int x;
	int y;
	//double a;
	//double b;

	//a = (double)((y2 - y1) / (x2 - x1));
	//b = y1 - a * x1;
	x = x1;
	ft_putchar('c');
	while (x <= x2)
	{
		ft_putchar('d');
		y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, WHITE);
		x++;
	}
}

int		main(void)
{
	t_env	env;
	
	env.curr_x = 200;
	env.curr_y = 200;
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, 500, 500, "Ma fenetre de ouf");
	mlx_pixel_put(env.mlx_ptr, env.win_ptr, env.curr_x, env.curr_y, WHITE);
	//mlx_key_hook(env.win_ptr, deal_key, &env);
	//mlx_hook(env.win_ptr, 2, (1L<<0), deal_key, &env);
	//mlx_hook(env.win_ptr, 4, (1L<<2), gere_mouse, &env);

	mlx_pixel_put(env.mlx_ptr, env.win_ptr, 250, 250, WHITE);
	segment(200, 200, 250, 250, &env);
	mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 10, WHITE, "salut");
	mlx_loop(env.mlx_ptr);
	return (0);
}
