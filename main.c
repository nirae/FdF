/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:27:19 by ndubouil          #+#    #+#             */
/*   Updated: 2018/04/18 23:56:11 by ndubouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	carre(int x, int y, int size_x, int size_y, t_env *env)
{
	int a;
	int b;

	a = x;
	b = y;
	while (a < (x + size_x))
	{
		fill_pixel(&env->img, a, b, WHITE);
		a++;
		if (a == (x + size_x) && b < (y + size_y))
		{
			b++;
			a = x;
		}
	}
}
/*
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
*/
/*int		deal_key(int key, t_env *env)
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
}*/
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

#define X1 100
#define Y1 800

#define X2 400
#define Y2 100

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

#define COEFF 1
#define XY 20

int			get_start_x(int xmid)
{
	int result;
	//int xmax;

	//xmax = (width - 1) * coeff;
	result = (WIDTH / 2) - xmid;
	return (result);
}

int			get_start_y(int ymid)
{
	int result;
	//int ymax;

	//ymax = (height - 1) * coeff;
	result = (HEIGHT / 2) - ymid;
	return (result);
}

/*int			get_default_coeff(int xmax, int ymax)
{
	int		y_coeff;
	int		x_coeff;

	x_coeff = 0;
	y_coeff = 0;
	while (xmax * x_coeff <= WIDTH - (MARGIN * 2))
		x_coeff++;
	while (ymax * y_coeff <= HEIGHT - (MARGIN * 2))
		y_coeff++;
	if (x_coeff < y_coeff)
		return (x_coeff);
	else 
		return (y_coeff);
}*/


t_pixel		**parser2(int height, int width, char *file)
{
	int		i;
	int		ii;
	char	*line;
	int		fd;
	char	**tab;
	t_pixel	**result;

	line = NULL;
	/*** Calcul du coefficient de zoom de base
	
	
	//int xmax = (width - 1) - (height - 1);
	//int ymax = ((width - 1) + (height - 1)) / 2;

	int xmax = (CTE1 * (width - 1) - CTE2 * (height - 1));
	int ymax = (((CTE1 / 2 + CTE1 % 2) * (width - 1)) + ((CTE2 / 2 + CTE2 % 2) * (height - 1)));

	int coeff = get_default_coeff(xmax, ymax);
	*/
	/*
	**
	*/

	result = make_array(height, width);
	if ((fd = open(file, O_RDONLY)) < 0)
			return (0); // Erreur d'ouverture du fichier
	i = -1;
	/*
	** Calcul en avance des points du centre pour calculer les points de depart
	*/
	/*
	//int xmid = ((width / 2) * coeff) - ((height / 2) * coeff);
	//int ymid = (((width / 2) * coeff) + ((height / 2) * coeff)) / 2;
	
	int xmid = (CTE1 * (width / 2) - CTE2 * (height / 2));
	int ymid = (((CTE1 / 2 + CTE1 % 2) * (width / 2)) + ((CTE2 / 2 + CTE2 % 2) * (height / 2)));
	*/
	/*
	**
	*/
	while (++i < height)
	{
		get_next_line(fd, &line);
		ft_putendl(line);
		if (ft_count_words(line, ' ') != width)
			break; // Erreur a gerer
		tab = ft_strsplit(line, ' ');
		ii = -1;
		while (++ii < width)
		{
			result[i][ii].x = ii;
			result[i][ii].y = i;
			//result[i][ii].x = (ii * coeff) + get_start_x(width, coeff);
			//int xx = (ii * coeff);
			//result[i][ii].y = (i * coeff) + get_start_y(height, coeff);
			//int yy = (i * coeff);
			result[i][ii].z = ft_atoi(tab[ii]);
			//int zz = ft_atoi(tab[ii]);
			//result[i][ii].x = (CTE1 * xx - CTE2 * yy) + get_start_x(xmid);;
			//result[i][ii].x = (xx - yy) + get_start_x(xmid);
			//result[i][ii].y = (-zz + ((CTE1 / 2 + CTE1 % 2) * xx) + ((CTE2 / 2 + CTE2 % 2) * yy)) + get_start_y(ymid);
			//result[i][ii].y = ((xx + yy) / 2) + get_start_x(ymid);
			result[i][ii].color = result[i][ii].z;
			printf("x : %d, y : %d, z : %d, color : %x\n", result[i][ii].x, result[i][ii].y, result[i][ii].z, result[i][ii].color);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (result);
}

/*
int		***parser_iso(int height, int width, char *file)
{
	int		i;
	int		y;
	char	*line;
	int		fd;
	char	**tab;
	int		***result;

	line = NULL;
	result = make_array(height, width);
	if ((fd = open(file, O_RDONLY)) < 0)
			return (0); // Erreur d'ouverture du fichier
	i = 0;
	while (i < height)
	{
		get_next_line(fd, &line);
		if (ft_count_words(line, ' ') != width)
			break; // Erreur a gerer
		tab = ft_strsplit(line, ' ');
		y = -1;
		while (++y < width)
		{
			//printf("TOUR NUMERO : %d\n", i);
			// Remplissage du X
			int xx = (y * (XY * COEFF)) + DEPARTX;
			int yy = (i * (XY * COEFF)) + DEPARTY;
			int zz = ft_atoi(tab[y]);
			printf("xx : %d, yy : %d, zz : %d\n", xx, yy, zz);
			result[i][y][2] = zz;
			result[i][y][0] = (CTE1 * xx - CTE2 * yy);
			//result[i][y][0] = xx - yy;
			result[i][y][1] = (-zz + ((CTE1 / 2 + CTE1 % 2) * xx) + ((CTE2 / 2 + CTE2 % 2) * yy));
			//result[i][y][1] = (xx + yy) / 2;
			printf("x : %d, y : %d, z : %d\n", result[i][y][0], result[i][y][1], result[i][y][2]);
		}	
		//ft_strclr(line);
		i++;
	}
	close(fd);
	return (result);
}*/
void		add_start_points(t_env *env);

void		set_coor_center(t_env *env)
{
	int xmid;
	int ymid;
	
	xmid = env->tab[env->height / 2][env->width / 2].x;
	ymid = env->tab[env->height / 2][env->width / 2].y;

	env->start_x = (WIDTH / 2) - xmid;
	env->start_y = (HEIGHT / 2) - ymid;
	add_start_points(env);
}

void		add_start_points(t_env *env)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->tab[i][ii] = create_pixel(
								env->tab[i][ii].x + env->start_x,
								env->tab[i][ii].y + env->start_y,
								env->tab[i][ii].z,
								env->tab[i][ii].color
								);
		}
	}

}

