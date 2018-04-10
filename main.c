/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:27:19 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/10 16:32:39 by ndubouil         ###   ########.fr       */
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
	int				size_x;
	int				size_y;
}					t_env;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	carre(int x, int y, int size_x, int size_y, t_env *env)
{
	int a;
	int b;

	a = x;
	b = y;
	while (a < (x + size_x))
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, a, b, WHITE);
		a++;
		if (a == (x + size_x) && b < (y + size_y))
		{
			b++;
			a = x;
		}
	}
}

int		agrandir_carre(int key, t_env *env)
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
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	carre(env->curr_x, env->curr_y, env->size_x, env->size_y, env);
	return (0);
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
	int tmp;

	if (x1 > x2)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
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

#define X1 100
#define Y1 350

#define X2 300
#define Y2 350

int		main(void)
{
	t_env	env;
	
	env.curr_x = 200;
	env.curr_y = 200;
	env.size_x = 50;
	env.size_y = 50;
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, 500, 500, "Ma fenetre de ouf");
	//mlx_pixel_put(env.mlx_ptr, env.win_ptr, env.curr_x, env.curr_y, WHITE);
	//mlx_key_hook(env.win_ptr, deal_key, &env);
	mlx_hook(env.win_ptr, 2, (1L<<0), deal_key, &env);
	//carre(env.curr_x, env.curr_y, env.size_x, env.size_y, &env);
	//mlx_hook(env.win_ptr, 2, (1L<<0), agrandir_carre, &env);
	mlx_hook(env.win_ptr, 4, (1L<<2), gere_mouse, &env);

	//mlx_pixel_put(env.mlx_ptr, env.win_ptr, 250, 250, WHITE);
	segment(X1, Y1, X2, Y2, &env);
	mlx_string_put(env.mlx_ptr, env.win_ptr, X1, Y1, WHITE, "1");
	mlx_string_put(env.mlx_ptr, env.win_ptr, X2, Y2, WHITE, "2");
	mlx_loop(env.mlx_ptr);
	return (0);
}