/*
int			get_start_y(int ymid)
{
	int result;
	//int ymax;

	//ymax = (height - 1) * coeff;
	result = (HEIGHT / 2) - ymid;
	return (result);
}
*/
void		add_zoom(t_env *env);

void		set_default_zoom(t_env *env)
{
	int		y_coeff;
	int		x_coeff;
	int		xmax;
	int		ymax;
	
	xmax = env->tab[env->height - 1][env->width - 1].x;
	ymax = env->tab[env->height - 1][env->width - 1].y;

	x_coeff = 0;
	y_coeff = 0;
	while (xmax * x_coeff <= HEIGHT - (MARGIN * 2))
		x_coeff++;
	while (ymax * y_coeff <= HEIGHT - (MARGIN * 2))
		y_coeff++;
	if (x_coeff < y_coeff)
		env->zoom = x_coeff;
	else 
		env->zoom = y_coeff;
	add_zoom(env);
}

void		set_zoom(t_env *env, int zoom)
{
	env->zoom = zoom;
	add_zoom(env);
}

void		add_zoom(t_env *env)
{
	int		i;
	int		ii;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			env->tab[i][ii] = create_pixel(
								env->tab[i][ii].x * env->zoom,
								env->tab[i][ii].y * env->zoom,
								env->tab[i][ii].z,
								env->tab[i][ii].color
								);
		}
	}
}

#define CTE1 1
#define CTE2 2

void		iso(t_env *env)
{
	int		i;
	int		ii;
	int		x;
	int		y;
	int		z;

	i = -1;
	while (++i < env->height)
	{
		ii = -1;
		while (++ii < env->width)
		{
			x = env->tab[i][ii].x;
			y = env->tab[i][ii].y;
			z = env->tab[i][ii].z * CTE2;
			env->tab[i][ii] =
			create_pixel(
							(CTE1 * x - CTE2 * y),
							(-z + ((CTE1 / 2 + CTE1 % 2) * x) + ((CTE2 / 2 + CTE2 % 2) * y)),
							env->tab[i][ii].z,
							env->tab[i][ii].color
						);
		}
	}
}


int		main(int argc, char **argv)
{
	//int		height;
	//int		width;
	t_env	env;
	int i;
	int ii;

	if (argc == 2)
	{
		env.height = get_height(argv[1]);
		env.width = get_width(argv[1]);
		//printf("height : %d\n", height);
		//printf("width : %d\n", width);
		// malloc a proteger
		env.tab = parser(env.height, env.width, argv[1]);
		set_default_zoom(&env);
		iso(&env);
		set_coor_center(&env);
		//add_zoom(&env);
		//env.tab[10][18][0] = 666;
		//printf("contenu de tab[%d][%d][0] : %d\n", 10, 18, env.tab[11][18].x);
		env.mlx_ptr = mlx_init();
		env.win_ptr = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT, "Ma fenetre de ouf");
		env.img.img_ptr = mlx_new_image(env.mlx_ptr, WIDTH, HEIGHT);
		env.img.data = (int *)mlx_get_data_addr(env.img.img_ptr, &env.img.bpp, 
				&env.img.size_l, &env.img.endian);
		//fill_pixel(&env.img, 400, 200, WHITE);
		//fill_segment(first, second, &env.img);
		i = -1;
		while (++i < env.height)
		{
			ii = -1;
			while (++ii < env.width)
			{
				if (i != env.height - 1)
					fill_segment(&env.img, env.tab[i][ii], env.tab[i + 1][ii]);
				if (ii != env.width - 1)
					fill_segment(&env.img, env.tab[i][ii], env.tab[i][ii + 1]);
				//fill_pixel(&env.img, env.tab[i][ii].x, env.tab[i][ii].y, WHITE);
			}
		}
		mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
		mlx_string_put(env.mlx_ptr, env.win_ptr, 10, 10, WHITE, "coucou");
		mlx_loop(env.mlx_ptr);
	}
	return (0); // Sortie du main
}
